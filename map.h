// -------- Estrutura do mapa ------- //
//Matriz n*n
typedef struct map{
	unsigned int size;
	int **matrix;
} MAP;

/* Boat type   symbol   size
	Carrier		c	  		5
	Battleship 	b	  		4
	Cruiser		r  		3
	Submarine	s 			3
	Destroyer   d 			2
*/ 


// falta definir relaçao com as restantes funçoes. Temos que tomar uma decisao.
typedef enum {
	CARRIER_S    = 5, 
	BATTLESHIP_S = 4,
	CRUISER_S    = 3, 
	SUBMARINE_S  = 3,
	DESTROYER_S  = 2
} ShipeSize;
//Struct para embarcações
typedef struct ship {
	char symbol;
	unsigned int length;
	char *name;
} SHIP;
//Struct para as coordenadas
typedef struct {
	int row; 	//linha
	int column; //colunas
} COORDINATES;
//Struct que define cada célula 1*1 (estou a tentar uma coisa)
typedef struct {
	//char symbol ????
	COORDINATES position;
} CELLS;
//Localização do barco
typedef struct {
    char id;
    int row;
    int column;
    int direction;
} BOATPOSITION;



BOATPOSITION placeShip(int row, int column, char id, int direction){
	BOATPOSITION new;
	new.row = row;
	new.column = column;
	new.direction = direction;
	new.id = id;
	return new;
}




