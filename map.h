// -------- Estrutura do mapa ------- //
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

//Struct que define cada célula 1*1 (estou a tentar uma coisa)
/*typedef struct {
	//char symbol ????
	COORDINATES position;
} CELLS;
*/
