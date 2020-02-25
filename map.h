// -------- Estrutura do mapa ------- //
//Matriz n*n
typedef struct map{
	unsigned int size;
	int **matrix;
} MAP;

/* Boat type   symbol   size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		3
	Submarine	s 			3
	Destroyer   d 			2*/

int boat_size(char c){
   switch(c){
      case 'c': return 5;
      case 'b': return 4;
      case 'r': return 3;
      case 's': return 3;
      case 'd': return 2;
      default: return -1;
   }
}

//Struct para as coordenadas
typedef struct {
	int row; 	//linha
	int column; //colunas
} COORDINATES;

//Localização do barco
typedef struct {
    COORDINATES position;
    int direction;
} BOATPOSITION;

//Struct para embarcações
typedef struct {
	char id;
	unsigned int length;
	char *name;
	int *damage;
	BOATPOSITION position;
} SHIP;

BOATPOSITION placeShip(COORDINATES position, int direction){
	BOATPOSITION new;
	new.position = position;
	new.direction = direction;
	return new;
}

//Struct que define cada célula 1*1 (estou a tentar uma coisa)
/*typedef struct {
	//char symbol ????
	COORDINATES position;
} CELLS;
*/

