#include <stdio.h>
#include <stdlib.h>
#define N_MATRIX 10 // tamanho da matriz
#define N_BOATS 5	// numero de barcos

int const boat_size[] = {2,3,4,4,5};

typedef struct map{
	int matrix[N_MATRIX][N_MATRIX]; 
} MAP;

MAP* build_matrix(){
	MAP* map = (MAP*)malloc(sizeof(MAP)); //mapa jogador 
	for(int i = 0; i < N_MATRIX; i++){
		for(int j = 0; j < N_MATRIX; j++){
			map -> matrix[i][j] = 0;
		}
	}

	return map;
}


int main(int argc, char** argv){
	MAP* player1 = (MAP*)build_matrix(); //construir mapa do jogador
	
}
