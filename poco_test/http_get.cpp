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

int main(int argc, char **argv) {
	try {
		URI uri("http://bsecure/api/v0/session");
		HTTPClientSession session(uri.getHost(), uri.getPort());
		
		string path(uri.getPathAndQuery());
		path = uri.getPath();
		
		
		
		// USE POST
		// {"email":"x@src.bz","code":"591acbb20a20d8115f7cfd39b218948e"}
		HTTPRequest req(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_1);
		req.setContentLength(2048);
		std::ostream& outStream = session.sendRequest(req);
		string json = "{\"email\":\"x@src.biz\",\"code\":\"591acbb20a20d8115f7cfd39b218948e\"}";
		
		outStream << json;
		cout<<outStream;
		req.write(outStream);
		
		
		// expect 200 response
		HTTPResponse res;
		std::istream& rs = session.receiveResponse(res);
		cout << res.getStatus()<< " " << res.getReason() << " " << endl;
		cout << " Response: " << session.receiveResponse(res) << endl;
		//istream &is = session.receiveResponse(res);
		//StreamCopier::copyStream64(is, cout);
	} catch (Poco::Exception &ex) {
		cerr << ex.displayText() << endl;
		return -1;
	}
	
	return 0;
}
