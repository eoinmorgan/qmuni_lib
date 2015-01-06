#include "conversation_model.h"
#include "qmuni.h"

ConversationModel::ConversationModel(){
	extern string url;
	uri_ = url + "/conversation/";

}

