
#include <string>

#include "qmuni.h"

#include "session_model.h"



SessionModel::SessionModel() : Model() {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
	//data_.SetObject();

}

SessionModel::SessionModel(string uri) : Model(uri) {
	// TODO: This really should be a constant of the SessionModel so that the compiler can optimize it
	uri_ = QAPI_BASE_URI + "/session/";
}


