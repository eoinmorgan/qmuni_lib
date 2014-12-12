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
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <url>" << endl;
		cout << "			 fetch the <url> resource and output the result" << endl;
		return -1;
	}

	try {
		URI uri(argv[1]);
		HTTPClientSession session(uri.getHost(), uri.getPort());

		string path(uri.getPathAndQuery());
		if (path.empty()) path = "/";

		HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
		session.sendRequest(req);

		HTTPResponse res;
		cout << res.getStatus() << " " << res.getReason() << endl;

		istream &is = session.receiveResponse(res);
		StreamCopier::copyStream64(is, cout);
	} catch (Poco::Exception &ex) {
		cerr << ex.displayText() << endl;
		return -1;
	}

	return 0;
}

