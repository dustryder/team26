#ifndef WINSTATUS_H
#define WINSTATUS_H

/** Filename: win_status.h
 *  Author:  Jacob Mckenzie
 *  Date: 12/10/2015
 * 	Description: A program which returns a board-specific message in a game of four-in-a-row 
 * 	to indicate that one player has won and the other has lost. In the case that neither player has 
 *  won and the board is entirely full, a draw message is returned instead.
 *	  
 */

int win_status (uint8_t yourTurn);

#endif /* WINSTATUS_H  */
