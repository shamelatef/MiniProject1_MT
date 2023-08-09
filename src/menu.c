/*
 * display.c
 *
 *  Created on: Aug 7, 2023
 *      Author: shame
 */

#include "../Header/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Header/Options.h"

extern char OnOffString[][4];

typedef struct MenuOptions{

	char trafficLightColor;
	float roomTemperature;
	float engineTemperature;

}MenuOptions;
extern MenuOptions *MO;

extern unsigned int *VehicleSpeed;
extern unsigned char *AcStatus;
extern unsigned char *EngineControllerStatus;



/*
 * TurnOn_OFF is a function that takes a character and depending on it, it returns a value that
 * corresponds to a function call.
 *
  	a. Turn on the vehicle engine
	b. Turn off the vehicle engine
	c. Quit the system


 *
 * */
/*First menu*/
unsigned char TurnOn_OFF(unsigned char c)

{

	unsigned char result;
	switch (c)
	{
	case 'a':
		result=CALL_SET_MENU;
		break;
	case 'b':
		result =CALL_TURN_ON_OFF;
		break;
	case 'c':
		printf("Quit \n");
		result=QUIT_SYS;
		break;

	default:
		printf("Please try again - Wrong Char\n");
		result = CALL_TURN_ON_OFF;
		break;
	}
return result;
}


/*

 this function is only called when the user inputs the first choice "Turn ON",
	it takes a character

 	a. Turn off the engine
	b. Set the traffic light color.
	c. Set the room temperature (Temperature Sensor)
	d. Set the engine temperature (Engine Temperature Sensor)


 * */
/*Second Menu*/
unsigned char SetMenu(unsigned char c)
{
	unsigned char result;

	switch (c)
	{
	case 'a':
		//Prompt();
		result =CALL_ENGINE_OFF;
		break;
	case 'b':
		result=CALL_TRAFFIC_LIGHT;
		//TrafficLightColor_UserInput();
		break;
	case 'c':
		result =CALL_ROOM_TEMP;
		//RoomTemperature_UserInput();
		break;
	case 'd':
		result = CALL_ENGINE_TEMP;
		//EngineTemperature_UserInput();
		break;
	default:
		printf("Wrong Char - Try Again\n");
		result = ERROR;
		break;


	}
	return result;
}


/*


 A Function to Display the current state after each input the user does.

 **/

void DisplayCurrentState()
{
	printf("Engine is: %s\n",OnOffString[1]);
	if (*AcStatus == AC_ON)
		printf("AC: %s\n",OnOffString[AC_ON] );
	if (*AcStatus == AC_OFF)
		printf("AC: %s\n",OnOffString[AC_OFF] );


	printf("Vehicle Speed: %u Km/hr\n",*VehicleSpeed);
	printf("Room Temperature: %f C\n",MO -> roomTemperature);

#if(WITH_ENGINE_TEMP_CONTROLLER)
	printf("Engine Temperature Controller: %s\n",OnOffString[*EngineControllerStatus]);
	printf("Engine Temperature: %f C\n\n",MO ->engineTemperature);
#endif

}


