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

/* ------------------------------TO DO LIST------------------------------
	- Each piece data structure besides the bitmap field, should have an additional field, e.g. shot_count, that is a counter of the number of times that a piece was hit (uniquely, 2 or more shots in the same place only count as one)
	- For each shot from the adversary you have to use the inverse of these functions to map it within the canonical (to check if it was a hit or not)
	- Define 5 different types of boats, with at least one shape being different from a rectangle or square, e.g. "T", "L".
	- Each game must have at least 1 boat of each type
	- The maximum number of boats is given by game_size / 5*5, e.g. with a game size of 20*20 = 400, max number of pieces is 400/25 = 16.
------------------------------------------------------------------------*/

//It Works !
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
    while (1) {
        printf("Select the prefered mode to insert the boats: \n");
        printf("'r' :: random\n");
        printf("'m' :: manual\n");
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

// inacabada o input seguro
// Temos que pensar como vamos mostrar a cada jogador o seu mapa de ataque.
//Guardar em duas variaveis(uma para cada jogador) o numero de "quadriculas" que cada barco ocupa. Sempre que um jogador ataca, verificamos se foi atingido algum barco e caso seja é so decrementar o valor da variavel e quando chegar a zero sabemos que perdemos
/*void game(PLAYER* player1, PLAYER* player2) {
    while (n1_size != 0 && n2_size != 0) {
        int x, y;
        // ataque do jogador 1
        printf("Player1 please select the attack coordinates.\n");
        scanf("%d", & x);
        scanf("%d", & y);
        flushInput();

        if (x >= 0 && y >= 0 && x < n_matrix && y < n_matrix &&
            player1 -> mapOpponent -> matrix[x][y] != 2 &&
            player1 -> mapOpponent -> matrix[x][y] != 3) {
            
            //player1 ataca player2
            if (player2 -> mapPlayer -> matrix[x][y] == 1) {
                printf("HIT!\n");
                player1 -> mapOpponent -> matrix[x][y] = 2;
                n1_size--;
            }
            else {
                printf("MISS!\n");
                player1 -> mapOpponent -> matrix[x][y] = 3;
            }
        }
        else printf("Invalid input. Please try again.\n");

        print_matrix(player1 -> mapOpponent);

        if (n2_size == 0) break;

        // ataque do jogador 2
        printf("Player2 please select the attack coordinates.\n");
        scanf("%d", & x);
        scanf("%d", & y);
        flushInput();

        if (x >= 0 && y >= 0 && x < n_matrix && y < n_matrix &&
            player1 -> mapOpponent -> matrix[x][y] != 2 &&
            player1 -> mapOpponent -> matrix[x][y] != 3) {
            
            //player2 ataca player1
            if (player1 -> mapPlayer -> matrix[x][y] == 1) {
                printf("HIT!\n");
                player2 -> mapOpponent -> matrix[x][y] = 2;
                n2_size--;
            }
            else {
                printf("MISS!\n");
                player2 -> mapOpponent -> matrix[x][y] = 3;
            }
        }
        else printf("Invalid input. Please try again.\n");

        print_matrix(player2 -> mapOpponent);
    }

    if (n1_size == 0) printf("Player2 wins !\n");
    else printf("Player1 wins !\n");
}*/

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
    sleep(5);
    system("clear");
    
    //Board player2
    printf("********************\n");
    printf("*     Player2      *\n");
    printf("********************\n");
    Board* p2 = (Board *) buildBoard();
    preparePlayerBoats(p2);
    sleep(5);
    system("clear");
    
    //game(player1, player2);
    
    free(p1);
    free(p2);
}
