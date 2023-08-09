/*
 * display.h
 *
 *  Created on: Aug 7, 2023
 *      Author: shame
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

// Enums for the  options' list

typedef enum prompt1options {CALL_SET_MENU, CALL_TURN_ON_OFF,QUIT_SYS} Prompt1options;
typedef enum menu {CALL_ENGINE_OFF, CALL_TRAFFIC_LIGHT,CALL_ROOM_TEMP, CALL_ENGINE_TEMP,ERROR} MENU;

unsigned char SetMenu(unsigned char c);
unsigned char TurnOn_OFF(unsigned char c);
void DisplayCurrentState();



#endif /* DISPLAY_H_ */
