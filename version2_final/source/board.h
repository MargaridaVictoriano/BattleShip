#ifndef BOARD
#define BOARD

//Matrix limits
#define MIN_MATRIX 20
#define MAX_MATRIX 40

typedef struct {
	char shot;
	char state;
	Boat *ship;
} Cell;


typedef struct {
	Cell *map;
	char remainingBoats;
	unsigned char size_boats;
	Boat **boats;
} Board;

Board* buildBoard();
void destroyBoard(Board*);
char selectCharDefense(char);
char selectCharAttack(char);
void printDefenseBoard(Board*);
void printAttackBoard(Board*);

#endif
