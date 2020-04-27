#ifndef BOAT
#define BOAT

#define MAX_AREA 5

typedef struct {
	char id;
	Coords* coords;
	unsigned char hp;  
	char *ship;       
} Boat;

extern const char listBoat[];
extern const char l[];
extern const char c[];
extern const char b[];
extern const char r[];
extern const char s[];
extern const char d[];

signed char indexBoat(char);
signed char sizeBoat(char);
const char* nameBoat(char);
void rotBoat(Boat*);
void prepareBoat(Boat*);
Boat* buildBoat(char,Coords*);
void destroyBoatTemp(Boat*);
void destroyBoat(Boat*);
void setShip(Boat*,int,int,int);

#endif
