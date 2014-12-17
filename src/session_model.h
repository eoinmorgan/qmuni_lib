#include <string>
#include <vector>
#include <iostream>

#include <Poco/URI.h>

using namespace std;

class SessionModel {
private:
	string userName;
	string emailAddres;
	string token;
	bool login;
public:
	SessionModel();
	SessionModel(Poco::URI uri);
	SessionModel(URI uri, string token);
	string login(string userName, string code);

	string get_user_name() { return userName };
	string get_email_address() { return emailAddres };
	string get_token() { return token };
	bool get_login() { return login };

	int set_user_name(string input_name);
	int set_email_address(string input_addresss);
	int set_token(string input_token);
	int set_login(bool input_login_status);
};

