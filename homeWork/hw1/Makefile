CC=g++
CFLAGS= -fpermissive

all:
	@$(CC) $(CFLAGS) -c src/main.cpp -I obj/ -o obj/main.o
	@$(CC) $(CFLAGS) -o bin/main obj/main.o

clean:
	rm -f obj/*.*
	rm -f bin/*.*

run:
	cd ./bin; ./main;
