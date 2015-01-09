#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <string>

#include "rapidjson/document.h"

#include "net.h"

using namespace std;

class Model {
private:
	
protected:
	string emailAddres_;
	string token_;
	string uri_;
	
	
	rapidjson::Document data_;
	bool login_status_;
	void debugNet();
	string storeJson();
	rapidjson::Value::MemberIterator getJsonIterator(string name);
	

public:
	Model();
	Model(string uri);
	Model(string uri, string token);
	~Model();

	string get_email_address() { return emailAddres_; };
	string get_token() { return token_; };
	bool get_login() { return login_status_; };

	int set_user_name(string input_name);
	int set_email_address(string input_addresss);
	int set_token(string input_token);
	int set_login(bool input_login_status);
	void debugJson(string json);
	void parseJson(const string &json);

	int save();
	int save(int id);
	int load();
	int load(int id);
	int destroy();
	int destroy(int id);
	int create();

	void setString(string key, string value);
	void setInt(string key, int value);

	int getInt(string key);
	string getString(string key);
};


