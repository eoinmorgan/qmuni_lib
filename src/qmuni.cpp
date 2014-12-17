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

#include "session_handler.h"

#include "qmuni.h"
//#include "HTTP/HTTP.h"

using namespace Poco::Net;
using namespace Poco;
using namespace std;
using namespace Net;

int main(int argc, char **argv) {
	Session app_session;

	//app_session.login("x@src.com","x");
	//URI uri("http://bsecure/api/v0/session");
	//BNet::HTTP.net_post(uri,"{\"email\":\"x@src.bz\",\"code\":\"1\"}");

	return 0;	
}

