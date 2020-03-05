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
	ligar as posiçoes do damage diretamente ao mapa
	alterar os barcos para ser full heap
	veficar os mallocs se dao null
	asserts
	atualizar print de numero de barcos sempre que algum é colocado
	tamanho da matriz O utilizador tem que escolher //TAMANHO MAXIMO : 40
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
		if(n_matrix >= 10 && n_matrix <= 40){
			break;
		}
		printf("Invalid input. Please try again.\n");

	}
	while(getchar() != '\n'); // flush buffer input
}

void pickNumberBoats(){
	printf("Please insert how many boats you want from each type.\n");
	printf("Boats Available and ID: \n");
	printf("CARRIER       'c'\n");
	printf("BATTLESHIP    'b'\n");
	printf("CRUISER       'r'\n");
	printf("SUBMARINE     's'\n");
	printf("DESTROYER     'd'\n");

	while(1){
		scanf("%d", &n_matrix);
		if(n_matrix >= 10 && n_matrix <= 40){
			break;
		}
		printf("Invalid input. Please try again.\n");

	}
	while(getchar() != '\n'); // flush buffer input
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
	   		while(getchar() != '\n'); // flush buffer input
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
			while(getchar() != '\n'); // flush buffer input
		}
		else{
		   while(getchar() != '\n'); // flush buffer input
	   	printf("\nInvalid input. Please try again.\n\n");
		}

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
      while(getchar() != '\n'); // flush buffer input
      if(mode=='r' || mode=='m') break;
      printf("Invalid mode. Please try again.\n");
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
	|														   |
	|										     			   |
	|				Pretty screen with rules		           |
	|														   |
	|														   |
	|														   | 
	|														   |
	|**********************************************************/
}

int main(int argc, char** argv){
   srand(time(NULL)); // randomize seed
   
   	system("clear");
	Battleship();
	pickMatrixSize();
	MAP* player1 = (MAP*)build_matrix(n_matrix); //inicializar mapa do jogador
	preparePlayerBoats(player1);
	print_matrix(player1);
	//sleep(2);
	destroy_matrix(player1);
}
