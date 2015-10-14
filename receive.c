#include "system.h"
#include "button.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "receive.h"
#include "pacer.h"
/** Filename: receive.c
 *  Author: Jacob McKenzie
 *  Date: 13/10/2015
 * 	Description: Waits for one player in a two player game to push the button. 
 *  Doing so will draw a point on the LED display and send True to the other player
 *  to indicate that the game has started.
 */
 
//need to change received to gameActivate or something better
void check_receive(uint8_t *gameActivate, uint8_t *yourTurn, tinygl_point_t pos) { //also needs to take in pos for tinygl_draw_point below
	uint8_t gameState = *gameActivate; //if gameState is 1 then the game has started
	uint8_t newTurn  = *yourTurn;
	tinygl_text("Push the Button!");
	while (gameState != 1) {
		pacer_wait();
		tinygl_update ();
		button_update ();

		if (ir_uart_read_ready_p ()) {
			tinygl_clear();
			gameState = ir_uart_getc ();
		}

		if (button_push_event_p (0)) {
			tinygl_clear();
			tinygl_draw_point (pos, 1);
			ir_uart_putc (1);
			newTurn = 1;
			gameState = 1;
		}
	}
	*gameActivate = gameState;
	*yourTurn = newTurn;
}
