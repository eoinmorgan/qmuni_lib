#include <string>
#include <vector>
#include <iostream>
#include "model.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"


using namespace std;

Model::Model(){
    rapidjson::Document data_;
}

Model::Model(string uri) {
	m_uri = uri;
	m_token = "";
	
}

Model::Model(string uri, string tokenIn) {
	m_uri = uri;
	m_token = tokenIn;
	
}


void Model::decodeJson(const char json[]){

    
    data_.Parse(json);

}
string Model::encodeJson(){
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    data_.Accept(writer);
    return buffer.GetString();
}

void Model::debugJson(){
    rapidjson::Value &test = data_["hello"];
    string t = test.GetString();
    cout << "resutl: " << t << endl;
    cout << encodeJson() << endl;
}
