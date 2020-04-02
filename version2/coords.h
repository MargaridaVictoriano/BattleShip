/**************************************
               VERSION 2
**************************************/  

//Struct para as coordenadas
typedef struct {
	int row; 	  //linha
	int column;   //colunas
	int rotation; //rotacao
} Coords;

Coords* buildCoords(int row, int column){
   Coords *new = (Coords *)malloc(sizeof(Coords));
   new -> row = row;
   new -> column = column;
   new -> rotation = 0;
   return new;
}

void destroyCoords(Coords* new){
	free(new);
}
