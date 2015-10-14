/** Filename: draw.c
 *  Author:  Ju Feng Zhou
 *  Date: 10/10/2015
 * 	Description: A program which takes 5 by 7 2d array and lights up points in the ledmatrix that corresponds to
 * 				 'X' and 'O' values in the 2d array with 'X' flashing via pulse width modulation			  
 */

#include <stdlib.h>
#include "draw.h"
#include "tinygl.h"
#include "system.h"

void draw(uint8_t *state, char boardGame[][TINYGL_HEIGHT], uint8_t *pwm_tick) {
	
	uint8_t tempState = *state;
	uint8_t tempTick = *pwm_tick;

	tempState = 20 > tempTick * 100 / 25;

	for (int x = 0; x < TINYGL_WIDTH; x++)
	{
		for (int y = 0; y < TINYGL_HEIGHT; y++)
		{	
			if (boardGame[x][y] == 'X') {
				tinygl_draw_point (tinygl_point (x, y), tempState);
			}
			if (boardGame[x][y] == 'O') {
				tinygl_draw_point (tinygl_point (x, y), 1);
			}
		}
	}
	
	tempTick++;
	if (tempTick >= 25)
	{
		tempTick = 0;
	}

	*state = tempState;
	*pwm_tick = tempTick;
}
