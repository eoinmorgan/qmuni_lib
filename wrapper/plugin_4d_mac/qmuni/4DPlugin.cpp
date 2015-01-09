/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : qmuni
 #	author : Andrew Grandstaff
 #	1/8/15
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

#include <stdio.h>
#include <string.h>

#include "qmuni.h"
#include "session_handler.h"

void PluginMain( PA_long32 selector, PA_PluginParameters params )
{
	switch( selector )
	{
// --- Basics

		case 1 :
			login( params );
			break;

	}
}

// ------------------------------------ Basics ------------------------------------


void login( PA_PluginParameters params )
{
	PA_Unichar* email_uchars;
	PA_Unistring* email;
	PA_Unichar* code_uchars;
	PA_Unistring* code;
	short returnValue;

	email = PA_GetStringParameter( params, 1 );
	email_uchars = PA_GetUnistring( email );
	code = PA_GetStringParameter( params, 2 );
	code_uchars = PA_GetUnistring( code );
	SessionHandler *session_handler = new SessionHandler();
	session_handler->login(email,code);
	PA_ReturnShort( params, returnValue );
}

