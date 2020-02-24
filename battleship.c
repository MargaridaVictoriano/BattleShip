#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const boat_size[] = {2,3,3,4,5}; // o tamanho dos navios e quantidade

#include "map.h"

#define N_MATRIX  10   // tamanho da matriz
#define N_BOATS   5	  // numero de barcos
#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

// em ifs 0 = false, 1 = true

/* Boat type   symbol   size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		3
	Submarine	s 			3
	Destroyer   d 			2
*/ 

/*
// falta definir relaçao com as restantes funçoes. Temos que tomar uma decisao.
typedef enum {
	CARRIER_S    = 5, 
	BATTLESHIP_S = 4,
	CRUISER_S    = 3, 
	SUBMARINE_S  = 3,
	DESTROYER_S  = 2
} ShipeSize;


//Struct para embarcações
typedef struct ship {
	char symbol;
	unsigned int length;
	char *name;
} SHIP;

//Struct para as coordenadas
typedef struct {
	int row; 	//linha
	int column; //colunas
} COORDINATES;

//Struct que define cada célula 1*1 (estou a tentar uma coisa)
typedef struct {
	//char symbol ????
	COORDINATES position;
} CELLS;

//Localização do barco
typedef struct {
    char id;
    int row;
    int column;
    int direction;
} BOATPOSITION;
*/

/*
BOATPOSITION placeShip(int row, int column, char id, int direction){
	BOATPOSITION new;
	new.row = row;
	new.column = column;
	new.direction = direction;
	new.id = id;
	return new;
}

void randomlyShipsonMap(CELLS build_matrix[][N_MATRIX], SHIP ship[]) {
	COORDINATES position;
	int direction = -1;
	int i = 0;
	for (i = 0; i < N_BOATS; i++) {
		while (1) {
			direction = getRandomNumber (0, 1); // 0 : horizontal, 1 : vertical 
			//position = generatePosition (direction, ship[i].length);
			//Criar funçao para verificar se a posiçao existe e se nao esta ocupada
			//if (isValidLocation (gameBoard, position, direction, ship[i].length)) break;
		}
		insert_boat(map, ship[i], position, direction);
	}
}
*/

// ASSUMINDO QUE A <= B
int generateRandomNumber(int a, int b){
	return (rand() % (b-a+1)) + a; 
}

//put ship on the map
void pickBoatPosition(){
	printf("Boats Available and ID: \n");
	printf("CARRIER       'c'\n");
	printf("BATTLESHIP    'b'\n");
	printf("CRUISER       'r'\n");
	printf("SUBMARINE     's'\n");
	printf("DESTROYER     'd'\n");
	printf("\n");


}

void Battlesip(){
	printf ("@@@@@   @@@@  @@@@@@ @@@@@@ @@     @@@@@@  @@@@@ @@  @@ @@ @@@@\n");
	printf ("@@  @@ @@  @@   @@     @@   @@     @@     @@     @@  @@ @@ @@  @@\n");
	printf ("@@@@@  @@  @@   @@     @@   @@     @@@@    @@@@  @@@@@@ @@ @@@@\n"); 
	printf ("@@  @@ @@@@@@   @@     @@   @@     @@         @@ @@  @@ @@ @@\n");
	printf ("@@@@@  @@  @@   @@     @@   @@@@@@ @@@@@@ @@@@@  @@  @@ @@ @@\n");
	printf("\n");

	/* ***************************************************************************
	|                                                                             |
	|																			  |
	|																			  |
	|						Pretty screen with rules							  |
	|																			  |
	|																			  |
	|																			  | 
	|																			  |
	|*****************************************************************************
	*/
}

int main(int argc, char** argv){
   srand(time(NULL)); // randomize seed
   
	MAP* player1 = (MAP*)build_matrix(N_MATRIX); //inicializar mapa do jogador
	
	system("clear");
	Battlesip();
	pickBoatPosition();
	
	insert_boat(player1,0,2,3,1);
	//insert_boat(player1,4,6,4,0);
	
	print_matrix(player1);
	
	destroy_matrix(player1);
}
