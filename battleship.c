// gcc -Werror battleship.c -o battleship && ./battleship && rm battleship

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "global_var.h"
#include "map.h"
#include "boat.h"
#include "utils.h"


/* -------------------------------------------------------TO DO LIST---------------------------------------------------
	array para guardar barcos
	ligar as posiçoes do damage diretamente ao mapa
	alterar os barcos para ser full heap
	veficar os mallocs se dao null
	asserts
	atualizar print de numero de barcos sempre que algum é colocado
	começar a pensar como armazenar os boats(um array de boats e suficente) 
	random para determinar numero de barcos
	random para determinar tamanho da matriz
	minimos e maximos de barcos consoante tamanho da matriz
	tem code la em baixo por acabar
-------------------------------------------------------------------------------------------------------------------------*/

//It Works !
void pickMatrixSize(){
	printf("Please insert the matrix size.\n");
	printf("Both users will use the same matrix size.\n");
	printf("The matrix minimum size is %d and the matrix maximum size is %d.\n",MIN_MATRIX ,MAX_MATRIX);
	while(1){
		scanf("%d", &n_matrix);
		if(n_matrix >= MIN_MATRIX && n_matrix <= MAX_MATRIX){
			break;
		}
		printf("Invalid input. Please try again.\n");

	}
	flushInput();
}
//need to finish
void pickNumberBoats(){
	//dependendo do tamanho da matriz temos que limitar o numero de barcos
	printf("Please insert how many boats you want from each type.\n");
	printf("Boats Available and ID: \n");
	printf("CARRIER       'c'\n");
	printf("BATTLESHIP    'b'\n");
	printf("CRUISER       'r'\n");
	printf("SUBMARINE     's'\n");
	printf("DESTROYER     'd'\n");

	while(1){
		scanf("%d", &n_matrix);
		if(n_matrix >= MIN_MATRIX && n_matrix <= MAX_MATRIX){
			break;
		}
		printf("Invalid input. Please try again.\n");

	}
	flushInput();
}

void pickBoatPosition(MAP* map){
	BOATPOSITION boat_pos;
	char boat_id;
	for(int i = 0; i < n_boats; i++){
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
	   		flushInput();
	   		if(boat_id == 'c' || boat_id == 'b' || boat_id == 'r' || boat_id == 's' || boat_id == 'd') break;
	   		printf("Invalid input. Please try again.\n");
		}
	
		//printf("%c\n", boat_id);
		printf("Please enter the desired coordinates for the boat: \n");
		printf("Coordinate X:\n");
		scanf("%d",&boat_pos.position.row);
		//printf("%d\n", boat_pos.position.row);
		printf("Coordinate Y:\n");
		scanf("%d",&boat_pos.position.column);
		//printf("%d\n", boat_pos.position.column);
		printf("Please Select the Direction:\n");
		printf("1 :: Horizontal \n");
		printf("0 :: Vertical \n");
		scanf("%d", &boat_pos.direction);
		
		if(checkAvalablePosition(map,boat_id,boat_pos)){
			insert_boat(map,boat_id, boat_pos);
			print_matrix(map);
			printf("\n");
		}
		else{
	   	printf("\nInvalid input. Please try again.\n\n");
		}
		
		flushInput();
	}
}

void preparePlayerBoats(MAP* map){
   char mode;
   while(1) {
      printf("Select the prefered mode to insert the boats: \n");
      printf("r :: random\n");
      printf("m :: manual\n");
      printf("Select the mode:\n");
      mode = getchar();
      flushInput();
      if(mode=='r' || mode=='m') break;
      printf("Invalid mode. Please try again.\n");
   }
   
   if(mode == 'r') randomlyPlaceBoatonMap(map);
   else pickBoatPosition(map);
}

void Battleship(){
	printf ("@@@@@   @@@@  @@@@@@ @@@@@@ @@     @@@@@@  @@@@@ @@  @@ @@ @@@@  \n");
	printf ("@@  @@ @@  @@   @@     @@   @@     @@     @@     @@  @@ @@ @@  @@\n");
	printf ("@@@@@  @@  @@   @@     @@   @@     @@@@    @@@@  @@@@@@ @@ @@@@  \n"); 
	printf ("@@  @@ @@@@@@   @@     @@   @@     @@         @@ @@  @@ @@ @@    \n");
	printf ("@@@@@  @@  @@   @@     @@   @@@@@@ @@@@@@ @@@@@  @@  @@ @@ @@    \n");
	printf ("\n");

	/**********************************************************|
	|                                                          |
	|														                 |
	|										     			                 |
	|				Pretty screen with rules		                 |
	|														                 |
	|														                 |
	|														                 | 
	|														                 |
	|**********************************************************/
}

// Margarida por favor corrige estas strings tds ;-)
// Temos que pensar como vamos mostrar a cada jogador o seu mapa de ataque.
// O ciclo ainda nao sei como o fazer terminar
void game(MAP* map1, MAP* map2){
   while(1){
      int x,y;
      
      // ataque do jagador 1
      printf("Player1 select coords for attack.\n");
      scanf("%d",&x);
      scanf("%d",&y);
      flushInput();
      
      if(x>=0 && y>=0 && x<map2->size && y<map2->size){
         if(map2->matrix[x][y] == 1) printf("HIT!\n");
         else printf("MISS!\n");
      }
      else printf("Invalid input. Please try again.\n");
      
      // ataque do jagador 2
      printf("Player2 select coords for attack.\n");
      scanf("%d",&x);
      scanf("%d",&y);
      flushInput();
      
      if(x>=0 && y>=0 && x<map1->size && y<map1->size){
         if(map1->matrix[x][y] == 1) printf("HIT!\n");
         else printf("MISS!\n");
      }
      else printf("Invalid input. Please try again.\n");
   }
}

int main(int argc, char** argv){
   srand(time(NULL)); // randomize seed
   
   system("clear");
	Battleship();
	
	pickMatrixSize();
	
	system("clear");
	MAP* player1 = (MAP*)build_matrix(n_matrix); //inicializar mapa do jogador
	printf("Player1\n");
	preparePlayerBoats(player1);
	print_matrix(player1);
	
	system("clear");
	MAP* player2 = (MAP*)build_matrix(n_matrix); //inicializar mapa do jogador
	printf("Player2\n");
	preparePlayerBoats(player2);
	print_matrix(player2);
	
	system("clear");
	game(player1,player2);
	
	destroy_matrix(player1);
	destroy_matrix(player2);
}
