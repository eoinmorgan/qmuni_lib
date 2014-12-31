#pragma once
#include "rapidjson/reader.h"
#include <iostream>




using namespace std;

class JsonParser{
public:
	Model decode(Model model, const char json[]);
	string encode(Model model);
	bool isValidJson(string str);
};