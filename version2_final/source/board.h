#ifndef BOARD
#define BOARD

// Limites da matriz
#define MIN_MATRIX 20
#define MAX_MATRIX 40

typedef struct {
	// informacao adversario
	int shot;    // 0 = no shot, 1 = shot that didn't hit, 2 = shot that hit an enemy piece
	// informacao local
	int state;   // 0 = empty, 1 = piece without being hitted, 2 = piece hitted, 3 = missed shot
	Boat *ship;  // apontador para o barco local
} Cell;

//Matriz n*n
typedef struct {
	Cell **map;
	int remainingBoats;
	
	// reserva dos boats
	int size_boats;
	Boat **boats;
} Board;

Board *buildBoard();
void destroyBoard(Board*);
char selectCharDefense(int);
char selectCharAttack(int);
void printBoardDefense(Board*);
void printBoardAttack(Board*);

#endif
