#ifndef UTILS
#define UTILS

void flushInput();
int getRandomNumber(int,int);
bool containsBoat(Board*,int,int);
bool isAvailablePosition(Board*,char,Coords*);
void insertBoat(Board*,char,Coords*);
void randomlyPlaceBoatonBoard(Board*);

#endif
