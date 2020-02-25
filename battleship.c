#include <stdio.h>
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

MAP* build_matrix(unsigned int len){
	MAP* map = (MAP*)malloc(sizeof(MAP)); //mapa jogador 
	map->size = len;
	
	// construir a matrix
	map -> matrix = (int **)malloc(map->size*sizeof(int *));
	for(int i=0; i<map->size; i++){
	   map -> matrix[i] = (int *)malloc(map->size*sizeof(int));
	}
	
	// zerar a matrix
	for(int i = 0; i < map->size; i++){
		for(int j = 0; j < map->size; j++){
			map -> matrix[i][j] = 0;
		}
	}
	return map;
}

void destroy_matrix(MAP* map){
   if(map != NULL){
      for(int i=0; i< map->size; i++){
         free(map -> matrix[i]);
      }
      free(map -> matrix);
      free(map);
   }
}

int contains_boat(MAP* map,int x,int y){
   if(map -> matrix[x][y] == 1) return 1;
   return 0;
}

// int insert_boat(Map, ship, coord, dir)

int insert_boat(MAP* map,int boat_num,int x,int y, int dir){
	if(x<0 || y<0 || x>=map->size || y>=map->size || dir<0 || dir>1) return 0;
	
	// dir = 0 -> vertical
	// dir = 1 -> horizontal
	if(dir){	// horizontal
		if(boat_size[boat_num] + y >= map->size) return 0;
		for(int k=y; k<boat_size[boat_num]+y; k++){
			if(map -> matrix[x][k] != 0) return 0;
		}
		for(int k=y; k<boat_size[boat_num]+y; k++){
			map -> matrix[x][k] = 1;
		}
	}
	else {	// vertical
		if(boat_size[boat_num] + x >= map->size) return 0;
		for(int k=x; k<boat_size[boat_num]+x; k++){
			if(map -> matrix[k][y] != 0) return 0;
		}
		for(int k=x; k<boat_size[boat_num]+x; k++){
			map -> matrix[k][y] = 1;
		}
	}
	return 1;
}

char select_char(int v){
	switch(v){
		case 0 : return '~';
		case 1 : return '#';
		default: return -1;
	}
}

void print_matrix(MAP* map){
	printf("  ");
	for(int i=0; i<map->size; i++){
		printf(" %d",i);
	}
	printf("\n");

	for(int i=0; i<map->size; i++){
		printf(" %d", i);
		for(int j=0; j<map->size; j++){
			int temp = map -> matrix[i][j];
			printf(" %c",select_char(temp));
		}
		printf("\n");
	}
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
