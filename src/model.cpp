#include <string>
#include <vector>
#include <iostream>


#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include "qmuni.h"
#include "model.h"


using namespace std;

Model::Model() {
    rapidjson::Document data_;
    uri_ = QAPI_BASE_URI;
   cout << "net made according to model" << endl;
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

    char *target = (char*)json.c_str();
    data_.Parse(target);
    cout << "fetched Json" << endl;

}
string Model::storeJson(){
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    data_.Accept(writer);
    return buffer.GetString();
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


