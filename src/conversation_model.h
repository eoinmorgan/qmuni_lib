#pragma once

#include <string>

#include "model.h"

using namespace std;

class ConversationModel : public Model{
private:
	string subject;
	int conversation_id_;
	string created_date_;
	

protected:

public:
	ConversationModel();
	string getConversation();
	string getConversationList();
	string newConversation();

	string getSubject();
	int getConversationID();

	void setSubject(string subject);
	void setCreateDate(string subject);
	void setConversationID(int id);
};