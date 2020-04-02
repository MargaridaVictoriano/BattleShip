//somatorio do tamanho dos barcos
//int n1_size = 17;
//int n2_size = 17;

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

