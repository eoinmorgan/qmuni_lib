#include <iostream>
#include <string>
#include <cstdio>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

#include "net.h"

using namespace std;

// sudo tcpdump -i lo0 port 80 and dst 127.0.0.1
string Net::http_post(Poco::URI uri, string data) {
	string result = "";

	try {
		Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
		Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_POST, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);
		//req.set("User-Agent","BSecure Client 1.0");
		//req.setHost("bsecure");
		//req.setContentType("application/json\r\n");
		req.setContentLength(data.length());
		ostream& out = session.sendRequest(req);
		out << data;
		
		// expect 200 response
		Poco::Net::HTTPResponse res;
		istream& rs = session.receiveResponse(res);
		
		if (res.getStatus() != 200) {
			result = "***** FAILED REQUEST";
			// cout << result;
			// cout << res.getStatus() << " " << res.getReason() << endl;
			Poco::StreamCopier::copyStream(rs, cout);
			// res.write(cout);
		} else {
			// output cookies if given in response
			vector<Poco::Net::HTTPCookie> cookies;
			res.getCookies(cookies);
			// printf("%d",cookies.size());
			// cout << "sucess";

			for (vector<Poco::Net::HTTPCookie>::iterator it = cookies.begin(); it != cookies.end(); ++it) {
				result = result + "Cookie Name: " + it->getName();
				result = result + "Cookie Value: " + it->getValue();
				// cout << result;
			}
		}
	} catch (Poco::Exception &ex) {
		cerr << ex.displayText() << endl;
	}

	return result;
}

