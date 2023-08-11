/*
 * display.h
 *
 *  Created on: Aug 7, 2023
 *      Author: shame
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

// Enums for the  options' list

 enum prompt1options {CALL_SET_MENU, CALL_TURN_ON_OFF,QUIT_SYS};
 enum menu {CALL_ENGINE_OFF, CALL_TRAFFIC_LIGHT,CALL_ROOM_TEMP, CALL_ENGINE_TEMP,ERROR};

unsigned char Menu_1(unsigned char c);
unsigned char Menu_2(unsigned char c);
void DisplayCurrentState();



#endif /* DISPLAY_H_ */
