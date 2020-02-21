#include <stdio.h>
#include <stdlib.h>

#define N_MATRIX 10 // tamanho da matriz
#define N_BOATS 5	// numero de barcos

// em ifs 0 = false, 1 = true

int const boat_size[] = {2,3,4,4,5}; // o tamanho dos navios e quantidade

typedef struct {
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

int insert_boat(MAP* map,int boat_num,int x,int y, int dir){
	if(x<0 || y<0 || x>=N_MATRIX || y>=N_MATRIX || dir<0 || dir>1) return 0;
	
	// dir = 0 -> vertical
	// dir = 1 -> horizontal
	if(dir){	// horizontal
		if(boat_size[boat_num] + y >= N_MATRIX) return 0;
		for(int k=y; k<boat_size[boat_num]+y; k++){
			if(map -> matrix[x][k] != 0) return 0;
		}
		for(int k=y; k<boat_size[boat_num]+y; k++){
			map -> matrix[x][k] = 1;
		}
	}
	else {	// vertical
		if(boat_size[boat_num] + x >= N_MATRIX) return 0;
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
		case 0 : return '-';
		case 1 : return '#';
		default: return -1;
	}
}

void print_matrix(MAP* map){
	printf("  ");
	for(int i=0; i<N_MATRIX; i++){
		printf(" %d",i);
	}
	printf("\n");

	for(int i=0; i<N_MATRIX; i++){
		printf(" %d", i);
		for(int j=0; j<N_MATRIX; j++){
			int temp = map -> matrix[i][j];
			printf(" %c",select_char(temp));
		}
		printf("\n");
	}
}

int main(int argc, char** argv){
	MAP* player1 = (MAP*)build_matrix(); //construir mapa do jogador
	insert_boat(player1,0,2,3,1);
	insert_boat(player1,4,6,4,0);
	print_matrix(player1);
}
