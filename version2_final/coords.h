//Struct para as coordenadas
typedef struct {
	int row; 	  //linha
	int column;   //colunas
	int rotation; //rotacao
} Coords;

Coords* buildCoords(int, int,int);
void destroyCoords(Coords*);
