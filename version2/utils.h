void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ASSUMINDO QUE A <= B
int getRandomNumber(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

//Verificar se contem barco
bool containsBoat(Board* board, int x, int y) {
    if(board -> map[x][y].ship != NULL) {
        return true;
    } 
    return false;
}

bool checkAvalablePosition(Board* board, char boat_id, Coords* coords) {
    int x = coords -> row;
    int y = coords -> column;
    int rotation = coords -> rotation;
    if (x < 0 || y < 0 || x >= n_matrix || y >= n_matrix ) return false;
    if(rotation < 0 || rotation > 360 || rotation%90 != 0) {
        return false;
    }
    Boat* temp = buildBoat(boat_id,coords);
    for(int i = 0 ; i < MAX_AREA; i++) {
        for(int j = 0; j < MAX_AREA; j++) {
            if(temp -> ship[i][j] == 1) {
                if(i+x-2 < 0 || j+y-2 < 0 || i+x-2 >= n_matrix || j+y-2 >= n_matrix || containsBoat(board,i+x-2,j+y-2)) {
                    destroyBoat(temp);
                    return false;
                }
            }
        }
    }
    destroyBoat(temp);
    return true;
}

void insertBoat(Board* board, char boat_id, Coords* coords) {
    int x = coords -> row;
    int y = coords -> column;
    Boat* temp = buildBoat(boat_id,coords);
    for(int i = 0 ; i < MAX_AREA ; i++) {
        for(int j = 0; j < MAX_AREA; j++) {
            if(temp -> ship[i][j] == 1) {
                board -> map[i+x-2][j+y-2].state = 1;
                board -> map[i+x-2][j+y-2].ship = temp;
            }
        }
    }
}


void randomlyPlaceBoatonBoard(Board* board) {
    char boat_id[] = {'c','b','r','s','d','l'}; 
    for (int i = 0; i < n_boats; i++) {
        Coords* coords = buildCoords(getRandomNumber(0,n_matrix -1),getRandomNumber(0, n_matrix -1),getRandomNumber(0, 3)*90);
        if (checkAvalablePosition(board, boat_id[i], coords)) {
            insertBoat(board, boat_id[i], coords);
        }
        else {
            i--;
        }
    }
}
