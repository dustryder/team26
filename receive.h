#ifndef RECEIVE_H
#define RECEIVE_H

/** Filename: receive.h
 *  Author: Jacob McKenzie
 *  Date: 13/10/2015
 * 	Description: Waits for one player in a two player game to push the button. 
 *  Doing so will draw a point on the LED display and send True to the other player
 *  to indicate that the game has started.
 */
 
//typedef struct receivedValues 
//{
//	int receive;
//	int turn;
	//tinygl_point_t position;
//} receive_t;

void check_receive(uint8_t *gameActivate, uint8_t *yourTurn, tinygl_point_t pos);

#endif /* RECEIVE_H  */
