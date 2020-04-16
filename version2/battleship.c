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

// printas tambem o numero maximo de barcos
// usando a variavel max_boats
// forcada jogo a ter no minimo um por cada tipo de barco
void pickNumberBoats() {
    int max_boats = (n_matrix*n_matrix)/(MAX_AREA*MAX_AREA);
    
    printf("Please insert how many boats you want from each type.\n");
    printf("Boats Available and ID: \n");
   	for(int i=0; i<n_boats; i++){
   		char id = listBoat[i];
   		printf("%c ",id);
   	}
   	printf("\n");
	
	while(1) {
		sum_boats = 0;
		for(int i=0; i<n_boats; i++){
   			scanf("%d",&boat_number[i]);
   			sum_boats += boat_number[i];
   		}
   		flushInput();
		if(sum_boats <= max_boats) break;
		printf("Invalid input. Please try again.\n");
   	}
}

// margarida verifica as strings pls
// desambiguar o x e y por linha e coluna
void pickBoatPosition(Board* map) {
    for (int i = 0; i < sum_boats;) {
    	char boat_id;
    	int x,y,rot;
    	
        printf("Boats Available and ID: \n");
    	for(int j=0; j<n_boats; j++){
    		if(boat_number[j] > 0){
    			char id = listBoat[j];
    			printf("'%c' :: %s\n",id,nameBoat(id));
    		}
    	}
        printf("\n");

        while (1) {
            printf("Please enter the desired boat ID: \n");
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
        
        printf("Please Select the Rotation:\n");
        printf("Only 0º, 90º, 180º, 270º and 360º was accepted\n");
        scanf("%d", &rot);
        
        flushInput();
        
        Coords *boat_pos = (Coords *)buildCoords(x,y,rot);
        if (checkAvailablePosition(map, boat_id, boat_pos)) {
            insertBoat(map, boat_id, boat_pos);
            boat_number[indexBoat(boat_id)]--;
            i++;
            printBoard(map);
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
    
    printBoard(map);
}

// falta acrescentar a intereçao com os boats de forma a saber quando cada um e destruido
// e saber quando o jogo termina usando a var damage dos boats
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

// caso de paragem por resolver
// dependencia de resolver o attack para saber quando os barcos sao tds destruidos
// falta resolver o print dos mapas locais e inimigos
void game(Board* p1, Board* p2) {
    while (1) {
        // ataque do jogador 1
        printf("Player1 please select the attack coordinates.\n");
        while(!attack(p1,p2));

        // resolver os prints das matrizes locais e adversarias
        //print_matrix(p1);

        //if (n2_size == 0) break;

        // ataque do jogador 2
        printf("Player2 please select the attack coordinates.\n");
        while(!attack(p2,p1));
        
        // resolver os prints das matrizes locais e adversarias
        //print_matrix(p2);
    }

    //if (n1_size == 0) printf("Player2 wins !\n");
    //else printf("Player1 wins !\n");
}

// gerar aleatorio para quem é o primeiro jogador
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
