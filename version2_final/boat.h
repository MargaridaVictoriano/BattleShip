#define MAX_AREA 5

//Struct para embarcações
typedef struct {
	char id;
	Coords* coords;
	int hp;
	int **ship;
} Boat;

const char listBoat[] = {'l','c','b','r','s','d'};

const char l[] = "LBOAT";
const char c[] = "CARRIER";
const char b[] = "BATTLESHIP";
const char r[] = "CRUISER";
const char s[] = "SUBMARINE";
const char d[] = "DESTROYER";

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

