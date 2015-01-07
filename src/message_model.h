#pragma once

#include <string>

#include "conversation_model.h"

class MessageModel : public ConversationModel gs{
private:
	int id_;
	string content_;
	string delivered_date_;
protected:
public:
	MessageModel();
	string printf();
};
