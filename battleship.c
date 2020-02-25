#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "boat.h"

#define N_MATRIX  10   // tamanho da matriz
#define N_BOATS   5	  // numero de barcos

/////// começar a pensar como armazenar os boats(um array de boats e suficente) 
/////// tem code la em baixo por acabar

// em ifs 0 = false, 1 = true

int contains_boat(MAP* map,int x,int y){
   if(map -> matrix[x][y] == 1) return 1;
   return 0;
}

// int insert_boat(Map, ship, coord, dir)

BOAT insert_boat(MAP* map,char boat_id ,BOATPOSITION position){
	int size_boat = boat_size(boat_id);
	int x = position.position.row;
	int y = position.position.column;
	int dir = position.direction;
	
	if(dir){	// horizontal
		for(int k=y; k<size_boat+y; k++){
			map -> matrix[x][k] = 1;
		}
	}
	else {	// vertical
		for(int k=x; k<size_boat+x; k++){
			map -> matrix[k][y] = 1;
		}
	}
	return build_boat(boat_id,position);
}

int checkAvalablePosition(MAP* map,char boat_id ,BOATPOSITION position){
	int size_boat = boat_size(boat_id);
	int x = position.position.row;
	int y = position.position.column;
	int dir = position.direction;
   
   if(x<0 || y<0 || x>=map->size || y>=map->size || dir<0 || dir>1) return 0;
   
   if(dir){	// horizontal
		if(size_boat + y >= map->size) return 0;
		for(int k=y; k<size_boat+y; k++){
			if(map -> matrix[x][k] != 0) return 0;
		}
	}
	else {	// vertical
		if(size_boat + x >= map->size) return 0;
		for(int k=x; k<size_boat+x; k++){
			if(map -> matrix[k][y] != 0) return 0;
		}
	}
   return 1;
}

// ASSUMINDO QUE A <= B
int getRandomNumber(int a, int b){
	return (rand() % (b-a+1)) + a; 
}

void randomlyPlaceBoatonMap(MAP* map) {
	BOATPOSITION boat_pos;
	char boat_id[] = {'c', 'b','r', 's','d'};
	for (int i = 0; i < N_BOATS; i++) {
		do {
			boat_pos.direction = getRandomNumber(0, 1); // 0 : horizontal, 1 : vertical 
			boat_pos.position.row = getRandomNumber(0,N_MATRIX-1);
			boat_pos.position.column = getRandomNumber(0,N_MATRIX-1);
		}
		while(!checkAvalablePosition(map, boat_id[i],boat_pos));
	   insert_boat(map, boat_id[i],boat_pos);
	}
}

void pickBoatPosition(MAP* map){
	BOATPOSITION boat_pos;
	char boat_id;
	printf("Boats Available and ID: \n");
	printf("CARRIER       'c'\n");
	printf("BATTLESHIP    'b'\n");
	printf("CRUISER       'r'\n");
	printf("SUBMARINE     's'\n");
	printf("DESTROYER     'd'\n");
	printf("\n");
	
	while(1){
	   printf("Please enter the desired boat ID: \n");
	   boat_id = getchar();
	   while(getchar() != '\n'); // flush buffer input
	   if(boat_id == 'c' || boat_id == 'b' || boat_id == 'r' || boat_id == 's' || boat_id == 'd') break;
		printf("Invalid input. Please try again.\n");
	}
	
	////////////////////////// falta acabar daqui para baixo ////////////////////////
	//printf("%c\n", boat_id);
	printf("Please enter the desired coordinates for the boat: \n");
	printf("Coordinate X:\n");
	scanf("%d",&boat_pos.position.row);
	//printf("%d\n", boat_pos.position.row);
	printf("Coordinate Y:\n");
	scanf("%d",&boat_pos.position.column);
	printf("%d\n", boat_pos.position.column);



}

void preparePlayerBoats(MAP* map){
   char mode;
   while(1) {
      printf("Select manual position of boats or automaticaly\n");
      printf("r -> ramdom\n");
      printf("m -> manual\n");
      printf("Select mode:\n");
      mode = getchar();
      while(getchar() != '\n'); // flush buffer input
      if(mode=='r' || mode=='m') break;
      printf("Invalid input. Please try again.\n");
   }
   
   if(mode == 'r') randomlyPlaceBoatonMap(map);
   else pickBoatPosition(map);
}

void Battleship(){
	printf ("@@@@@   @@@@  @@@@@@ @@@@@@ @@     @@@@@@  @@@@@ @@  @@ @@ @@@@\n");
	printf ("@@  @@ @@  @@   @@     @@   @@     @@     @@     @@  @@ @@ @@  @@\n");
	printf ("@@@@@  @@  @@   @@     @@   @@     @@@@    @@@@  @@@@@@ @@ @@@@\n"); 
	printf ("@@  @@ @@@@@@   @@     @@   @@     @@         @@ @@  @@ @@ @@\n");
	printf ("@@@@@  @@  @@   @@     @@   @@@@@@ @@@@@@ @@@@@  @@  @@ @@ @@\n");
	printf("\n");

	/**********************************************************|
	|                                                          |
	|																			  |
	|																			  |
	|						Pretty screen with rules					  |
	|																			  |
	|																			  |
	|																			  | 
	|																			  |
	|**********************************************************/
}

int main(int argc, char** argv){
   srand(time(NULL)); // randomize seed
   
	MAP* player1 = (MAP*)build_matrix(N_MATRIX); //inicializar mapa do jogador
	
	system("clear");
	Battleship();
	preparePlayerBoats(player1);
	
	print_matrix(player1);
	
	destroy_matrix(player1);
}

