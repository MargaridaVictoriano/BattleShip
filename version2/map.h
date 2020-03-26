// -------- Estrutura do Cell ------- //
// Limites da matriz
#define MIN_MATRIX 20
#define MAX_MATRIX 40

//Matriz n*n
typedef struct {
	Cell **map;
} Map;

Map *buildMap(){
	Map *new = (Map *)malloc(sizeof(Map)); //mapa jogador 
	
	// construir a matrix
	new -> map = (Cell **)malloc(n_matrix*sizeof(Cell *));
	for(int i=0; i<n_matrix; i++){
	   new -> map[i] = (Cell *)malloc(n_matrix*sizeof(Cell));
	}
	
	// zerar a matrix
	for(int i = 0; i <n_matrix; i++){
		for(int j = 0; j <n_matrix; j++){
			new -> map[i][j] = NULL;
		}
	}
	return new;
}

void destroyMap(Map* map){
    for(int i=0; i<n_matrix; i++){
 	   for(int j=0; j<n_matrix; j++){
 		  	free(map -> map[i][j]);
 	   }
 	   free(map -> map[i]);
    }
    free(map -> map);
	free(map);
}

/*
char selectChar(int v){
	switch(v){
		case 0 : return '~';
		case 1 : return '#';
		case 2 : return 'X';
		case 3 : return 'O';
		default: return -1;
	}
}

void printCell(Cell* cell){
	int digits = 1,temp = n_matrix;
	while(temp/10 != 0){
		digits++;
		temp /= 10;
	}

	for(int i = 0; i < digits + 1; i++){
		printf(" ");
	}
	for(int i=0; i<n_matrix; i++){
		printf(" %*d",digits,i);
	}
	printf("\n");

	for(int i=0; i<n_matrix; i++){
		printf(" %*d",digits,i);
		for(int j=0; j<n_matrix; j++){
			int temp = cell -> map[i][j];
			for(int i = 0; i < digits; i++){
				printf(" ");
			}
			printf("%c",selectChar(temp));
		}
		printf("\n");
	}
}*/
