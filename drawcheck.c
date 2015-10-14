/** Filename: drawcheck.c
 *  Author: Ju Feng Zhou
 *  Date: 12/10/2015
 * 	Description: Checks a 2d array for amount of non-null characters and returns the value
 */
#include "tinygl.h"
#include "drawcheck.h"

int drawCheck(char boardGame[][7]) {

	int drawCounter = 0;
	int i = 0;
	int j = 0;
	while (i < 5) {
		while (j < 7) {
			if (boardGame[i][j] != '\0') {
			drawCounter += 1;
			}
		j += 1;
		}
	i += 1;
	j = 0;
	}

	return drawCounter;
}
