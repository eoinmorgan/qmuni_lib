
#include <string>
#include <vector>
#include <iostream>
#include "model.h"


using namespace std;

Model::Model(){
}

Model::Model(string uri) {
	m_uri = uri;
	m_token = "";
	
}

Model::Model(string uri, string tokenIn) {
	m_uri = uri;
	m_token = tokenIn;
	
}



enum State {
        kExpectObjectStart,
        kExpectNameOrObjectEnd,
        kExpectValue,
    }state_;

bool Model::Null() { 
    switch(state_){
    case kExpectValue:

    state_ = kExpectNameOrObjectEnd;
    return true;

    default:
    return false;
    }
}
bool Model::Bool(bool b) { 
    switch(state_){
        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;

        return true;
        default:

        return false;
    }
}
bool Model::Int(int i) { 
    switch(state_){

        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;
        return true;

        default:
        return false;
    }
}
bool Model::Uint(unsigned u) {
    switch(state_){
        
        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;
        return true;

        default:
        return false;
    }
}
bool Model::Int64(int64_t i) {
    switch(state_){
        
        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;
        return true;

        default:
        return false;
    }
}
bool Model::Uint64(uint64_t u) {
    switch(state_){
        
        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;
        return true;

        default:
        return false;
    }
}
bool Model::Double(double d) {
    switch(state_){
        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;
        return true;
        
        default:
        return false;
    }
}
bool Model::String(const char* str, rapidjson::SizeType length, bool copy) { 
   switch(state_){
       case kExpectNameOrObjectEnd:

        state_ = kExpectValue;

        return true;
        case kExpectValue:

        state_ = kExpectNameOrObjectEnd;
        
        return true;
        default:
        
        return false;
    }
}
bool Model::StartObject() { 

     switch (state_) {
        case kExpectObjectStart:
            state_ = kExpectNameOrObjectEnd;
            return true;
        default:
            return false;
        }
}
bool Model::Key(const char *str, rapidjson::SizeType length, bool copy) {
    switch(state_){
        case kExpectNameOrObjectEnd:
            state_ = kExpectValue;
            //cout <<"key"<< endl;
            return true;
        case kExpectValue:
            state_ = kExpectNameOrObjectEnd;

            return true;
        default:

            return false;
    }
    
}
bool Model::EndObject(rapidjson::SizeType memberCount) { 
    //does not work consider how to use enmu
    return true;
}
bool Model::StartArray() { 
    //does not work consider how to use enmu
    return true;
}
bool Model::EndArray(rapidjson::SizeType elementCount) { 

    return true; 
}
void Model::decodeJson(const char json[]){

    Model model;
    rapidjson::Reader reader;
    rapidjson::StringStream ss(json);
    reader.Parse(ss, model);
}