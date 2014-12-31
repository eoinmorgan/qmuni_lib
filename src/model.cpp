#include <string>
#include <vector>
#include <iostream>
#include "model.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"


using namespace std;

Model::Model(){
    rapidjson::Document data_;
    net_ = new Net();
   
}

Model::Model(string uri) {
	m_uri = uri;
	m_token = "";
	
}

Model::Model(string uri, string tokenIn) {
	m_uri = uri;
	m_token = tokenIn;
	
}
Model::~Model(){
     delete net_;
    net_ = NULL;
}


void Model::fetchJson(const char json[]){

    
    data_.Parse(json);
    debugJson();

}
string Model::storeJson(){
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    data_.Accept(writer);
    return buffer.GetString();
}

void Model::debugJson(){
 
    rapidjson::Value::MemberIterator it  = getJsonIterator("desc");
    string t = it->value.GetString();
    cout << "resutl: " << t << endl;
    cout << storeJson() << endl;
}

rapidjson::Value::MemberIterator Model::getJsonIterator(string name){
    char *target = (char*)name.c_str();
    rapidjson::Value::MemberIterator it = data_.FindMember(target);
    
    return it;
   
}


