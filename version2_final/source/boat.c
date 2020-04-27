#include <stdlib.h>

#include "coords.h"
#include "boat.h"

const char listBoat[] = {'l','c','b','r','s','d'};

const char l[] = "LBOAT";
const char c[] = "CARRIER";
const char b[] = "BATTLESHIP";
const char r[] = "CRUISER";
const char s[] = "SUBMARINE";
const char d[] = "DESTROYER";

/**
 * Function name : indexBoat()
 * Usage         : indexBoat(char);
 * Definition    : Returns boat ID index.            
 */

signed char indexBoat(char id){
   	switch(id){
   		case 'l': return 0;
      	case 'c': return 1;
      	case 'b': return 2;
      	case 'r': return 3;
      	case 's': return 4;
      	case 'd': return 5;
      	default: return -1;
   	}
}

/**
 * Function name : sizeBoat()
 * Usage         : sizeBoat(char);
 * Definition    : Returns the boat size.            
 */

signed char sizeBoat(char id){
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

/**
 * Function name : nameBoat()
 * Usage         : nameBoat(char);
 * Definition    : Returns the boat name.            
 */

const char* nameBoat(char id){
	switch(id){
		case 'l': return l;
	    case 'c': return c;
  	    case 'b': return b;
  	    case 'r': return r;
  	    case 's': return s;
  	    case 'd': return d;
  	    default: return NULL;
	}
}

/**
 * Function name : rotBoat()
 * Usage         : rotBoat(Boat*);
 * Definition    : This function applies the desired rotation to the boat.            
 */

void rotBoat(Boat* boat){
	char *mat = boat -> ship, temp;
	switch(boat -> coords -> rotation){
		case 0 :
			return;
		case 90:
			for (int i = 0; i < MAX_AREA / 2; i++) { 
      			for (int j = i; j < MAX_AREA-i-1; j++) { 
            		temp = mat[i*MAX_AREA + j]; 
            		mat[i*MAX_AREA + j] = mat[j*MAX_AREA + MAX_AREA-1-i]; 
            		mat[j*MAX_AREA + MAX_AREA-1-i] = mat[(MAX_AREA-1-i)*MAX_AREA + MAX_AREA-1-j]; 
            		mat[(MAX_AREA-1-i)*MAX_AREA + MAX_AREA-1-j] = mat[(MAX_AREA-1-j)*MAX_AREA + i]; 
            		mat[(MAX_AREA-1-j)*MAX_AREA + i] = temp; 
        		} 
    		} 
			return;
		case 180:
			for(int i=0;i<MAX_AREA/2;i++) { 
            	for(int j=0;j<MAX_AREA;j++) { 
                	temp = mat[i*MAX_AREA + j]; 
                	mat[i*MAX_AREA + j] = mat[(MAX_AREA-i-1)*MAX_AREA + MAX_AREA-j-1]; 
               		mat[(MAX_AREA-i-1)*MAX_AREA + MAX_AREA-j-1] = temp; 
            	}
        	}
        	
        	// quando MAX_AREA impar
        	if(MAX_AREA & 1){
        		for(int j=0; j<MAX_AREA/2; j++){
        			temp = mat[(MAX_AREA/2)*MAX_AREA + j]; 
                	mat[(MAX_AREA/2)*MAX_AREA + j] = mat[(MAX_AREA/2)*MAX_AREA + MAX_AREA-j-1]; 
               		mat[(MAX_AREA/2)*MAX_AREA + MAX_AREA-j-1] = temp; 
        		}
        	}
        	
			return;
		case 270:
			for (int i = 0; i < MAX_AREA / 2; i++) { 
        		for (int j = i; j < MAX_AREA-i-1; j++) { 
            		temp = mat[i*MAX_AREA + j]; 
            		mat[i*MAX_AREA + j] = mat[(MAX_AREA-1-j)*MAX_AREA + i]; 
            		mat[(MAX_AREA-1-j)*MAX_AREA + i] = mat[(MAX_AREA-1-i)*MAX_AREA + MAX_AREA-1-j]; 
            		mat[(MAX_AREA-1-i)*MAX_AREA + MAX_AREA-1-j] = mat[j*MAX_AREA + MAX_AREA-1-i]; 
        	   		mat[j*MAX_AREA + MAX_AREA-1-i] = temp; 
        		} 
    		} 
			return;
	}
}

/**
 * Function name : prepareBoat()
 * Usage         : prepareBoat(Boat*);
 * Definition    : This function creates the boat generic model.            
 */

void prepareBoat(Boat* boat){
	char id = boat -> id;
	if(id == 'l') {
		for(int i=0; i<MAX_AREA ; i++)
			boat -> ship[i*MAX_AREA + 0] = 1;
		for(int i=1; i<MAX_AREA ; i++)
			boat -> ship[(MAX_AREA-1)*MAX_AREA + i] = 1;
	}
	else {
		int size = sizeBoat(id);
		for(int i=0; i<size; i++){
			boat -> ship[2*MAX_AREA + i] = 1;
		}
	}
}

/**
 * Function name : buildBoat()
 * Usage         : buildBoat(char,Coords*);
 * Definition    : This function allocates the structure on the heap, creates the boat generic model and it applies the requested rotation.            
 */

Boat* buildBoat(char id, Coords* coords){
    Boat* new = (Boat*)malloc(sizeof(Boat));
    if(new == NULL) exit(-1);
    
    new -> id = id;
    new -> coords = coords;
    new -> hp = sizeBoat(id);
    
    new -> ship = (char *)malloc(MAX_AREA*MAX_AREA*sizeof(char));
    if(new -> ship == NULL) exit(-1);
	
	for(int i=0; i<MAX_AREA; i++){
	    for(int j=0; j<MAX_AREA; j++){
	    	new -> ship[i*MAX_AREA + j] = 0;
	    }
	}
    
    prepareBoat(new);
    rotBoat(new);
    return new;
}

/**
 * Function name : destroyBoatTemp()
 * Usage         : destroyBoatTemp(Boat*);
 * Definition    : This function deallocs everything except for the coordinates.            
 */

void destroyBoatTemp(Boat* boat){
    free(boat -> ship);
	free(boat);
}

/**
 * Function name : destroyBoat()
 * Usage         : destroyBoat(Boat*);
 * Definition    : This function deallocs everything.           
 */

void destroyBoat(Boat* boat){
    destroyCoords(boat -> coords);
	  destroyBoatTemp(boat);
}

/**
 * Function name : setShip()
 * Usage         : setShip(Boat*,int,int,int);
 * Definition    : This function updates the boat structure when it suffers an attack.           
 */

void setShip(Boat* boat, int value, int x, int y){
	if(value >= 0 && value <= 3){
		if(boat -> id == 'l') {
			boat -> ship[(x - boat -> coords -> row)*MAX_AREA + y - boat -> coords -> column] = value;
		}
		else {
			switch(boat -> coords -> rotation){
				case 0  : boat -> ship[(x - boat -> coords -> row + 2)*MAX_AREA + y - boat -> coords -> column] = value; break;
				case 90 : boat -> ship[(MAX_AREA - 1 - (x - boat -> coords -> row))*MAX_AREA + y - boat -> coords -> column + 2] = value; break;
				case 180: boat -> ship[(x - boat -> coords -> row + 2)*MAX_AREA + MAX_AREA - 1 - (y - boat -> coords -> column)] = value; break;
				case 270: boat -> ship[(x - boat -> coords -> row)*MAX_AREA + y - boat -> coords -> column + 2] = value; break;
			}
		}
	}
}

//Debug
// incluir #include <stdio.h> para usar neste file
/*void printShip(Boat *boat){
	printf("   ");
	for(int i=0; i<MAX_AREA; i++){
		printf(" %2d",i);
	}
	printf("\n");
	
	for(int i=0; i<MAX_AREA; i++){
		printf(" %2d",i);
		for(int j=0; j<MAX_AREA; j++){
			int temp = boat -> ship[i*MAX_AREA + j];
			printf("  %d",temp);
		}
		printf("\n");
	}
}*/
