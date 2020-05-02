#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "global_var.h"
#include "coords.h"
#include "boat.h"
#include "board.h"
#include "utils.h"

/**
 * Function name : flushInput()
 * Usage         : flushInput();
 * Definition    : This function flushes the standard input.
 */

void flushInput() {
    for(int c; (c = getchar()) != '\n' && c != EOF ;);
}

/**
 * Function name : getRandomNumber()
 * Usage         : getRandomNumber(int,int);
 * Definition    : This function returns a random number between and including the lowest to the highest number.
 */

int getRandomNumber(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}
