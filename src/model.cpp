#include <string>
#include <vector>
#include <iostream>


#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#include "qmuni.h"
#include "model.h"


using namespace std;

Model::Model(){
    rapidjson::Document data_;
    extern string url;
    net_ = new Net();
    uri_ = url;
   
}

Model::Model(string uri) {
	extern string url;
    m_uri = uri;
	m_token = "";
	
}

Model::Model(string uri, string tokenIn) {
	extern string url;
    m_uri = uri;
	m_token = tokenIn;
	
}
Model::~Model(){
     delete net_;
    net_ = NULL;
}


void Model::fetchJson(const char json[]){

    
    data_.Parse(json);
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
    char *target = (char*)json.c_str();
    fetchJson(target);
    //rapidjson::Value::MemberIterator it  = getJsonIterator("created");
    for (int i = 0; i < data_.Size(); ++i){
        
        const rapidjson::Value &message = data_["last_message"];
        const rapidjson::Value &profile = message["profile"];
    }
   

    string t = "fail";
    if(data_["first_name"].IsString()){
          t = data_["first_name"].GetString();
    }
   
    cout << "resutl: " << t << endl;
    cout << storeJson() << endl;
}

rapidjson::Value::MemberIterator Model::getJsonIterator(string name){
    char *target = (char*)name.c_str();
    rapidjson::Value::MemberIterator it = data_.FindMember(target);
    if(it == data_.MemberEnd()){
        cout << "cant find Member: " << name << endl;
    }
    
    return it;
   
}


