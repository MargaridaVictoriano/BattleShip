// -------- Estrutura do Cell ------- //

// Limites da matriz
#define MIN_MATRIX 20
#define MAX_MATRIX 40

typedef struct {
	// informacao adversario
	int shot;    // 0 = no shot, 1 = shot that didn't hit, 2 = shot that hit an enemy piece
	// informacao local
	int state;   // 0 = empty, 1 = piece without being hitted, 2 = piece hitted, 3 = missed shot
	Boat *ship;  // apontador para o barco local
} Cell;

//Matriz n*n
typedef struct {
	Cell **map;
	int remainingBoats;
	
	// reserva dos boats
	int size_boats;
	Boat **boats;
} Board;

Board *buildBoard(){
	Board *new = (Board *)malloc(sizeof(Board)); //mapa jogador
	if(new == NULL) exit(-1);
	
	new -> remainingBoats = 0;
	
	// construir a matrix
	new -> map = (Cell **)malloc(n_matrix*sizeof(Cell *));
	if(new -> map == NULL) exit(-1);
	
	for(int i=0; i<n_matrix; i++){
	   new -> map[i] = (Cell *)malloc(n_matrix*sizeof(Cell));
	   if(new -> map[i] == NULL) exit(-1);
	}
	
	// zerar a matrix
	for(int i = 0; i <n_matrix; i++){
		for(int j = 0; j <n_matrix; j++){
			new -> map[i][j].shot = 0;
			new -> map[i][j].state = 0;
			new -> map[i][j].ship = NULL;
		}
	}
	
	// construir a reserva dos boats
	new -> size_boats = 0;
	new -> boats = (Boat **)malloc(sum_boats*sizeof(Boat *));
	if(new -> boats == NULL) exit(-1);
	
	return new;
}

void destroyBoard(Board* map){
    for(int i=0; i<n_matrix; i++){
 	   	free(map -> map[i]);
    }
    free(map -> map);
	
	for(int i=0; i< map -> size_boats; i++){
		destroyBoat(map -> boats[i]);
	}
	free(map -> boats);
	
	free(map);
}

char selectCharDefense(int v){
	switch(v){
		case 0 : return '~';
		case 1 : return '#';
		case 2 : return 'X';
		case 3 : return 'O';
		default: return -1;
	}
}
char selectCharAttack(int v){
	switch(v){
		case 0 : return '~';
		case 1 : return 'O';
		case 2 : return 'X';
		default: return -1;
	}
}

void printBoardDefense(Board* map){
	printf("   ");
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
	}
	printf("\n");
	
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
		for(int j=0; j<n_matrix; j++){
			int temp = map -> map[i][j].state;
			printf("  %c",selectCharDefense(temp));
		}
		printf("\n");
	}
}

void printBoardAttack(Board* map) {
	printf("   ");
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
	}
	printf("\n");
	
	for(int i=0; i<n_matrix; i++){
		printf(" %2d",i);
		for(int j=0; j<n_matrix; j++){
			int temp = map -> map[i][j].shot;
			printf("  %c",selectCharAttack(temp));
		}
		printf("\n");
	}
}
