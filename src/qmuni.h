// public header file
#pragma once
#include <string>
#include "session_handler.h"

using namespace std;

const string PROTOCOL = "http";
const string SERVER = "beta.qmuni.com";
const string VERSION = "0";
int login(string email, string code);
