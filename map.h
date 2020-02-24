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
