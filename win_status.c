/** Filename: win_status.c
 *  Author:  Jacob Mckenzie
 *  Date: 12/10/2015
 * 	Description: A program which returns a board-specific message in a game of four-in-a-row 
 * 	to indicate that one player has won and the other has lost. In the case that neither player has 
 *  won and the board is entirely full, a draw message is returned instead.
 *	  
 */

//#include <stdlib.h>
#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"
#include "win_status.h"

/* checks the value of yourTurn - if 1 (it is your turn) 
 * but the while(1) loop has been broken out of because arrayCheck is satisfied
 * then that inidicates you have lost. If 0 (you just had your turn) and 
 * while(1) loop is broken out of then that inidicates you have won.
*/

int win_status (uint8_t yourTurn) {
    if (yourTurn == 1) {
		tinygl_text("You lose!");
	} else if (yourTurn == 0){
		tinygl_text("You win!");
	} else if (yourTurn == 2) {
		tinygl_text("It's a draw!");
	}
	while(1) {
		pacer_wait();
		tinygl_update();
	}

}

