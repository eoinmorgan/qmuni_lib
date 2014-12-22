#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include <iostream>

#include "json_parser.h"




Model JsonParser::decode(Model model, const char json[] ){
rapidjson::Reader reader;
rapidjson::StringStream ss(json);
reader.Parse(ss, model);
return model;
}

string JsonParser::encode(Model model) {

//write object data to buffer
rapidjson::StringBuffer sb;
rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
writer.StartObject();
writer.EndObject();

//going to change here for testing purposes
string result = sb.GetString();


return result;

}
bool isValidJson(string str){
	return true;
}