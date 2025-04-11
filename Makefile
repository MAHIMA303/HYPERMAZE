CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = src/main.o src/poly.o src/keygen.o src/ntt.o

all: hypermaze.exe

hypermaze.exe: $(OBJ)
	$(CC) $(OBJ) -o hypermaze.exe

src/main.o: src/main.c include/poly.h include/keygen.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/poly.o: src/poly.c include/poly.h include/ntt.h
	$(CC) $(CFLAGS) -c src/poly.c -o src/poly.o

src/keygen.o: src/keygen.c include/keygen.h include/poly.h
	$(CC) $(CFLAGS) -c src/keygen.c -o src/keygen.o

src/ntt.o: src/ntt.c include/ntt.h
	$(CC) $(CFLAGS) -c src/ntt.c -o src/ntt.o

clean:
	rm -f src/*.o hypermaze.exe