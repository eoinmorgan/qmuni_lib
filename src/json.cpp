#include "json.h"

enum State {
        kExpectObjectStart,
        kExpectNameOrObjectEnd,
        kExpectValue,
    }state_;

bool Json::Null() { 
	switch(state_)
	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	default:
	return false;
    
}
bool Json::Bool(bool b) { 
switch(state_)
	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	default:
	return false;
}
bool Json::Int(int i) { 
switch(state_)

	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	return true;

	default:
	return false;
}
bool Json::Uint(unsigned u) {
cswitch(state_)
	
	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	return true;

	default:
	return false;
}
bool Json::Int64(int64_t i) {
switch(state_)
	
	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	return true;

	default:
	return false;
}
bool Json::Uint64(uint64_t u) {
switch(state_)
	
	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	return true;

	default:
	return false;
}
bool Json::Double(double d) {

	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	return true;
	
	default:
	return false;
}
bool Json::String(const char* str, rapidjson::SizeType length, bool copy) { 
   case kExpectNameOrObjectEnd:

	state_ = kExpectValue;
	return true;
	
	case kExpectValue:

	state_ = kExpectNameOrObjectEnd;
	return true;
	
	default:
	return false;
}
bool Json::StartObject() { 

	 switch (state_) {
        case kExpectObjectStart:
            state_ = kExpectNameOrObjectEnd;
            return true;
        default:
            return false;
        }
}
bool Json::Key(const char* str, rapidjson::SizeType length, bool copy) {
    
    return true;
}
bool Json::EndObject(rapidjson::SizeType memberCount) { 
	return true
}
bool Json::StartArray() { 

	return true; 
}
bool Json::EndArray(rapidjson::SizeType elementCount) { 

	return true; 
}
void Json::debugJson(){
const char json[] = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
    Model model;
    rapidjson::Reader reader;
    rapidjson::StringStream ss(json);
    reader.Parse(ss, model);
}