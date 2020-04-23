#ifndef BOAT
#define BOAT

#define MAX_AREA 5

//Struct para embarcações
typedef struct {
	char id;
	Coords* coords;
	int hp;
	int **ship;
} Boat;

extern const char listBoat[];
extern const char l[];
extern const char c[];
extern const char b[];
extern const char r[];
extern const char s[];
extern const char d[];

int indexBoat(char);
int sizeBoat(char);
const char* nameBoat(char);
void rotBoat(Boat*);
void prepareBoat(Boat*);
Boat* buildBoat(char,Coords*);
void destroyBoatTemp(Boat*);
void destroyBoat(Boat*);
void setShip(Boat*,int,int,int);

//Debug
//void printShip(Boat);

#endif
