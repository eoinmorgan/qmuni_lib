#pragma once
#include <string>

#include "model.h"

using namespace std;

class SessionModel : public Model{
private:

public:
	SessionModel();
	SessionModel(string uri);
	int login(string email, string code);
	
	string getEmail();
	string getCode();

	void setEmail(string email);
	void setCode(string code);

	
};