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
    extern string url;
    net_ = new Net();
    uri_ = url;
   cout << "net made according to model" << endl;
   
}

Model::Model(string uri) {
	extern string url;
    net_ = new Net();
    m_uri = uri;
	m_token = "";
	
}

Model::Model(string uri, string tokenIn) {
	extern string url;
    net_ = new Net();
    m_uri = uri;
	m_token = tokenIn;
	
}
Model::~Model() {
     delete net_;
    net_ = NULL;
}


void Model::fetchJson(const string &json){

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
    
    fetchJson(json);
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


