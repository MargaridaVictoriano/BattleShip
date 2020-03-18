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
//Mudar para ter disponivel o novo barco
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
   print_matrix(map);


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
	|														   |
	|										     			   |
	|				Pretty screen with rules		           |
	|										                   |
	|											               |
	|							   			                   | 
	|											               |
	|**********************************************************/
}

// Temos que pensar como vamos mostrar a cada jogador o seu mapa de ataque.
// O ciclo ainda nao sei como o fazer terminar
//Guardar em duas variaveis(uma para cada jogador) o numero de "quadriculas" que cada barco ocupa. Sempre que um jogador ataca, verificamos se foi atingido algum barco e caso seja é so decrementar o valor da variavel e quando chegar a zero sabemos que perdemos
void game(PLAYER* player1, PLAYER* player2) {
 
   while(n1_size != 0 && n2_size != 0) {
      int x,y;
      // ataque do jogador 1
      printf("Player1 please select the attack coordinates.\n");
      scanf("%d",&x);
      scanf("%d",&y);
      flushInput();
      
      if(x>=0 && y>=0 && x<n_matrix && y<n_matrix){
      	//player1 ataca player2
         if(player2 -> mapPlayer -> matrix[x][y] == 1) {
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

      if(n2_size == 0) {
      	break;
      }
      // ataque do jogador 2
      printf("Player2 please select the attack coordinates.\n");
      scanf("%d",&x);
      scanf("%d",&y);
      flushInput();
      
      if(x>=0 && y>=0 && x<n_matrix && y<n_matrix){
      	      	//player2 ataca player1
            if(player1 -> mapPlayer -> matrix[x][y] == 1) {
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
   if(n1_size == 0) { 
   		printf("Player2 wins !\n" );
   }
   else {
   		printf("Player1 wins !\n");
   }
}

int main(int argc, char** argv){
   srand(time(NULL)); // randomize seed
   
    system("clear");
	Battleship();
	
	pickMatrixSize();
	
	system("clear");
	//Mapa player1
	MAP* p1 = (MAP*)build_matrix(); //inicializar mapa do jogador
	printf("********************\n");
	printf("*     Player1      *\n");
	printf("********************\n");
	preparePlayerBoats(p1);
	PLAYER* player1 = (PLAYER*)buildPlayer(p1);
	sleep(2);
	system("clear");

	//Mapa player2
	MAP* p2 = (MAP*)build_matrix(); //inicializar mapa do jogador
	printf("********************\n");
	printf("*     Player2      *\n");
	printf("********************\n");
	preparePlayerBoats(p2);
	PLAYER* player2 = (PLAYER*)buildPlayer(p2);
	sleep(2);
	system("clear");
	
	//system("clear");
	game(player1,player2);
	
	destroyPlayer(player1);
	destroyPlayer(player2);
	free(p1);
	free(p2);
}
