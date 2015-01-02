#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>



#include "qmuni.h"


using namespace std;

string url = PROTOCOL + "://" + SERVER + "/api/v" + VERSION;

// debug the network connection

int debugNet() {
	Net *net = new Net();
	map<string, string> noHeaders;
	map<string, string> jsonHeader;
	string uri = "http://bsecure/api/v0/session";
	string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	cout << "url: " << uri << endl;

	jsonHeader.insert(make_pair<string, string>("Content-Type", "application/json"));
	jsonHeader.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	noHeaders.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));
	
	string *output = new string;
	int result = net->httpPost(uri, &jsonHeader, data, output);
	cout << "post result: " << result << " " << *output << endl;

	//cout << "get result: ";
	//cout << net->httpGet(uri, noHeaders) << endl;
	//cout << "put result: ";
	//cout << net->httpPut(uri, data, jsonHeader) << endl;
	//cout << "delete result: ";
	//cout << net->httpDelete(uri, noHeaders) << endl;

	delete net;
	delete output;
	net = NULL;
	output = NULL;

	return result;
}

void debugSessionModel(){


	SessionHandler *session_handler = new SessionHandler("http://mocksvc.mulesoft.com/mocks/487209f4-65da-4576-acbd-c89231ea860f/book");

	//cout << "from main " << session_handler->m_session_model.m_uri << endl;
	string data = "{\"email\":\"x@src.bz\",\"code\":\"1\"}";

	cout << session_handler->login("x@src.bz", "1") << endl;
	
	delete session_handler;
	session_handler = NULL;
	

}
int login(string email, string code)
{
	SessionHandler *session_handler = new SessionHandler("http://mocksvc.mulesoft.com/mocks/487209f4-65da-4576-acbd-c89231ea860f/book");
	return session_handler->login(email, code);

}

void debugJson(){

	string json = "[{\"subject\":\"testing\",\"created\":\"2014-12-30 10:23:54\",\"conversation\":1,\"last_message\"\
					  :{\"message\":0,\"profile\"\
						  :{\"profile\":0,\"email\":null,\"image_path\":null,\"phone\":null,\"first_name\":null,\"last_name\":null,\"address\":null\
						   },\
						   \"content\":null,\"delivered\":null,\"files\":[]\
						}\
					},\
					{\"subject\":\"\",\"created\":\"2014-12-31 12:56:30\",\"conversation\":2,\"last_message\":\
						{\"message\":2,\"profile\":\
							{\"profile\":3,\"email\":\"agrandstudent@gmail.com\",\"image_path\":\"\\/file\\/3\\/fEqXsD\",\"phone\":\"\",\"first_name\":\"\",\"last_name\":\"\",\"address\":\"\"\
							},\
							\"content\":\"convo created\",\"delivered\":\"2014-12-31 12:56:50\",\"files\":[]\
						}\
					},\
					{\"subject\":\"\",\"created\":\"2014-12-31 12:57:30\",\"conversation\":3,\"last_message\"\
						:{\"message\":0,\"profile\"\
							:{\"profile\":0,\"email\":null,\"image_path\":null,\"phone\":null,\"first_name\":null,\"last_name\":null,\"address\":null\
							},\
							\"content\":null,\"delivered\":null,\"files\":[]\
						}\
					},\
					{\"subject\":\"\",\"created\":\"2014-12-31 12:57:49\",\"conversation\":4,\"last_message\":{\"message\":0,\"profile\":{\"profile\":0,\"email\":null,\"image_path\":null,\"phone\":null,\"first_name\":null,\"last_name\":null,\"address\":null},\"content\":null,\"delivered\":null,\"files\":[]}},{\"subject\":\"\",\"created\":\"2014-12-31 12:58:31\",\"conversation\":5,\"last_message\":{\"message\":0,\"profile\":{\"profile\":0,\"email\":null,\"image_path\":null,\"phone\":null,\"first_name\":null,\"last_name\":null,\"address\":null},\"content\":null,\"delivered\":null,\"files\":[]}}]";
					

	//string json = "{\"name\":\"ThE bIbLE\",\"by\":\"andrew\",\"desc\":\"you do not want to known\"}";
	/*
	string json = "{\"subject\":\"testing\",\"created\":\"2014-12-30 10:23:54\",\"conversation\":1,\"last_message\"\
					  :{\"message\":0,\"profile\"\
						  :{\"profile\":0,\"email\":null,\"image_path\":null,\"phone\":null,\"first_name\":\"andrew\",\"last_name\":null,\"address\":null\
						   },\
						   \"content\":null,\"delivered\":null,\"files\":[]\
						}\
					}";
					*/
	SessionHandler *session_handler = new SessionHandler();
	session_handler->debugJson(json);
}

int main(int argc, char **argv) {
	//login("x@src.bz", "1");
	debugJson();

	return 0;	
}

