
/**************************************
               VERSION 2
 ************************************/*              
/* Boat type   symbol   size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		3
	Submarine	s 			3
	Destroyer   d 			2*/
	
#define MAX_AREA 5

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

const char* name_boat(char id){
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
	int row; 	  //linha
	int column;   //colunas
	int rotation; //rotacao
} COORDINATES;

COORDINATES* build_coordinates(int row, int column){
   COORDINATES* new = (COORDINATES*)malloc(sizeof(COORDINATES));
   new.row = row;
   new.column = column;
   new.rotation = 0;
   return new;
}

void destroy_coordinates(COORDINATES* new){
	if(new != NULL){
      free(row);
      free(column);
      free(rotation);
      free(new);
   }
}

// marcar a matrix com os barcos
void func(int[MAX_AREA][MAX_AREA] temp, int size){
	for(int i = 0; i < MAX_AREA; i++) {
		for(int j = 0; j < MAX_AREA; j++) {
			if(i == 2 && j < size) temp[i][j] = 1;
			else temp[i][j] = 0;
		}
	}
}

void transpose(int** mat){
	int j,i,temp;	
	for(i=0;i<MAX_AREA;i++)
    {
        for(j=0;j<i;j++)
        {
            temp=mat[i][j];
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
}

void rotation(BOAT* boat){
	int new[MAX_AREA][MAX_AREA];
	
	for(int i = 0; i < MAX_AREA; i++) {
		for(int j = 0; j < MAX_AREA; j++) {
			temp[i][j] = 0;
		}
	}
	
	int rot = boat -> coords -> rotation;
	int** old = boat -> ship;
	
	switch(rot % 360){
		case 0 :
			return;
		case 90:
			for(int i = 0; i < MAX_AREA; i++) {
				for(int j = 0; j < MAX_AREA; j++) {
					if(old[i][j] == 1){
						new[][]
					}
				}
			}
			return;
		case 180:
			for(int i = 0; i < MAX_AREA; i++) {
				for(int j = 0; j < MAX_AREA; j++) {
					if(old[i][j] == 1){
						new[j][i] = 1;
					}
				}
			}
			return;
		case 270:
			for(int i = 0; i < MAX_AREA; i++) {
				for(int j = 0; j < MAX_AREA; j++) {
					if(old[i][j] == 1){
						new[][]
					}
				}
			}
			return;
	}
}


//Struct para embarcações
typedef struct {
	char id;
	int damage;
	int ship[MAX_AREA][MAX_AREA];
	COORDINATES* coords;
} BOAT;

BOAT* build_boat(char id, COORDINATES* coords){
   BOAT* new = (BOAT*)malloc(sizeof(BOAT));
   new.id = id;
   int damage = boat_size(id);
   new.coords = coords;
   
   func(ship,damage);
   rotation(new);
   
   return new;
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
