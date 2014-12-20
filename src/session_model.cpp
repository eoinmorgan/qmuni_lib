
#include <string>
#include <vector>
#include <iostream>
#include "http.h"
#include "session_model.h"

using namespace std;

SessionModel() {
	m_uri = string uri("http://bsecure/api/v0/session");
	m_token = "";
	Net *m_net = new Net();
	
	delete m_net;
	m_net = NULL;
	return 0;
}

SessionModel(Poco::URI uriIn) {
	m_uri = uriIn;
	m_token = "";
	return 0;
}

SessionModel(Poco::URI uriIn, string tokenIn) {
	m_uri = uriIn;
	m_token = tokenIn;
	return 0;
}


string login(string userName, string code){
	string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}"
	m_net.httpPost(m_uri, 

	return output;	
}

