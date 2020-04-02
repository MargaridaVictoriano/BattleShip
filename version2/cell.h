
/**************************************
               VERSION 2
 ************************************/

// Celulas
typedef struct {
	// informacao adversario
	int shot;    // 0 = no shot, 1 = shot that didn't hit, 2 = shot that hit an enemy piece
	
	// informacao local
	int state;   // 0 = empty, 1 = piece without being hitted, 2 = piece hitted, 3 = missed shot
	Boat *ship;  // apontador para o barco local
} Cell;

