#include <string>

#include "session_model.h"
SessionModel::SessionModel() : Model(){

cout <<"wrong model created" << endl;
}

SessionModel::SessionModel(string uri) : Model(uri){
	m_uri = uri;
	cout << "this happened: "<< m_uri << endl;

}
string SessionModel::login(string userName, string code){
	//debugNet();
	string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}";
	cout << "data: " << input << endl; 
	cout << "uri: " << m_uri << endl; 
	map<string, string> noHeaders;
	noHeaders.insert(make_pair<string, string>("Content-Type", "application/json"));
	noHeaders.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));

	int result = 0;
	string *output = new string;

	Net *net = new Net();
	result = net->httpPost(m_uri, &noHeaders, input, output);
	result = net->httpPut(m_uri, &noHeaders, input, output);

	cout << net->printf();

	delete net;
	net = NULL;
	// BUG THIS LEAKS MEMORY LIKE A BROKEN FIREHYDRANT LEAKS WATER
	return *output;
}
