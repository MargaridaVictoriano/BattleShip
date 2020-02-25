// -------- Estrutura do mapa ------- //
/* Boat type   symbol   size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		3
	Submarine	s 			3
	Destroyer   d 			2*/

//Matriz n*n
typedef struct map{
	unsigned int size;
	int **matrix;
} MAP;

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

typedef enum {
	c = "CARRIER",
	b = "BATTLESHIP",
	r = "CRUISER", 
	s = "SUBMARINE",
	d = "DESTROYER"
} Ship_Name;

char* name_boat(char c){
   switch(c){
      case 'c': return Ship_Name.c;
      case 'b': return Ship_Name.b;
      case 'r': return Ship_Name.r;
      case 's': return Ship_Name.s;
      case 'd': return Ship_Name.d;
      default: return NULL;
   }
}

//Struct para as coordenadas
typedef struct {
	int row; 	//linha
	int column; //colunas
} COORDINATES;

COORDINATES build_coordinates(int row, int column){
   COORDINATES new;
   new.row = row;
   new.column = column;
}

//Localização do barco
typedef struct {
    COORDINATES position;
    int direction;
} BOATPOSITION;

BOATPOSITION build_boatposition(COORDINATES position, int direction){
	BOATPOSITION new;
	new.position = position;
	new.direction = direction;
	return new;
}

//Struct para embarcações
typedef struct {
	char id;
	int *damage;
	BOATPOSITION position;
} BOAT;

BOAT build_boat(char id, BOATPOSITION position){
   BOAT new;
   new.id = id;
   int len = boat_size(id);
   new.damage = (int *)malloc(len*sizeof(int));
   for(int i=0; i<len ;i++) damage[i] = 0;
   new.position = position;
}

//Struct que define cada célula 1*1 (estou a tentar uma coisa)
/*typedef struct {
	//char symbol ????
	COORDINATES position;
} CELLS;
*/
