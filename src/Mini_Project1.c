/*
 ============================================================================
Name        : Mini_Project1.c

Description : Vehicle Control system
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include "../Header/menu.h"
#include "../Header/Options.h"


/**  A structure to store the trafficLightColor,  roomTemperature , engineTemperature  in (Turn ON CASE)    **/
typedef struct MenuOptions{

	char trafficLightColor;
	float roomTemperature;
	float engineTemperature;

}MenuOptions;
MenuOptions *MO =NULL;



char OnOffString[][4] ={"OFF","ON"}; // Array of strings to store ON/OFF in



unsigned int 	*VehicleSpeed=NULL;// Gloabal variable (pointer to an unsigned int) to store the vehicle speed in
unsigned char 	*AcStatus=NULL; //
unsigned char  	*EngineControllerStatus=NULL; //



int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


	// allocating the pointers
	MO =(struct MenuOptions *) malloc(sizeof(struct MenuOptions));
	EngineControllerStatus = (unsigned char *) malloc(sizeof(unsigned char));
	AcStatus = (unsigned char *) malloc(sizeof(unsigned char));
	VehicleSpeed = (unsigned int *) malloc(sizeof(unsigned int));


	//initializing the variables.
	*AcStatus=AC_OFF;
	*VehicleSpeed=10;
	*EngineControllerStatus = ENGINE_TEMPERATURE_CONTROLLER_OFF;
	MO->roomTemperature   = 0.0;
	MO->engineTemperature = 0.0;

	// User input variables
	unsigned char operation;// for choosing to turnOn/OFF
	unsigned char option;// for choosing the option to be done in ON case

	// storing functions' return.
	unsigned char res1;
	unsigned char res2;

	// Function pointer for engine/room temperature.
	void (*Func_Ptr)(float*) = NULL;

	for(;;)
	{
		printf("a. Turn on the vehicle engine\nb. Turn off the vehicle engine\nc. Quit the system\n");
		scanf(" %c",&operation);
		res1= TurnOn_OFF(operation);


		if (res1==CALL_SET_MENU)
		{
			for(;;)
			{
				printf("a. Turn off the engine\nb. Set the traffic light color.\nc. Set the room temperature (Temperature Sensor)\nd. Set the engine temperature (Engine Temperature Sensor)\n");
				scanf(" %c",&option);

				res2 = SetMenu(option);
				if (res2 == CALL_ENGINE_OFF)
					break;
				else if (res2==CALL_TRAFFIC_LIGHT)
				{
					printf("Choose a color\n");
					scanf(" %c",&MO->trafficLightColor);
					TrafficLightColor(MO->trafficLightColor);
					continue;
				}
				else if (res2==CALL_ROOM_TEMP)
				{
					printf("Room Temperature?\n");
					scanf("%f",&MO->roomTemperature);
					Func_Ptr = RoomTemperature;
					(*Func_Ptr)(&MO->roomTemperature);

				}
				else if (res2==CALL_ENGINE_TEMP)
				{
					#if(WITH_ENGINE_TEMP_CONTROLLER)
						printf("Engine Temperature?\n");
						scanf("%f",&MO->engineTemperature);
						Func_Ptr = EngineTemperature;
						(*Func_Ptr)(&MO->engineTemperature);
					#endif

				}
				else if (res2==ERROR)
					continue;
			}
		}
		else if (res1==CALL_TURN_ON_OFF)
			continue;
		else if (res1==QUIT_SYS)
			break;
	}

return EXIT_SUCCESS;
}

