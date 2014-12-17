#include <iostream>
#include <vector>
#include <string>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPCookie.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

//#include "session_handler.h"

#include "qmuni.h"
#include "net.h"

using namespace std;

int main(int argc, char **argv) {
	Poco::URI uri("http://bsecure/api/v0/session");
	string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	cout.flush();
	cout << data << endl;;

	Net *net = new Net();
	cout << net->http_post(uri, data) << endl;

	delete net;
	net = NULL;

	return 0;	
}

