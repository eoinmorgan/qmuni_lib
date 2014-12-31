#pragma once
#include <string>

#include "model.h"

using namespace std;

class SessionModel : public Model{
public:
	SessionModel();
	SessionModel(string uri);
	int login(string userName, string code);
	
};