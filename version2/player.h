typedef struct {
	Map *mapPlayer;
} Player;

//Construtor do jogador
Player *buildPlayer(Map *map) {
	Player* new = (Player*)malloc(sizeof(Player)); 
	new -> mapPlayer = map; 
	return new;
}

void destroyPlayer(Player* player) {
	destroyMap(player -> mapPlayer);
	free(player);
}

