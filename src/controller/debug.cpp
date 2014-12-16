#include "Controller/Session.h"
#include <iostream>
#include <string>
int main(int argc, char **argv){
	
	Session session = new Session();
	string userName = "x@src.biz";
	string code = "x";
	cout << session.login(userName, code);
}