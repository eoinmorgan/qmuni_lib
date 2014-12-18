#include <iostream>
#include <vector>
#include <string>

#include <Poco/Exception.h>

#include "qmuni.h"
#include "net.h"
#include "session_handler.h"

using namespace std;

int main(int argc, char **argv) {
	string uri_post = "http://mocksvc.mulesoft.com/mocks/487209f4-65da-4576-acbd-c89231ea860f/book";
		string uri = "http://mocksvc.mulesoft.com/mocks/487209f4-65da-4576-acbd-c89231ea860f/book";
	string data = "{}";//"{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	

	Net *net = new Net();
	cout << "post result: ";
	cout << net->http_post(uri_post, data) << endl;
	cout << "get result: ";
	cout << net->http_get(uri) << endl;
	cout << "put result: ";
	cout << net->http_put(uri_post, data) << endl;
	
	//SessionHandler *session_handler = new SessionHandler();
	//session_handler->login(uri, data);

	delete net;
	net = NULL;
	//delete session_handler;
	//session_handler = NULL;

	return 0;	
}

