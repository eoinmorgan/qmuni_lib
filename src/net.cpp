#include <iostream>
#include <string>
#include <cstdio>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>

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



Net::Net(){
	
	

		
		
}

istream& Net::httpGet(string path, map<string, string> &headers) {
	string empty;
	return httpCall(POCO_GET, path, empty, headers);
}

istream& Net::httpDelete(string path, map<string, string> &headers) {
	string empty;
	return httpCall(POCO_DELETE, path, empty, headers);
}

// TODO assert that data is not empty
istream& Net::httpPost(string path, string &data, map<string, string> &headers) {
	return httpCall(POCO_POST, path, data, headers);
}


// TODO assert that data is not empty
istream& Net::httpPut(string path, string &data, map<string, string> &headers) {
	return httpCall(POCO_PUT, path, data, headers);
}

istream& Net::httpCall(string call, string path, string &data, map<string, string> &headers) {
	string result = "";
	bool hasData = false;
	Poco::URI uri(path);
	streambuf *sb;
	istream& rs(istream &b);

	try {
		Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
		Poco::Net::HTTPRequest req(call, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);
 
		//req.set("User-Agent","BSecure Client 1.0");
		//req.setHost("bsecure");

		// add or replace headers for this request
		addHeadersToRequest(req, headers);

		if (!data.empty()) {
			hasData = true;
		}

		// update length of content if data was given
		if (hasData) {
			req.setContentLength(data.length());
		}

		// send the request to the server
		ostream &out = session.sendRequest(req);

		// send the data to the server in the body of the request
		if (hasData) {
			out << data;
		}

		// collect the response from the server
		Poco::Net::HTTPResponse res;
		 istream &rs = session.receiveResponse(res);

		return &rs;
		// TODO don't do this
		// convert the stream response to a string
		

		
	} catch (Poco::Exception &ex) {
		cerr << ex.displayText() << endl;
	}
	cout << "end of call: " << result << endl;
	return rs;
 }

void Net::addHeadersToRequest(Poco::Net::HTTPRequest &request, map<string, string> &headers) {
	for (map<string, string>::iterator it = headers.begin(); it != headers.end(); ++it) {
		request.set(it->first, it->second);
	}
}
void Net::getCookie(){

}

