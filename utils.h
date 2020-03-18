void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//usar em game
int contains_boat(MAP* map, int x, int y) {
    if (map -> matrix[x][y] == 1) return 1;
    return 0;
}

BOAT insert_boat(MAP* map, char boat_id, BOATPOSITION position) {
    int size_boat = boat_size(boat_id);
    int x = position.position.row;
    int y = position.position.column;
    int dir = position.direction;

    if (dir) { // horizontal
        for (int k = y; k < size_boat + y; k++) {
            map -> matrix[x][k] = 1;
        }
    }
    else { // vertical
        for (int k = x; k < size_boat + x; k++) {
            map -> matrix[k][y] = 1;
        }
    }
    
    return build_boat(boat_id, position);
}

bool checkAvalablePosition(MAP* map, char boat_id, BOATPOSITION position) {
    int size_boat = boat_size(boat_id);
    int x = position.position.row;
    int y = position.position.column;
    int dir = position.direction;

    if (x < 0 || y < 0 || x >= n_matrix || y >= n_matrix || dir < 0 || dir > 1) return false;

    if (dir) { // horizontal
        if (size_boat + y >= n_matrix) return false;
        for (int k = y; k < size_boat + y; k++) {
            if (map -> matrix[x][k] != 0) return false;
        }
    }
    else { // vertical
        if (size_boat + x >= n_matrix) return false;
        for (int k = x; k < size_boat + x; k++) {
            if (map -> matrix[k][y] != 0) return false;
        }
    }
    
    return true;
}

// ASSUMINDO QUE A <= B
int getRandomNumber(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

void randomlyPlaceBoatonMap(MAP* map) {
    BOATPOSITION boat_pos;
    char boat_id[] = {'c','b','r','s','d'};
    
    for (int i = 0; i < n_boats; i++) {
        do {
            boat_pos.direction = getRandomNumber(0, 1); // 0 : horizontal, 1 : vertical 
            boat_pos.position.row = getRandomNumber(0, n_matrix - 1);
            boat_pos.position.column = getRandomNumber(0, n_matrix - 1);
        } while (!checkAvalablePosition(map, boat_id[i], boat_pos));
        
        insert_boat(map, boat_id[i], boat_pos);
    }
}
