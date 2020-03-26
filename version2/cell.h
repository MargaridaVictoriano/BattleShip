
/**************************************
               VERSION 2
 ************************************/

// Celulas
typedef struct {
	bool isShot; // false = not hitted, true = hitted
	int state;   // 0 = empty, 1 = piece without being hitted, 2 = piece hitted, 3 = missed shot
	Boat *ship;
} Cell;
