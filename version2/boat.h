/**************************************
               VERSION 2
 ************************************/  
             
/* Boat type   symbol   size
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

const char* nameBoat(char id){
   switch(id){
      case 'c': return c;
      case 'b': return b;
      case 'r': return r;
      case 's': return s;
      case 'd': return d;
      default: return NULL;
   }
}

//falta testar
//
void rotBoat(Boat* boat){
	int** mat = boat -> ship;
	switch(boat -> coords -> rotation % 360){
		case 0 :
			return;
		case 90:
			for (int x = 0; x < MAX_AREA / 2; x++) { 
      			for (int y = x; y < MAX_AREA-x-1; y++) { 
            		int temp = mat[x][y]; 
            		mat[x][y] = mat[y][MAX_AREA-1-x]; 
            		mat[y][MAX_AREA-1-x] = mat[MAX_AREA-1-x][MAX_AREA-1-y]; 
            		mat[MAX_AREA-1-x][MAX_AREA-1-y] = mat[MAX_AREA-1-y][x]; 
            		mat[MAX_AREA-1-y][x] = temp; 
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

// falta terminar
// contruir o barco modelo
void prepareBoat(Boat* boat){
	// zerar a matrix
	int** map = boat -> ship;
	for(int i = 0; i < MAX_AREA; i++) {
		for(int j = 0; j < MAX_AREA; j++) {
			map[i][j] = 0;
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

/*// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
void rotateMatrix(int mat[][MAX_AREA]) { 
    for (int x = 0; x < MAX_AREA / 2; x++) { 
        for (int y = x; y < MAX_AREA-x-1; y++) { 
            int temp = mat[x][y]; 
            mat[x][y] = mat[y][MAX_AREA-1-x]; 
            mat[y][MAX_AREA-1-x] = mat[MAX_AREA-1-x][MAX_AREA-1-y]; 
            mat[MAX_AREA-1-x][MAX_AREA-1-y] = mat[MAX_AREA-1-y][x]; 
            mat[MAX_AREA-1-y][x] = temp; 
        } 
    } 
} 

void transpose(int** mat){
	for(int i=0; i<MAX_AREA; i++){
        for(int j=0; j<i; j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
}

// ainda nao testada
void flip_lines(int** mat){	
	int j,i,temp;	
	for(i=0;i<MAX_AREA;i++)
    {
    	int k = MAX_AREA-1;
        for(j=0;j<k;j++)
        {
            temp=mat[j][i];
            mat[j][i]=mat[k][i];
            mat[k][i]=temp;
            k--;
        }
    }
}*/
