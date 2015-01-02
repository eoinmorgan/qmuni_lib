#include "model_conversation.h"
#include "qmuni.h"

ConversationModel::ConversationModel(){
	extern string url;
	uri_ = url + "/conversation/";
}