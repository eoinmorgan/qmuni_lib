#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace std;

class Json{
public:
	type getJson(string json);
	string objToJson(type object);
	private:
	
};