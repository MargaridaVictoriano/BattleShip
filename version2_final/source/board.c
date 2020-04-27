#include <stdio.h>
#include <stdlib.h>

#include "global_var.h"
#include "coords.h"
#include "boat.h"
#include "board.h"

/**
 * Function name : buildBoard()
 * Usage         : buildBoard();
 * Definition    : This function builds and initializes the game board.             
 */

Board *buildBoard(){
	Board *new = (Board *)malloc(sizeof(Board)); //players map
	if(new == NULL) exit(-1);
	
	new -> remainingBoats = 0;
	
	new -> map = (Cell *)malloc(n_matrix*n_matrix*sizeof(Cell));
	if(new -> map == NULL) exit(-1);
	
	for(int i = 0; i <n_matrix; i++){
		for(int j = 0; j <n_matrix; j++){
			new -> map[i*n_matrix + j].shot = 0;
			new -> map[i*n_matrix + j].state = 0;
			new -> map[i*n_matrix + j].ship = NULL;
		}
	}
	
	new -> size_boats = 0;
	new -> boats = (Boat **)malloc(sum_boats*sizeof(Boat *));
	if(new -> boats == NULL) exit(-1);
	
	return new;
}

/**
 * Function name : destroyBoard()
 * Usage         : destroyBoard(Board*);
 * Definition    : This function destroys the game board.             
 */

void destroyBoard(Board* map){
    free(map -> map);
	
	for(int i=0; i< map -> size_boats; i++){
		destroyBoat(map -> boats[i]);
	}
	free(map -> boats);
	
	free(map);
}

/**
 * Function name : selectCharDefense()
 * Usage         : selectCharDefense(char);
 * Definition    : Returns corresponding symbol.            
 */

char selectCharDefense(char v){
	switch(v){
		case 0 : return '~';
		case 1 : return '#';
		case 2 : return 'X';
		case 3 : return 'O';
		default: return -1;
	}
}

/**
 * Function name : selectCharAttack()
 * Usage         : selectCharAttack(char);
 * Definition    : Returns corresponding symbol.            
 */

char selectCharAttack(char v){
	switch(v){
		case 0 : return '~';
		case 1 : return 'O';
		case 2 : return 'X';
		default: return -1;
	}
}

/**
 * Function name : printDefenseBoard()
 * Usage         : printDefenseBoard(Board*);
 * Definition    : This function displays the defense map.            
 */

void printDefenseBoard(Board* map){
	printf("   ");
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
	}
	printf("\n");
	
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
		for(int j=0; j<n_matrix; j++){
			int temp = map -> map[i*n_matrix + j].state;
			printf("  %c",selectCharDefense(temp));
		}
		printf("\n");
	}
}

/**
 * Function name : printAttackBoard()
 * Usage         : printAttackBoard(Board*);
 * Definition    : This function displays the attack map.            
 */

void printAttackBoard(Board* map) {
	printf("   ");
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
	}
	printf("\n");
	
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
		for(int j=0; j<n_matrix; j++){
			int temp = map -> map[i*n_matrix + j].shot;
			printf("  %c",selectCharAttack(temp));
		}
		printf("\n");
	}
}
