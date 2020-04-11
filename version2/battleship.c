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

/* ------------------------------TO DO LIST------------------------------
	- Each piece data structure besides the bitmap field, should have an additional field, e.g. shot_count, that is a counter of the number of times that a piece was hit (uniquely, 2 or more shots in the same place only count as one)
	- Use the necessary functions to perform the transformations for each position (I,J). This implies that you need to do this for the initial matrix setup for all the pieces.
	- For each shot from the adversary you have to use the inverse of these functions to map it within the canonical (to check if it was a hit or not)
	- Define 5 different types of boats, with at least one shape being different from a rectangle or square, e.g. "T", "L".
	- Each game must have at least 1 boat of each type
	- The maximum number of boats is given by game_size / 5*5, e.g. with a game size of 20*20 = 400, max number of pieces is 400/25 = 16.
------------------------------------------------------------------------*/

//It Works !
/*
void pickMatrixSize() {
    printf("Please insert the matrix size.\n");
    printf("Both users will use the same matrix size.\n");
    printf("The matrix minimum size is %d and the matrix maximum size is %d.\n", MIN_MATRIX, MAX_MATRIX);
    while (1) {
        scanf("%d", & n_matrix);
        if (n_matrix >= MIN_MATRIX && n_matrix <= MAX_MATRIX) break;
        printf("Invalid input. Please try again.\n");

    }
    flushInput();
}

//need to finish
void pickNumberBoats() {
    //dependendo do tamanho da matriz temos que limitar o numero de barcos
    printf("Please insert how many boats you want from each type.\n");
    printf("Boats Available and ID: \n");
    printf("CARRIER       'c'\n");
    printf("BATTLESHIP    'b'\n");
    printf("CRUISER       'r'\n");
    printf("SUBMARINE     's'\n");
    printf("DESTROYER     'd'\n");

    while (1) {
        scanf("%d", & n_matrix);
        if (n_matrix >= MIN_MATRIX && n_matrix <= MAX_MATRIX) break;
        printf("Invalid input. Please try again.\n");

    }
    flushInput();
}

//Mudar para ter disponivel o novo barco
void pickBoatPosition(MAP* map) {
    BOATPOSITION boat_pos;
    char boat_id;
    for (int i = 0; i < n_boats; i++) {
        printf("Boats Available and ID: \n");
        printf("CARRIER       'c'\n");
        printf("BATTLESHIP    'b'\n");
        printf("CRUISER       'r'\n");
        printf("SUBMARINE     's'\n");
        printf("DESTROYER     'd'\n");
        printf("\n");

        while (1) {
            printf("Please enter the desired boat ID: \n");
            boat_id = getchar();
            flushInput();
            if (boat_id == 'c' || boat_id == 'b' || boat_id == 'r' || boat_id == 's' || boat_id == 'd') break;
            printf("Invalid input. Please try again.\n");
        }

        //printf("%c\n", boat_id);
        printf("Please enter the desired coordinates for the boat: \n");
        printf("Coordinate X:\n");
        scanf("%d", & boat_pos.position.row);
        //printf("%d\n", boat_pos.position.row);
        printf("Coordinate Y:\n");
        scanf("%d", & boat_pos.position.column);
        //printf("%d\n", boat_pos.position.column);
        printf("Please Select the Direction:\n");
        printf("1 :: Horizontal \n");
        printf("0 :: Vertical \n");
        scanf("%d", & boat_pos.direction);

        if (checkAvalablePosition(map, boat_id, boat_pos)) {
            insert_boat(map, boat_id, boat_pos);
            print_matrix(map);
            printf("\n");
        }
        else {
            printf("\nInvalid input. Please try again.\n\n");
        }

        flushInput();
    }
}

void preparePlayerBoats(MAP* map) {
    char mode;
    while (1) {
        printf("Select the prefered mode to insert the boats: \n");
        printf("r :: random\n");
        printf("m :: manual\n");
        printf("Select the mode:\n");
        mode = getchar();
        flushInput();
        if (mode == 'r' || mode == 'm') break;
        printf("Invalid mode. Please try again.\n");
    }

    if (mode == 'r') randomlyPlaceBoatonBoard(map);
    else pickBoatPosition(map);
    print_matrix(map);

}
*/
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
/*
// inacabada o input seguro
// Temos que pensar como vamos mostrar a cada jogador o seu mapa de ataque.
//Guardar em duas variaveis(uma para cada jogador) o numero de "quadriculas" que cada barco ocupa. Sempre que um jogador ataca, verificamos se foi atingido algum barco e caso seja é so decrementar o valor da variavel e quando chegar a zero sabemos que perdemos
void game(PLAYER* player1, PLAYER* player2) {
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

int main(int argc, char ** argv) {
    srand(time(NULL)); // randomize seed
	
	Board *p1 = (Board *) buildBoard(); //inicializar mapa do jogador
    
    //char boat_id[] = {'l','c','b','r','s','d'};
    
    Coords* coords;
    //coords = buildCoords(15,15,90);
    //insertBoat(p1,'l',coords);
    
    coords = buildCoords(15,15,180);
    insertBoat(p1,'c',coords);
    
    coords = buildCoords(0,0,180);
    insertBoat(p1,'c',coords);
    /*
    coords = buildCoords(0,0,90);
    insertBoat(p1,'b',coords);
    
    coords = buildCoords(0,0,90);
    insertBoat(p1,'r',coords);
    
    coords = buildCoords(0,0,90);
    insertBoat(p1,'s',coords);
    
    coords = buildCoords(0,0,90);
    insertBoat(p1,'d',coords);
    */
    //randomlyPlaceBoatonBoard(p1);
    printBoard(p1);

	
	/*Coords* ned;
	Boat* boat1;
	
	ned = (Coords *)buildCoords(7,9,0);
	boat1 = (Boat *)buildBoat('l',ned);
	printf("\n");
	printShip(boat1);
	
	ned = (Coords *)buildCoords(7,9,90);
	boat1 = (Boat *)buildBoat('l',ned);
	printf("\n");
	printShip(boat1);
	
	ned = (Coords *)buildCoords(7,9,180);
	boat1 = (Boat *)buildBoat('l',ned);
	printf("\n");
	printShip(boat1);
	
	ned = (Coords *)buildCoords(7,9,270);
	boat1 = (Boat *)buildBoat('l',ned);
	printf("\n");
	printShip(boat1);
	*/

	/*boat1 = (Boat *)buildBoat('c',ned);
	printf("\n");
	printShip(boat1);
	
	boat1 = (Boat *)buildBoat('b',ned);
	printf("\n");
	printShip(boat1);
	
	boat1 = (Boat *)buildBoat('r',ned);
	printf("\n");
	printShip(boat1);
	
	boat1 = (Boat *)buildBoat('s',ned);
	printf("\n");
	printShip(boat1);
	
	boat1 = (Boat *)buildBoat('d',ned);
	printf("\n");
	printShip(boat1);
	*/
    /*system("clear");
    Battleship();

    pickMatrixSize();

    system("clear");
    //Boarda player1
    MAP* p1 = (MAP *) build_matrix(); //inicializar mapa do jogador
    printf("********************\n");
    printf("*     Player1      *\n");
    printf("********************\n");
    preparePlayerBoats(p1);
    PLAYER* player1 = (PLAYER *) buildPlayer(p1);
    sleep(2);
    system("clear");

    //Board player2
    MAP* p2 = (MAP *) build_matrix(); //inicializar mapa do jogador
    printf("********************\n");
    printf("*     Player2      *\n");
    printf("********************\n");
    preparePlayerBoats(p2);
    PLAYER* player2 = (PLAYER *) buildPlayer(p2);
    sleep(2);
    system("clear");

    //system("clear");
    game(player1, player2);

    destroyPlayer(player1);
    destroyPlayer(player2);
    free(p1);
    free(p2);*/
}
