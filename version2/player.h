typedef struct {
	Map *mapPlayer;
	Map *mapOpponent;
} Player;

//Construtor do jogador
Player *buildPlayer(Map *map) {
	Player* new = (Player*)malloc(sizeof(Player)); 
	new -> mapPlayer = map;
	new -> mapOpponent = (Map *)buildMap(); 
	return new;
}

void destroyPlayer(Player* player) {
	destroyMap(player -> mapPlayer);
	destroyMap(player -> mapOpponent);
	free(player);
}

