#include "rapidjson/reader.h"
#include <iostream>

#include "session_model.h"


using namespace std;

class JsonParser{
public:
	Model decode(Model model, const char json[]);
	string encode(Model model);
	bool isValidJson(string str);
};