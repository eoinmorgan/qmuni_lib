
#include "conversation_model.h"
#include "qmuni.h"

ConversationModel::ConversationModel() : Model(){
	
	uri_ = QAPI_BASE_URI + "/conversation/";

}
string ConversationModel::getConversation(){
	return "conversation_id_;";
}

