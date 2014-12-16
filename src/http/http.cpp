#include "HTTP.h"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

string net_post( Uri uirInput, string dataInput) {
	String outputString = "";
    if (argc != 2) {
        outputString = "Usage: " + argv[0] + " <url>" + endl;
        outputString = outputString + "			 fetch the <url> resource and output the result" + endl;
        return -1;
    }
    
    try {
		Uri uir = uriInput;
		HTTPClientSession session(uri.getHost(), uri.getPort());
		HTTPRequest req(HTTPRequest::HTTP_POST, uri.getPathAndQuery(), HTTPMessage::HTTP_1_1);
		string data = dataInput;
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
			outputString = "***** FAILED REQUEST" + endl;
			// cout << res.getStatus() << " " << res.getReason() << endl;
			//StreamCopier::copyStream(rs, cout);
			// res.write(cout);
		} else {
			// output cookies if given in response
			vector<HTTPCookie> cookies;
			res.getCookies(cookies);
			
			for (vector<HTTPCookie>::iterator it = cookies.begin(); it != cookies.end(); ++it) {
				outputString = outputString + "Cookie Name: " + it->getName() + endl;
				outputString = outputString + "Cookie Value: " + it->getValue() + endl;
			}
		}

    } catch (Poco::Exception &ex) {
        cerr << ex.displayText() << endl;
        return outputString;
    }
    
    return outputString;
}

