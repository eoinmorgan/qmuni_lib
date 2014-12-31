
#include <string>

#include "session_model.h"
SessionModel::SessionModel() : Model(){


}

SessionModel::SessionModel(string uri) : Model(uri){
	m_uri = uri;


}
int SessionModel::login(string userName, string code){
	//debugNet();
	string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}";
	//cout << "data: " << input << endl; 
	//cout << "uri: " << m_uri << endl; 
	map<string, string> noHeaders;
	noHeaders.insert(make_pair<string, string>("Content-Type", "application/json"));
	noHeaders.insert(make_pair<string, string>("User-Agent", "Qmuni Client Library v1"));

	int status_code = 0;
	string *output = new string();
	

	
	status_code = net_->httpPost(m_uri, &noHeaders, input, output);
	if(status_code == 200 || status_code == 201)
	{	
		char *json = (char*)output->c_str();
		fetchJson(json);
		
	}
	
	

	//cout << net->printf();
	delete output;
	output = NULL;
	

	// BUG THIS LEAKS MEMORY LIKE A BROKEN FIREHYDRANT LEAKS WATER
	return status_code;
}

