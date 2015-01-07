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
	string printf();
	string getUri();
	int setUri(string uri);

	int login(string email, string code);

	//not sure what this should return at the momenet
	void fetchConversationList();

	

	
private:
	string m_token;
	string uri_;
	SessionModel *session_model_;

	
};

