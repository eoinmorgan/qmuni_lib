#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include "rapidjson/document.h"

#include "net.h"

using namespace std;

class Model {
protected:
	string m_userName;
	string m_emailAddres;
	string m_token;
	
	rapidjson::Document data_;
	Net m_net;
	bool m_login_status;
	void debugNet();
public:
	Model();
	Model(string uri);
	Model(string uri, string token);
	
string m_uri;
	string get_user_name() { return m_userName; };
	string get_email_address() { return m_emailAddres; };
	string get_token() { return m_token; };
	bool get_login() { return m_login_status; };

	int set_user_name(string input_name);
	int set_email_address(string input_addresss);
	int set_token(string input_token);
	int set_login(bool input_login_status);
	void decodeJson(const char json[]);
	void debugJson();
	string encodeJson();

};



