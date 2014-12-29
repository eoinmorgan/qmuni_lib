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
	CookieJar m_jar;
}

int Net::httpGet(const string path, map<string, string> *headers, string *responseData)  {
	return httpCall(POCO_GET, path, headers, NULL, responseData);
}

int Net::httpDelete(const string path, map<string, string> *headers, string *responseData)  {
	return httpCall(POCO_DELETE, path, headers, NULL, responseData);
}

// TODO assert that data is not empty
int Net::httpPost(const string path, map<string, string> *headers, const string &requestData, string *responseData)  {
	return httpCall(POCO_POST, path, headers, requestData, responseData);
}

// TODO assert that data is not empty
int Net::httpPut(const string path, map<string, string> *headers, const string &requestData, string *responseData)  {
	return httpCall(POCO_PUT, path, headers, requestData, responseData);
}

int Net::httpCall(const string &call, const string &path, map<string, string> *headers, const string &requestData, string *responseData)  {
	int result = 0;

	try {
		Poco::URI uri(path);
		Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());
		Poco::Net::HTTPRequest req(call, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);
 
		//req.set("User-Agent","BSecure Client 1.0");
		//req.setHost("bsecure");

		// add or replace headers for this request
		addHeadersToRequest(&req, headers);

		bool hasData = false;

		if (!requestData.empty()) {
			hasData = true;
		}

		// update length of content if data was given
		if (hasData) {
			req.setContentLength(requestData.length());
		}

		// send the request to the server
		ostream &out = session.sendRequest(req);

		// send the data to the server in the body of the request
		if (hasData) {
			out << requestData;
		}

		// collect the response from the server
		Poco::Net::HTTPResponse res;
		vector<Poco::Net::HTTPCookie> cookies;
		res.getCookies(cookies);
		for(int it = 0; it!=cookies.size();++it){
			m_jar.addCookie(cookies[it]);
		}

		istream &rs = session.receiveResponse(res);
		Poco::StreamCopier::copyToString(rs, *responseData);

		result = res.getStatus();
	} catch (Poco::Exception &ex) {
		cerr << ex.displayText() << endl;
	}

	return result;
}

void Net::addHeadersToRequest(Poco::Net::HTTPRequest *request, map<string, string> *headers) const {
	for (map<string, string>::iterator it = headers->begin(); it != headers->end(); ++it) {
		// for the current header, set the key and value of that header in the request
		request->set(it->first, it->second);
	}
}

string Net::printf(){
	return m_jar.printf();
}
