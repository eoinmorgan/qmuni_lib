// public header file
#pragma once
#include <string>
#include "session_handler.h"

using namespace std;

// PRODUCTION API
/*
const string PROTOCOL = "http";
const string SERVER = "beta.qmuni.com";
const string VERSION = "0";
*/

// DEVELOPMENT API
const string PROTOCOL = "http";
const string SERVER = "bsecure";
const string VERSION = "0";
const string QAPI_BASE_URI = PROTOCOL+"://"+SERVER+"/api/v"+VERSION;



int login(string email, string code);
