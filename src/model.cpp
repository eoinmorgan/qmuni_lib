#include <string>
#include <vector>
#include <iostream>


#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include "net.h"
#include "qmuni.h"
#include "model.h"


using namespace std;

Model::Model() {
    rapidjson::Document data_;
    uri_ = QAPI_BASE_URI;
}

Model::Model(string uri) {
    uri_ = QAPI_BASE_URI;
	token_ = "";
}

Model::Model(string uri, string tokenIn) {
    uri_ = QAPI_BASE_URI;
	token_ = tokenIn;
}

Model::~Model() {
}


void Model::parseJson(const string &json){
    cerr << "json to parse: " << json << endl;
    char *target = (char*)json.c_str();
    data_.Parse(target);

}
string Model::storeJson(){
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    data_.Accept(writer);
    string  result = buffer.GetString();
    cerr << "json to be stored: " << result << endl;
    return result;
}

void Model::debugJson(string json){
    cout << "starting debugJson" << endl; 
    
    parseJson(json);
    //rapidjson::Value::MemberIterator it  = getJsonIterator("created");
    for (int i = 0; i < data_.Size(); ++i){
        
      
        const rapidjson::Value &convo = data_[i];
        const rapidjson::Value &message = convo["last_message"];
        cout << message["message"].GetInt() << endl;
    }

}

rapidjson::Value::MemberIterator Model::getJsonIterator(string name){
    char *target = (char*)name.c_str();
    rapidjson::Value::MemberIterator it = data_.FindMember(target);
    if(it == data_.MemberEnd()){
        cout << "cant find Member: " << name << endl;
    }
    
    return it;
   
}
int Model::save(){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    status_code = Net::Instance()->httpPost(uri_,&no_headers,this->storeJson(),output);
    return status_code;   
}
int Model::save(int id){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    string request_uri = uri_+":"+to_string(id);
    status_code = Net::Instance()->httpPost(request_uri, &no_headers, this->storeJson(), output);
    return status_code;    
}
int Model::load(){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    status_code = Net::Instance()->httpGet(uri_, &no_headers, output);
    this->parseJson(*output);
    return status_code;    
}
int Model::load(int id){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    string request_uri = uri_ + ":" + to_string(id);
    status_code = Net::Instance()->httpGet(request_uri, &no_headers, output);
    this->parseJson(*output);
    return status_code;    
}
int Model::destroy(){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    status_code = Net::Instance()->httpDelete(uri_, &no_headers,output);
    return status_code;   
}
int Model::destroy(int id){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    status_code = Net::Instance()->httpDelete(uri_, &no_headers,output);
    return status_code;    
}
int Model::create(){
    map<string, string> no_headers;
    int status_code;
    string *output = new string();
    status_code = Net::Instance()->httpPut(uri_, &no_headers, this->storeJson(), output);
    return status_code;
}
void Model::setString(string key, string value){

    char *c_value = (char*)value.c_str();
    char *c_key = (char*)key.c_str();

    assert(data_.IsObject());
    if(!data_.HasMember(c_key)){
         data_.AddMember(rapidjson::StringRef(c_key), rapidjson::StringRef(c_value), data_.GetAllocator());
        assert(data_.IsObject());
        cerr << "new key:value pair added: " << c_key << ":" << c_value << endl;
    }
    else{
        data_[c_key].SetString(c_value, data_.GetAllocator());
        assert(data_.IsObject());
        cerr << "key:value pair modfied: " << c_key << ":" << c_value << endl;
    }
}
void Model::setInt(string key, int value){

    
    char *c_key = (char*)key.c_str();

    assert(data_.IsObject());
    if(!data_.HasMember(c_key)){
         data_.AddMember(rapidjson::StringRef(c_key), value, data_.GetAllocator());
        assert(data_.IsObject());
        cerr << "new key:value pair added: " << c_key << ":" << value << endl;
    }
    else{
        data_[c_key].SetInt(value);
        assert(data_.IsObject());
        cerr << "key:value pair modfied: " << c_key << ":" << value << endl;
    }
}
int Model::getInt(string key){
    char *c_key = (char*)key.c_str();
    rapidjson::Value &val = data_[c_key];
    int result = val.GetInt(); 
    return result;
}
string Model::getString(string key){
    char *c_key = (char*)key.c_str();
    rapidjson::Value &val = data_[c_key];
    string result = val.GetString(); 
    return result;
}
