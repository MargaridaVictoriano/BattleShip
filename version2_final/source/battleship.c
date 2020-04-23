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

void showRules() {
    printf(".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*:.*~*:._.:*~*:.\n");
    printf("                                                                RULES                                                                            \n");
    printf(".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*:.*~*:._.:*~*:.\n");
    printf("\n");
    printf("1. This is a two player game.\n");
    printf("2. You will be prompted to insert the maximum board size.\n");
    printf("  Please keep in mind that both players must play with boards of equal size\n");
    printf("  so you will only be prompted once to input the size which cannot be changed throughout the game.\n");
    printf("3. You will be prompted to insert how many boats you want from each type.\n");
    printf("  Please keep in mind that both players must play with the same number of boats\n");
    printf("  so you will only be prompted once to input the number of boats which cannot be changed throughout the game.\n");
    printf("  You must choose atleast one boat of each type.\n");
    printf("4. Players will be prompted to choose how to place the boats on the map: randomly or manually.\n");
    printf("  4.1. Random Mode:\n");
    printf("       .:Players will see the map with the boats randomly placed for a few seconds.\n");
    printf("  4.2. Manual Mode:\n");
    printf("       .:Players will enter the desired boat ID and then they will be prompted to choose the: \n");
    printf("       .:X coordinates\n");
    printf("       .:Y coordinates\n");
    printf("       .:Rotation : 0,90,270,360 degrees\n");
    printf("until all boats are placed.\n");
    printf("5. When the game begins the players take turns attacking each other and they can view their own map and their attack map whenever they want.\n");
    printf("6. The first player to guess the location of all ships wins!\n\n");
    printf(".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*:.*~*:._.:*~*:.\n");
    printf(".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*._.:*~*:._.:*~*:._.:*~*:.*~*:._.:*~*:.\n");
    printf("\n");

	printf("Press any key to continue.\n\n");
	
	flushInput();
	
    system("clear");
}

void Battleship() {
    printf("@@@@@   @@@@  @@@@@@ @@@@@@ @@     @@@@@@  @@@@@ @@  @@ @@ @@@@  \n");
    printf("@@  @@ @@  @@   @@     @@   @@     @@     @@     @@  @@ @@ @@  @@\n");
    printf("@@@@@  @@  @@   @@     @@   @@     @@@@    @@@@  @@@@@@ @@ @@@@  \n");
    printf("@@  @@ @@@@@@   @@     @@   @@     @@         @@ @@  @@ @@ @@    \n");
    printf("@@@@@  @@  @@   @@     @@   @@@@@@ @@@@@@ @@@@@  @@  @@ @@ @@    \n");
    printf("\n");
    int mode;
    while (1) {
        printf("\n");
        printf("Select one of the following options.\n");
        printf("1 :: Start\n");
        printf("2 :: Rules\n");
        printf("3 :: Quit\n");
        scanf("%d",&mode);
        flushInput();
        if (mode >= 1 && mode <= 3) break;
        printf("Invalid mode. Please try again.\n");
    }
    switch(mode) {
        case 2: showRules();
            return;
        case 3:
            exit(0);
        case 1:
        default: return;
    }

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
        if (isAvailablePosition(map, boat_id, boat_pos)) {
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

void preparePlayerBoat(Board* map) {
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
            setShip(def -> map[x][y].ship,2, x, y);
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
    preparePlayerBoat(p1);
    sleep(3);
    system("clear");
    
    //Board player2
    printf("********************\n");
    printf("*     Player2      *\n");
    printf("********************\n");
    Board* p2 = (Board *) buildBoard();
    preparePlayerBoat(p2);
    sleep(3);
    system("clear");
    
    game(p1,p2);
    
    destroyBoard(p1);
    destroyBoard(p2);
}
