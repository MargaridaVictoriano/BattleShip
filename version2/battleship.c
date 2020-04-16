// gcc -Wall battleship.c -o battleship && ./battleship && rm battleship

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#include "global_var.h"
#include "coords.h"
#include "boat.h"
#include "board.h"
#include "utils.h"

// resolver os .h, func statics and makefile
// melhorar intereçao i/o
// testar se os mallocs retornam null
void Battleship() {
    printf("@@@@@   @@@@  @@@@@@ @@@@@@ @@     @@@@@@  @@@@@ @@  @@ @@ @@@@  \n");
    printf("@@  @@ @@  @@   @@     @@   @@     @@     @@     @@  @@ @@ @@  @@\n");
    printf("@@@@@  @@  @@   @@     @@   @@     @@@@    @@@@  @@@@@@ @@ @@@@  \n");
    printf("@@  @@ @@@@@@   @@     @@   @@     @@         @@ @@  @@ @@ @@    \n");
    printf("@@@@@  @@  @@   @@     @@   @@@@@@ @@@@@@ @@@@@  @@  @@ @@ @@    \n");
    printf("\n");

    /**********************************************************|
    |                                                          |
    |														   |
    |										     			   |
    |				Pretty screen with rules		           |
    |										                   |
    |											               |
    |							   			                   | 
    |											               |
    |**********************************************************/
}

void pickMatrixSize() {
    printf("Please insert the matrix size.\n");
    printf("Both users will use the same matrix size.\n");
    printf("The matrix minimum size is %d and the matrix maximum size is %d.\n", MIN_MATRIX, MAX_MATRIX);
    
    while (1) {
        scanf("%d", &n_matrix);
        flushInput();
        if (n_matrix >= MIN_MATRIX && n_matrix <= MAX_MATRIX) break;
        printf("Invalid input. Please try again.\n");
    }
}

void pickNumberBoats() {
    int max_boats = (n_matrix*n_matrix)/(MAX_AREA*MAX_AREA);
    
    printf("Please insert how many boats you want from each type.\n");
    printf("The maximum number of boats is: %d.\n", max_boats);
    printf("Boats Available and ID: \n");
   	for(int i=0; i<n_boats; i++){
   		char id = listBoat[i];
   		printf("%c ",id);
   	}
   	printf("\n");
	
	while(1) {
        bool minValue = true;
		sum_boats = 0;
		for(int i=0; i<n_boats; i++){
   			scanf("%d",&boat_number[i]);
            if(boat_number[i] < 1) {
                minValue = false;
            }
   			sum_boats += boat_number[i];
   		}
   		flushInput();

		if(sum_boats <= max_boats && minValue) break;
		printf("Invalid input. Please try again.\n");
   	}
}

void pickBoatPosition(Board* map) {
    for (int i = 0; i < sum_boats;) {
    	char boat_id;
    	int x,y,rot;
    	
        printf("Available Boats and corresponding ID: \n");
    	for(int j=0; j<n_boats; j++){
    		if(boat_number[j] > 0){
    			char id = listBoat[j];
    			printf("'%c' :: %s\n",id,nameBoat(id));
    		}
    	}
        printf("\n");

        while (1) {
            printf("Please enter the desired Boat ID: \n");
            boat_id = getchar();
            flushInput();
            if(indexBoat(boat_id) != -1 && boat_number[indexBoat(boat_id)] > 0) break;
            printf("Invalid input. Please try again.\n");
        }

        printf("Please enter the desired coordinates for the boat: \n");
        printf("Coordinate X:\n");
        scanf("%d", &x);
        
        printf("Coordinate Y:\n");
        scanf("%d", &y);
        
        printf("Please Insert the desired Rotation:\n");
        printf("Only 0, 90, 180, 270 and 360 degrees is accepted\n");
        scanf("%d", &rot);
        
        flushInput();
        
        Coords *boat_pos = (Coords *)buildCoords(x,y,rot);
        if (checkAvailablePosition(map, boat_id, boat_pos)) {
            insertBoat(map, boat_id, boat_pos);
            boat_number[indexBoat(boat_id)]--;
            i++;
            printBoardDefense(map);
            printf("\n");
        }
        else {
        	destroyCoords(boat_pos);
            printf("\nInvalid input. Please try again.\n\n");
        }
    }
}

