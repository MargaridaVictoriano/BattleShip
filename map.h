// -------- Estrutura do mapa ------- //
// Limites da matriz
#define MIN_MATRIX 10
#define MAX_MATRIX 40

//Matriz n*n
typedef struct map{
	unsigned int size;
	int **matrix;
} MAP;

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

char select_char(int v){
	switch(v){
		case 0 : return '~';
		case 1 : return '#';
		default: return -1;
	}
}

void print_matrix(MAP* map){
	int digits = 1,temp = map->size;
	while(temp/10 != 0){
		digits++;
		temp /= 10;
	}
	//printf("%d\n DIGITOS\n", digits);

	//printf(" ");
	for(int i = 0; i < digits + 1; i++){
		printf(" ");
	}
	for(int i=0; i<map->size; i++){
		printf(" %*d",digits,i);
	}
	printf("\n");

	for(int i=0; i<map->size; i++){
		printf(" %*d",digits,i);
		for(int j=0; j<map->size; j++){
			int temp = map -> matrix[i][j];
			for(int i = 0; i < digits; i++){
				printf(" ");
			}
			printf("%c",select_char(temp));
		}
		printf("\n");
	}
}
typedef struct {
	MAP* mapPlayer;
	MAP* mapOpponent;
} PLAYER;

//Construtor do jogador
PLAYER* buildPlayer(MAP* map) {
	PLAYER* new = (PLAYER*)malloc(sizeof(PLAYER)); 
	new -> mapPlayer = map;
	new -> mapOpponent = (MAP*)build_matrix(map -> size); 
	return new;
}

void destroyPlayer(PLAYER* player) {
	destroy_matrix(player -> mapPlayer);
	destroy_matrix(player -> mapOpponent);
	free(player);
}


//Struct que define cada célula 1*1 (estou a tentar uma coisa)
/*typedef struct {
	//char symbol ????
	COORDINATES position;
} CELLS;
*/
