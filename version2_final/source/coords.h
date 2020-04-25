#ifndef COORDS
#define COORDS

//Struct para as coordenadas
typedef struct {
	int row; 	  //linha   [0,40]
	int column;   //colunas [0,40]
	int rotation; //rotacao [0,360] pode ser convertido para [0,3]
} Coords;

Coords* buildCoords(int,int,int);
void destroyCoords(Coords*);

#endif
