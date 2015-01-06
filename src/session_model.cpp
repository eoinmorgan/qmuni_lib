
#include <string>

#include "qmuni.h"

#include "session_model.h"



SessionModel::SessionModel() : Model() {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
}

SessionModel::SessionModel(string uri) : Model(uri) {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
}

// TODO: this method should go away
// TODO: the network code needs to live in the network file
// TODO: the model should only be responsible for saving itself to the server
// TODO: the handler should be responsible for creating a model, setting model info, and telling the model to save
// TODO: the handler should also deal with the result of the save of the model


/*
void SessionModel::fetchConversationList(){
    map<string, string> headers;
    headers["Content-Type"] = "application/json";
    headers["User-Agent"] = "Qmuni Client Library v1";

    int status_code = 0;
    string *response = new string();
    status_code = net_->httpGet(uri_, &headers, response);
    string json = *response;
    Model::fetchJson(json);
     for (int i = 0; i < data_.Size(); ++i){
        
      
        const rapidjson::Value &convo = data_[i];
       
    }
}
*/