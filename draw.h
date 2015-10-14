/** Filename: draw.h
 *  Author:  Ju Feng Zhou
 *  Date: 10/10/2015
 * 	Description: A program which takes 5 by 7 2d array and lights up points in the ledmatrix that corresponds to
 * 				 'X' and 'O' values in the 2d array with 'X' flashing via pulse width modulation			  
 */

#ifndef DRAW_H
#define DRAW_H
#include "system.h"

void draw(uint8_t *state, char boardGame[][7], uint8_t *pwm_tick);

#endif /* DRAW_H  */
