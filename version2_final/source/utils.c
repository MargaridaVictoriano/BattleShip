#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "global_var.h"
#include "coords.h"
#include "boat.h"
#include "board.h"
#include "utils.h"

void flushInput() {
    for(int c; (c = getchar()) != '\n' && c != EOF ;);
}

// ASSUMINDO QUE A <= B
int getRandomNumber(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

//Verificar se contem barco
bool containsBoat(Board* board, int x, int y) {
    if(board -> map[x*n_matrix + y].ship != NULL) return true;
    return false;
}

bool isAvailablePosition(Board* board, char boat_id, Coords* coords) {
    int x = coords -> row;
    int y = coords -> column;
    int rotation = coords -> rotation;
    
    if (x < 0 || y < 0 || x >= n_matrix || y >= n_matrix || rotation < 0 || rotation > 360 || rotation%90 != 0) return false;
    if (boat_id == 'l') {
        if (MAX_AREA + x > n_matrix || MAX_AREA + y > n_matrix) return false;
        Boat* temp = buildBoat(boat_id,coords);
        for(int i = 0 ; i < MAX_AREA; i++) {
            for(int j = 0; j < MAX_AREA; j++) {
                if(temp -> ship[i*MAX_AREA + j] == 1) {
                    if(i+x < 0 || j+y < 0 || i+x >= n_matrix || j+y >= n_matrix || containsBoat(board,i+x,j+y)) {
                        destroyBoatTemp(temp);
                        return false;
                    }
                }
            }
        }
        destroyBoatTemp(temp);
        return true;
    }
    else {
        int boatSize = sizeBoat(boat_id);
        if(coords->rotation % 180 == 0) { //Horizontal
            if (boatSize + y >= n_matrix) return false;
            for(int k = y; k < boatSize + y; k++) {
                if(containsBoat(board,x,k)) return false;
            }
        }
        else { //Vertical
            if(boatSize + x >= n_matrix) return false;
            for(int k = x; k < boatSize + x; k++) {
                if(containsBoat(board,k,y)) return false;
            }

        }
        return true;
    }
}

void insertBoat(Board* board, char boat_id, Coords* coords) {
    int x = coords -> row;
    int y = coords -> column;
    
    Boat* temp = buildBoat(boat_id,coords);
    board -> boats[board -> size_boats] = temp;
    board -> size_boats++;
    
    if(boat_id == 'l') {
        for(int i = 0 ; i < MAX_AREA ; i++) {
            for(int j = 0; j < MAX_AREA; j++) {
                if(temp -> ship[i*MAX_AREA + j] == 1) {
                    board -> map[(i+x) * n_matrix + (j+y)].state = 1;
                    board -> map[(i+x) * n_matrix + (j+y)].ship = temp;
                }
            }
        }
    }
    else {
        int boatSize = temp -> hp;
        if(coords->rotation % 180 == 0) { //Horizontal
            for(int k = y; k < boatSize + y; k++) {
                board -> map[x * n_matrix + k].state = 1;
                board -> map[x * n_matrix + k].ship = temp;
            }
        }
        else { //Vertical
            for(int k = x; k < boatSize + x; k++) {
                board -> map[k * n_matrix + y].state = 1;
                board -> map[k * n_matrix + y].ship = temp;
            }

        }
    }
}

void randomlyPlaceBoatonBoard(Board* board) { 
    for (int i = 0; i < n_boats; i++) {
        char id = listBoat[i];
        int x,y,rot,n = boat_number[i];
        while(n > 0){
    	    if(id == 'l'){
    	    	x = getRandomNumber(0, n_matrix-5);
    	    	y = getRandomNumber(0, n_matrix-5);
    	    }
    	    else {
    	    	x = getRandomNumber(0, n_matrix-1);
    	    	y = getRandomNumber(0, n_matrix-1);
    	    }
    	    rot = getRandomNumber(0, 3)*90;
    	    
    	    Coords* coords = buildCoords(x,y,rot);
    	    if (isAvailablePosition(board, id, coords)) {
    	    	insertBoat(board, id, coords);
    	    	n--;
    	    }
	        else destroyCoords(coords);
        }
    }
}
