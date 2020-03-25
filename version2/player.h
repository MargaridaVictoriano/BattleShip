typedef struct {
	MAP* mapPlayer;
	MAP* mapOpponent;
} PLAYER;

//Construtor do jogador
PLAYER* buildPlayer(MAP* map) {
	PLAYER* new = (PLAYER*)malloc(sizeof(PLAYER)); 
	new -> mapPlayer = map;
	new -> mapOpponent = (MAP*)build_matrix(n_matrix); 
	return new;
}

void destroyPlayer(PLAYER* player) {
	destroy_matrix(player -> mapPlayer);
	destroy_matrix(player -> mapOpponent);
	free(player);
}

