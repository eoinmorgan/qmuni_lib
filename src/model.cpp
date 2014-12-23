
#include <string>
#include <vector>
#include <iostream>
#include "model.h"


using namespace std;

Model::Model() {
 cout << "bad model" << endl;
	m_token = "";
	Net m_net;
	
}

Model::Model(string uri) {
	m_uri = uri;
	cout << "got here " << m_uri << endl;
	Net m_net;
	m_token = "";
	
}

Model::Model(string uri, string tokenIn) {
	m_uri = uri;
	m_token = tokenIn;
	
}



void Model::debugNet() {
	Net *net = new Net();
	map<string, string> noHeaders;
	map<string, string> jsonHeader;
	string uri = "http://mocksvc.mulesoft.com/mocks/487209f4-65da-4576-acbd-c89231ea860f/book";
	string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	jsonHeader.insert(make_pair<string, string>("Content-Type", "application/json"));
	jsonHeader.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	noHeaders.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	
	cout << "post result: ";
	cout << net->httpPost(uri, data, jsonHeader) << endl;
	cout << "get result: ";
	cout << net->httpGet(uri, noHeaders) << endl;
	cout << "put result: ";
	cout << net->httpPut(uri, data, jsonHeader) << endl;
	cout << "delete result: ";
	cout << net->httpDelete(uri, noHeaders) << endl;
	
	
	delete net;
	net = NULL;
	
}
	bool Model::Null() { 

		return true; 
	}
    bool Model::Bool(bool b) { 

    	return true; 
    }
    bool Model::Int(int i) { 

    	return true; 
    }
    bool Model::Uint(unsigned u) {

    	return true; 
    }
    bool Model::Int64(int64_t i) {

    	return true; 
    }
    bool Model::Uint64(uint64_t u) {
    
    	return true; 
    }
    bool Model::Double(double d) {

    	return true; 
    }
    bool Model::String(const char* str, rapidjson::SizeType length, bool copy) { 
        
        return true;
    }
    bool Model::StartObject() { 

    	return true; 
    }
    bool Model::Key(const char* str, rapidjson::SizeType length, bool copy) {
        
        return true;
    }
    bool Model::EndObject(rapidjson::SizeType memberCount) { 

    	return true; 
    }
    bool Model::StartArray() { 

    	return true; 
    }
    bool Model::EndArray(rapidjson::SizeType elementCount) { 

    	return true; 
    }