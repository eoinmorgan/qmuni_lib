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

#define POCO_POST  Poco::Net::HTTPRequest::HTTP_POST
#define POCO_PUT  Poco::Net::HTTPRequest::HTTP_PUT
#define POCO_GET  Poco::Net::HTTPRequest::HTTP_GET
#define POCO_DELETE  Poco::Net::HTTPRequest::HTTP_DELETE
#define POCO_HEAD  Poco::Net::HTTPRequest::HTTP_HEAD
#define POCO_CONNECT  Poco::Net::HTTPRequest::HTTP_CONNECT

using namespace std;

// sudo tcpdump -i lo0 port 80 and dst 127.0.0.1

string Net::http_get(string path, string data, map<string, string> *headers) {
	string result = "";
	result = http_call(POCO_PUT,path, data, *headers);
	return result;
}



string Net::http_delete(string path, map<string, *string> headers) {
	string result = "";
	result = http_call(POCO_PUT,path, *headers);
	return result;
}

string Net::http_post(string path, string data, map<string, string> *headers) {
	string result = "";
	result = http_call(POCO_POST, path, data, *headers);
	return result;
}


string Net::http_put(string path, string data, map<string, string> *headers) {
	string result = "";
	result = http_call(POCO_PUT,path, data, *headers);
	return result;
}



string Net::http_call(string call, string path, string data, map<string, string> *headers){
	string result = "";
	Poco::URI uri(path);
	
	try {
		Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
		Poco::Net::HTTPRequest req(call, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);
 
		//req.set("User-Agent","BSecure Client 1.0");
		//req.setHost("bsecure");
		//pointer *
		if (headers != NULL)
			headers_obj = headers&;
			editHeader(req,headers_obj);

		if (data != NULL) {
			req.setContentLength(data->length());
			ostream& out = session.sendRequest(req);
			out << data&;

		}
		
		// expect 200 response
		Poco::Net::HTTPResponse res;
		istream& rs = session.receiveResponse(res);
		std::istreambuf_iterator<char> eos;
		std::string response_string(std::istreambuf_iterator<char>(rs), eos);
		result = response_string;
 
	}
	catch (Poco::Exception &ex) {
		cerr << ex.displayText() << endl;
	}
	
	return result;
 }

int Net::editHeader(Poco::Net::MessageHeader header, map<string, string> headers ){
	map<string, string>::iterator it;
	for(  it = headers.begin(); it !=headers.end(); it++){
		try {
			cout << it->first;
			header[it->first];
			header.set(it->first, it->second);
			cout << it->first;
		} catch (Poco::NotFoundException e) {
			header.set(it->first,it->second);
		}
	
	}
	header[it->first];
	return 0;
}

