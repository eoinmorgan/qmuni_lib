
#include <string>

#include "qmuni.h"

#include "session_model.h"



SessionModel::SessionModel() : Model() {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
	data_.SetObject();

}

SessionModel::SessionModel(string uri) : Model(uri) {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
}

string SessionModel::getEmail(){
	rapidjson::Value &val = data_["email"];
	string result = val.GetString(); 
	return result;
}
string SessionModel::getCode(){
	rapidjson::Value &val = data_["code"];
	string result = val.GetString();
	return result;
}
void SessionModel::setEmail(string email){

	char *target = (char*)email.c_str();
	string str = "email";
	char *key = (char*)str.c_str();

	assert(data_.IsObject());
	cerr << "check one two check check" << endl;
	if(!data_.HasMember(key)){
		 data_.AddMember("email", rapidjson::StringRef(target), data_.GetAllocator());
		assert(data_.IsObject());
	}
	else{
		data_["email"].SetString(target, data_.GetAllocator());
	}
}
void SessionModel::setCode(string code){
	
	char *target = (char*)code.c_str();
	string str = "code";
	char *key = (char*)str.c_str();
	// TODO:
	// This check complies but it doesnt update the document if the json doesnt already exist.  check doesnt do it job
	cerr << "about to asser is object in code" << endl;
	assert(data_.IsObject());
	
	if(!data_.HasMember(key)){
		data_.AddMember("code", rapidjson::StringRef(target), data_.GetAllocator());
	}
	else{
		data_["code"].SetString(target, data_.GetAllocator());
	}
}