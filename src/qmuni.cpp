#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>



#include "qmuni.h"

using namespace std;

string url = PROTOCOL + "://" + SERVER + "/api/v" + VERSION;

// debug the network connection

void debugNet() {
	Net *net = new Net();
	map<string, string> noHeaders;
	map<string, string> jsonHeader;
	string uri = "http://bsecure/api/v0/session";
	string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	cout << "url: " << url << endl;

	jsonHeader.insert(make_pair<string, string>("Content-Type", "application/json"));
	jsonHeader.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	noHeaders.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	
	cout << "post result: ";
	cout << net->httpPost(uri, data, jsonHeader) << endl;
	//cout << "get result: ";
	//cout << net->httpGet(uri, noHeaders) << endl;
	//cout << "put result: ";
	//cout << net->httpPut(uri, data, jsonHeader) << endl;
	//cout << "delete result: ";
	//cout << net->httpDelete(uri, noHeaders) << endl;
	
	
	delete net;
	net = NULL;
	
}

void debugSessionModel(){

	SessionHandler *session_handler = new SessionHandler("http://mocksvc.mulesoft.com/mocks/487209f4-65da-4576-acbd-c89231ea860f/book");
	string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	cout <<  session_handler->login("x@src.bz", "1") << endl;
	
	delete session_handler;
	session_handler = NULL;

}

int main(int argc, char **argv) {
	debugNet();

	return 0;	
}

