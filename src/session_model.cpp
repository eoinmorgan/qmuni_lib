
#include <string>

#include "qmuni.h"

#include "session_model.h"



SessionModel::SessionModel() : Model() {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
	data_.Parse("{\"email\":\"\",\"code\":\"\"}");
	//data_.SetObject();

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
	// TODO:
	// This check complies but it doesnt update the document if the json doesnt already exist.  check doesnt do it job
	if(!data_.HasMember("email")){
		rapidjson::Value val;
		val = data_.AddMember(rapidjson::StringRef("email"), rapidjson::StringRef(target), data_.GetAllocator());
	}
	else{
		
		data_["email"].SetString(target, data_.GetAllocator());
	}
}
void SessionModel::setCode(string code){
	
	char *target = (char*)code.c_str();
	// TODO:
	// This check complies but it doesnt update the document if the json doesnt already exist.  check doesnt do it job
	if(!data_.HasMember("code")){
		rapidjson::Value val;
		val = data_.AddMember(rapidjson::StringRef("code"), rapidjson::StringRef(target), data_.GetAllocator());
	}
	else{
		
		data_["code"].SetString(target, data_.GetAllocator());
	}
}