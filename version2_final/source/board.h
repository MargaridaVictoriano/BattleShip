#ifndef BOARD
#define BOARD

// Limites da matriz
#define MIN_MATRIX 20
#define MAX_MATRIX 40

typedef struct {
	// informacao adversario
	// 0 = no shot, 1 = shot that didn't hit, 2 = shot that hit an enemy piece
	char shot;    // [0,2]
	
	// informacao local
	// 0 = empty, 1 = piece without being hitted, 2 = piece hitted, 3 = missed shot
	char state;   // [0,3]
	// apontador para o barco local
	Boat *ship;  
} Cell;

//Matriz n*n
typedef struct {
	Cell *map;                      // array a simular a matrix
	char remainingBoats;            // [0,64]
	
	// reserva dos boats
	unsigned char size_boats;       // [16,64]
	Boat **boats;
} Board;

Board *buildBoard();
void destroyBoard(Board*);
char selectCharDefense(char);
char selectCharAttack(char);
void printBoardDefense(Board*);
void printBoardAttack(Board*);

#endif
