/* Boat type   symbol   size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		3
	Submarine	s 			3
	Destroyer   d 			2*/

int boat_size(char id){
   switch(id){
      case 'c': return 5;
      case 'b': return 4;
      case 'r': return 3;
      case 's': return 3;
      case 'd': return 2;
      default: return -1;
   }
}

const char c[] = "CARRIER";
const char b[] = "BATTLESHIP";
const char r[] = "CRUISER";
const char s[] = "SUBMARINE";
const char d[] = "DESTROYER";

const char* const name_boat(char id){
   switch(id){
      case 'c': return c;
      case 'b': return b;
      case 'r': return r;
      case 's': return s;
      case 'd': return d;
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
   return new;
}

//Localização do barco
	// direction = 0 -> vertical
	// direction = 1 -> horizontal
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
   for(int i=0; i<len ;i++) new.damage[i] = 0;
   new.position = position;
   return new;
}

