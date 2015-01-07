#pragma once
#include <string>

#include "model.h"

using namespace std;

class SessionModel : public Model{
private:
	string code_;
	string email_;
public:
	SessionModel();
	SessionModel(string uri);
	int login(string email, string code);
	
	string getEmail();{return email_;}
	string getCode();{return code_:}

	void setEmail(string email);{email_ = email;}
	void setCode(string code);{code_ = code;}

	
};