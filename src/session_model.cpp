
#include <string>
#include <vector>
#include <iostream>
#include "session_model.h"


using namespace std;

SessionModel::SessionModel() {
	m_uri =  "http://bsecure/api/v0/session";
	m_token = "";
	Net *m_net = new Net();
	
	delete m_net;
	m_net = NULL;
	
}

SessionModel::SessionModel(string uri) {
	m_uri = uri;
	m_token = "";
	
}

SessionModel::SessionModel(string uri, string tokenIn) {
	m_uri = uri;
	m_token = tokenIn;
	
}


string SessionModel::login(string userName, string code){
	string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}";
	map<string, string> noHeaders;
	noHeaders.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	return m_net.httpPost(m_uri, input, noHeaders);

		
}

