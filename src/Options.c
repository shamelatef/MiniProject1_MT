#include "../Header/Options.h"

#include <stdio.h>
#include <stdlib.h>

#include "../Header/menu.h"


typedef struct MenuOptions{

	char trafficLightColor;
	float roomTemperature;
	float engineTemperature;

}MenuOptions;
extern MenuOptions *MO;




extern unsigned int VehicleSpeed;
extern unsigned char AcStatus;
extern unsigned char EngineControllerStatus;

/*

 a Function to decide the vehicle speed based on the color that the user inputs

 */


void TrafficLightColor(unsigned char c)
{



	if (MO->trafficLightColor == 'g'|| MO->trafficLightColor== 'G')
		VehicleSpeed =100;
	else if (MO->trafficLightColor == 'o'|| MO->trafficLightColor== 'O')
		VehicleSpeed = 30;
	else if (MO->trafficLightColor == 'r'|| MO->trafficLightColor== 'R')
		VehicleSpeed = 0;


	if (VehicleSpeed == 30)
	{
		if (AcStatus == AC_OFF)
			AcStatus = AC_ON;

		if (EngineControllerStatus == ENGINE_TEMPERATURE_CONTROLLER_OFF)
			EngineControllerStatus = ENGINE_TEMPERATURE_CONTROLLER_ON;

		#if(WITH_ENGINE_TEMP_CONTROLLER)
		MO->engineTemperature = MO->engineTemperature*(5.0/4) +1.0;
		#endif
		MO->roomTemperature = MO->roomTemperature*(5.0/4) +1.0;

	}
	DisplayCurrentState();



}



/*
 * A function to read the room temperature.
 *
 * */

void RoomTemperature(float *f)
{


	if (*f< 10.0 ||*f> 30.0)
	{
		AcStatus=AC_ON;
		*f = 20.0;
	}

	else
		AcStatus=AC_OFF;

	DisplayCurrentState();

}


/*
 * A function to read Engine Temperature.
 *
 * */
void EngineTemperature(float *f)
{


	if (*f<100.0 || *f > 125.0)
	{
		EngineControllerStatus=ENGINE_TEMPERATURE_CONTROLLER_ON;
		*f=125;

	}
	else
		EngineControllerStatus=ENGINE_TEMPERATURE_CONTROLLER_OFF;



	DisplayCurrentState();


}

