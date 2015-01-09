
#include "qmuni.h"
#include "conversation_collection.h"
#include "conversation_model.h"

ConversationModel::ConversationModel() : Model(){
	
	uri_ = QAPI_BASE_URI + "/conversation/";

}
ModelCollection<Conversation> ConversationModel::getConversationList(ModelCollection<Conversation> *conversations){
	this->load();
	for (int i = 0; i < data_.Size(); ++i){      
        const rapidjson::Value &convo = data_[i];
       	conversations->addModel(&convo);
    }
	return conversations;
}


string ConversationModel::getSubject(){
	rapidjson::Value &val = data_["subject"];
	string result = val.GetString(); 
	return result;
}/*
string ConversationModel::getCreateDate(){
	rapidjson::Value &val = data_["code"];
	string result = val.GetString();
	return result;
}
*/
int ConversationModel::getConversationID(){
	rapidjson::Value &val = data_["conversation"];
	int result = val.GetInt(); 
	return result;
}
void ConversationModel::setSubject(string subject){

	this->setString("subject", subject);
}
void ConversationModel::setCreateDate(string created){
	
	this->setString("created", created);
}
void ConversationModel::setConversationID(int id){
	
	this->setInt("conversation",id);
}