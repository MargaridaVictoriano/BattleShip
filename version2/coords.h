//Struct para as coordenadas
typedef struct {
	int row; 	  //linha
	int column;   //colunas
	int rotation; //rotacao
} Coords;

Coords* buildCoords(int row, int column, int rotation){
   Coords* new = (Coords *)malloc(sizeof(Coords));
   if(new == NULL) exit(-1);
   new -> row = row;
   new -> column = column;
   new -> rotation = rotation % 360;
   return new;
}

void destroyCoords(Coords* new){
	free(new);
}
