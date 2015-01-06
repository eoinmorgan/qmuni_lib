#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "session_model.h"

using namespace std;

class SessionHandler {
public:
	SessionHandler();
	SessionHandler(string uri);
	SessionHandler(string uriIn, string token, Model session);


	~SessionHandler();

	void debugJson(string json);

	int login(string email, string code);
	string getUri();
	int setUri(string uri);
	//void fetchConversationList();

	

	
private:
	string m_token;
	string uri_;
	Net *net_;
	SessionModel *session_model_;
	
};