void preparePlayerBoats(Board* map) {
    char mode;
    
    printf("Select the prefered mode to insert the boats: \n");
    printf("'r' :: random\n");
    printf("'m' :: manual\n");
    
    while (1) {
        printf("Select the mode:\n");
        mode = getchar();
        flushInput();
        if (mode == 'r' || mode == 'm') break;
        printf("Invalid mode. Please try again.\n");
    }

    if (mode == 'r') randomlyPlaceBoatonBoard(map);
    else pickBoatPosition(map);
    
    printBoardDefense(map);
}

bool attack(Board* att, Board* def){
	int x, y;
	
    scanf("%d", &x);
    scanf("%d", &y);
    flushInput();
    
    if(x >= 0 && y >= 0 && x < n_matrix && y < n_matrix && att -> map[x][y].shot == 0) {
    
        if (def -> map[x][y].state == 1) {
    	    printf("HIT!\n");
            att -> map[x][y].shot = 2;
            def -> map[x][y].state = 2;
            def -> map[x][y].ship -> hp--;
            if(def -> map[x][y].ship -> hp == 0) {
                def -> remainingBoats--;
                printf("The ship %s was just destroyed !", nameBoat(def -> map[x][y].ship -> id));
            }
        }
        else {
            printf("MISS!\n");
            att -> map[x][y].shot = 1;
            def -> map[x][y].state = 3;
        }
        
        return true;
    }
    else printf("Invalid input. Please try again.\n");
    return false;
}

bool gameInterface(Board* p) {
    int mode;
    while (1) {
        printf("\n");
        printf("Select one of the following options.\n");
        printf("1 :: Defense Map\n");
        printf("2 :: Attack Map\n");
        printf("3 :: Attack !!!\n");
        scanf("%d",&mode);
        flushInput();
        if (mode >= 1 && mode <= 3) break;
        printf("Invalid mode. Please try again.\n");
    }
    switch(mode) {
        case 1: printBoardDefense(p);
            return false;
        case 2: printBoardAttack(p);
            return false;
        case 3:
            return true;
    }
    return false;
} 

void game(Board* p1, Board* p2) {
    p1 -> remainingBoats = sum_boats;
    p2 -> remainingBoats = sum_boats;
    while(p1 -> remainingBoats > 0 && p2 -> remainingBoats > 0) {
        //ataque do jogador 1
        printf("********************\n");
        printf("*     Player1      *\n");
        printf("********************\n");
        while(!gameInterface(p1));
        printf("Player1 please select the attack coordinates.\n");
        while(!attack(p1,p2));

        if(p2 -> remainingBoats == 0) break;
        sleep(3);
        system("clear");

        // ataque do jogador 2
        printf("********************\n");
        printf("*     Player2      *\n");
        printf("********************\n");
        while(!gameInterface(p2));
        printf("Player2 please select the attack coordinates.\n");
        while(!attack(p2,p1));
    }

    if (p1 -> remainingBoats == 0) printf("Player2 wins !\n");
    else printf("Player1 wins !\n");
}


// (muito opcional) gerar aleatorio para quem é o primeiro jogador
int main(int argc, char **argv) {
    srand(time(NULL)); // randomize seed

    system("clear");
    Battleship();
    
    pickMatrixSize();
    system("clear");
    
    pickNumberBoats();
    system("clear");
    
    //Board player1
    printf("********************\n");
    printf("*     Player1      *\n");
    printf("********************\n");
    Board* p1 = (Board *) buildBoard();
    preparePlayerBoats(p1);
    sleep(3);
    system("clear");
    
    //Board player2
    printf("********************\n");
    printf("*     Player2      *\n");
    printf("********************\n");
    Board* p2 = (Board *) buildBoard();
    preparePlayerBoats(p2);
    sleep(3);
    system("clear");
    
    game(p1,p2);

    free(p1);
    free(p2);
}
