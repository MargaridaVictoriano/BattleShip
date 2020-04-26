all: battleship

clean:
	rm -rf *.o battleship

battleship: global_var.o coords.o boat.o board.o utils.o
	gcc -o battleship.o battleship.c -c -std=c99 -Wpedantic -Wall -Wextra
	gcc -o battleship *.o

global_var.o: global_var.c global_var.h
	gcc -o global_var.o global_var.c -c -std=c99 -Wpedantic -Wall -Wextra

coords.o: coords.c coords.h
	gcc -o coords.o coords.c -c -std=c99 -Wpedantic -Wall -Wextra

boat.o: boat.c boat.h coords.h
	gcc -o boat.o boat.c -c -std=c99 -Wpedantic -Wall -Wextra

board.o: board.c board.h global_var.h coords.h boat.h
	gcc -o board.o board.c -c -std=c99 -Wpedantic -Wall -Wextra

utils.o: utils.c utils.h global_var.h coords.h boat.h board.h
	gcc -o utils.o utils.c -c -std=c99 -Wpedantic -Wall -Wextra

