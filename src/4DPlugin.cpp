/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : BSecure
 #	author : Andrew Grandstaff
 #	12/9/14
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

void PluginMain( PA_long32 selector, PA_PluginParameters params )
{
	switch( selector )
	{
// --- testing

		case 1 :
			addNumbers( params );
			break;

	}
}

// ------------------------------------ testing -----------------------------------


void addNumbers( PA_PluginParameters params )
{
	PA_long32 x;
	PA_long32 y;
	PA_long32 result;

	x = PA_GetLongParameter( params, 1 );
	y = PA_GetLongParameter( params, 2 );
	result = PA_GetLongParameter( params, 3 );

	// --- write the code of addNumbers here...
    result = x + y;

	PA_SetLongParameter( params, 3, result );
}
