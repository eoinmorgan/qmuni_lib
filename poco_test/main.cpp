#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPCookie.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <iostream>
#include <vector>
#include <string>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

// sudo tcpdump -i lo0 port 80 and dst 127.0.0.1
int main(int argc, char **argv) {
	try {
		URI uri("http://bsecure/api/v0/session");
		HTTPClientSession session(uri.getHost(), uri.getPort());
		HTTPRequest req(HTTPRequest::HTTP_POST, uri.getPathAndQuery(), HTTPMessage::HTTP_1_1);
		string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";
		//req.set("User-Agent","BSecure Client 1.0");
		//req.setHost("bsecure");
		//req.setContentType("application/json\r\n");
		req.setContentLength(data.length());
		ostream& out = session.sendRequest(req);
		out << data;

		// expect 200 response
		HTTPResponse res;
		istream& rs = session.receiveResponse(res);

		if (res.getStatus() != 200) {
			cout << "***** FAILED REQUEST" << endl;
			// cout << res.getStatus() << " " << res.getReason() << endl;
			StreamCopier::copyStream(rs, cout);
			// res.write(cout);
		} else {
			// output cookies if given in response
			vector<HTTPCookie> cookies;
        	res.getCookies(cookies);

			for (vector<HTTPCookie>::iterator it = cookies.begin(); it != cookies.end(); ++it) {
				cout << "Cookie Name: " << it->getName() << endl;
				cout << "Cookie Value: " << it->getValue() << endl;
			}
		}
	} catch (Exception &ex) {
		cerr << ex.displayText() << endl;
		return 1;
	}

	return 0;
}

