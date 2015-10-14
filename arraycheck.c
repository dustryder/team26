/** Filename: arraycheck.c
 *  Author: Ju Feng Zhou & Jacob McKenzie
 *  Date: 14/10/2015
 * 	Description: Checks a 2d array for four Xs or four Os which lie adjacent to each other and returns True if such a line is found
 */
#include "arraycheck.h"

int checkVert(int xPos, int yPos, char boardGame[][7]) {

	if ((yPos + 3) >= 7) {
		return 0;
	}
	if (((boardGame[xPos][yPos] == 'X') && (boardGame[xPos][yPos+1] == 'X') && (boardGame[xPos][yPos+2] == 'X') && (boardGame[xPos][yPos+3] == 'X')) ||
		((boardGame[xPos][yPos] == 'O') && (boardGame[xPos][yPos+1] == 'O') && (boardGame[xPos][yPos+2] == 'O') && (boardGame[xPos][yPos+3] == 'O'))) {
			return 1;
		}
	return 0;
}

int checkHori(int xPos, int yPos, char boardGame[][7]) {

	if ((xPos + 3) >= 5) {
		return 0;
	}
	if (((boardGame[xPos][yPos] == 'X') && (boardGame[xPos+1][yPos] == 'X') && (boardGame[xPos+2][yPos] == 'X') && (boardGame[xPos+3][yPos] == 'X')) ||
		((boardGame[xPos][yPos] == 'O') && (boardGame[xPos+1][yPos] == 'O') && (boardGame[xPos+2][yPos] == 'O') && (boardGame[xPos+3][yPos] == 'O'))) {
			return 1;
		}
	return 0;
}

int checkDDiag(int xPos, int yPos, char boardGame[][7]) {

	if (((xPos + 3) >= 5) || ((yPos + 3) >= 7)) {
		return 0;
	}
	if (((boardGame[xPos][yPos] == 'X') && (boardGame[xPos+1][yPos+1] == 'X') && (boardGame[xPos+2][yPos+2] == 'X') && (boardGame[xPos+3][yPos+3] == 'X')) ||
		((boardGame[xPos][yPos] == 'O') && (boardGame[xPos+1][yPos+1] == 'O') && (boardGame[xPos+2][yPos+2] == 'O') && (boardGame[xPos+3][yPos+3] == 'O'))) {
			return 1;
		}
	return 0;
}
	
int checkUDiag(int xPos, int yPos, char boardGame[][7]) {

	if (((xPos + 3) >= 5 ) || ((yPos - 3) < 0)) {
		return 0;
	}
	if (((boardGame[xPos][yPos] == 'X') && (boardGame[xPos+1][yPos-1] == 'X') && (boardGame[xPos+2][yPos-2] == 'X') && (boardGame[xPos+3][yPos-3] == 'X')) ||
		((boardGame[xPos][yPos] == 'O') && (boardGame[xPos+1][yPos-1] == 'O') && (boardGame[xPos+2][yPos-2] == 'O') && (boardGame[xPos+3][yPos-3] == 'O'))) {
			return 1;
		}
	return 0;
}


int arrayCheck(char boardGame[][7]) {

	int i = 0;
	int j = 0;
	
	while (i < 5) {
		while (j < 7) {
			if (boardGame[i][j] != '\0') {
				if ((checkHori(i, j, boardGame)) || (checkVert(i, j, boardGame)) || (checkUDiag(i ,j, boardGame)) || (checkDDiag(i ,j, boardGame))) {
					return 1;
				}
			}
		j += 1;
		}
	j = 0;
	i += 1;
	}
	return 0;
}

