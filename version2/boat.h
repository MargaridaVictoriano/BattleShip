// decidir um barco espcial. usei so o l para ter algo com que fazer testes. mas funciona
// em qualquer um. temos que o batizar ;-)

/*  Boat type   symbol      size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		    3
	Submarine	s 			3
	Destroyer   d 			2*/
	
#define MAX_AREA 5

//Struct para embarcações
typedef struct {
	char id;
	Coords* coords;
	int damage;
	int **ship;
} Boat;


int sizeBoat(char id){
   	switch(id){
   		case 'l': return 9;
      	case 'c': return 5;
      	case 'b': return 4;
      	case 'r': return 3;
      	case 's': return 3;
      	case 'd': return 2;
      	default: return -1;
   	}
}

/*const char c[] = "CARRIER";
const char b[] = "BATTLESHIP";
const char r[] = "CRUISER";
const char s[] = "SUBMARINE";
const char d[] = "DESTROYER";

const char* nameBoat(char id){
	switch(id){
	    case 'c': return c;
  	    case 'b': return b;
  	    case 'r': return r;
  	    case 's': return s;
  	    case 'd': return d;
  	    default: return NULL;
	}
}*/

void rotBoat(Boat* boat){
	int** mat = boat -> ship;
	switch(boat -> coords -> rotation){
		case 0 :
			return;
		case 90:
			for (int i = 0; i < MAX_AREA / 2; i++) { 
      			for (int j = i; j < MAX_AREA-i-1; j++) { 
            		int temp = mat[i][j]; 
            		mat[i][j] = mat[j][MAX_AREA-1-i]; 
            		mat[j][MAX_AREA-1-i] = mat[MAX_AREA-1-i][MAX_AREA-1-j]; 
            		mat[MAX_AREA-1-i][MAX_AREA-1-j] = mat[MAX_AREA-1-j][i]; 
            		mat[MAX_AREA-1-j][i] = temp; 
        		} 
    		} 
			return;
		case 180:
			for(int i=0; i<MAX_AREA; i++){
        		for(int j=0; j<i; j++){
         		   int temp = mat[i][j];
        		   mat[i][j] = mat[j][i];
      		       mat[j][i] = temp;
     		    }
  			}
			return;
		case 270:
			for (int i = 0; i < MAX_AREA / 2; i++) { 
        		for (int j = i; j < MAX_AREA-i-1; j++) { 
            		int temp = mat[i][j]; 
            		mat[i][j] = mat[MAX_AREA-1-j][i]; 
            		mat[MAX_AREA-1-j][i] = mat[MAX_AREA-1-i][MAX_AREA-1-j]; 
            		mat[MAX_AREA-1-i][MAX_AREA-1-j] = mat[j][MAX_AREA-1-i]; 
        	   		mat[j][MAX_AREA-1-i] = temp; 
        		} 
    		} 
			return;
	}
}

// contruir o barco modelo
void prepareBoat(Boat* boat){
	char id = boat -> id;
	if(id == 'l') {
		for(int i=0; i<MAX_AREA ; i++)
			boat -> ship[i][0] = 1;
		for(int i=1; i<MAX_AREA ; i++)
			boat -> ship[MAX_AREA-1][i] = 1;
	}
	else {
		int size = sizeBoat(id);
		for(int i=0; i<size; i++){
			boat -> ship[2][i] = 1;
		}
	}
}

Boat* buildBoat(char id, Coords* coords){
    Boat* new = (Boat*)malloc(sizeof(Boat));
    new -> id = id;
    new -> coords = coords;
    new -> damage = sizeBoat(id);
    
    new -> ship = (int **)malloc(MAX_AREA*sizeof(int *));
	for(int i=0; i<MAX_AREA; i++){
	    new -> ship[i] = (int *)malloc(MAX_AREA*sizeof(int));
	    for(int j=0; j<MAX_AREA; j++){
	    	new -> ship[i][j] = 0;
	    }
	}
    
    prepareBoat(new);
    rotBoat(new);
    return new;
}

void destroyBoat(Boat* boat){
	for(int i=0; i<MAX_AREA; i++){
       	free(boat -> ship[i]);
    }
    free(boat -> ship);
    destroyCoords(boat -> coords);
	free(boat);
}
//Debug
void printShip(Boat *boat){
	printf("   ");
	for(int i=0; i<MAX_AREA; i++){
		printf(" %2d",i);
	}
	printf("\n");
	
	for(int i=0; i<MAX_AREA; i++){
		printf(" %2d",i);
		for(int j=0; j<MAX_AREA; j++){
			int temp = boat -> ship[i][j];
			printf("  %d",temp);
		}
		printf("\n");
	}
}

/*//Localização do barco
	// direction = 0 -> vertical
	// direction = 1 -> horizontal
typedef struct {
    COORDINATES position;
    int rotation;
} BOATPOSITION;

BOATPOSITION build_boatposition(COORDINATES position, int direction){
	BOATPOSITION new;
	new.position = position;
	new.direction = direction;
	return new;
}*/
