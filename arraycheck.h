#ifndef ARRAYCHECK_H
#define ARRAYCHECK_H
#include "system.h"

int arrayCheck(char boardGame[5][7]);

int checkUDiag(int xPos, int yPos, char boardGame[][7]);

int checkDDiag(int xPos, int yPos, char boardGame[][7]);

int checkHori(int xPos, int yPos, char boardGame[][7]);

int checkVert(int xPos, int yPos, char boardGame[][7]);


#endif /* ARRAYCHECK_H  */
