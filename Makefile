# === Makefile ===

CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = src/main.o src/poly.o src/keygen.o src/sign.o src/verify.o

# Final build
hypermaze.exe: $(OBJ)
	$(CC) $(OBJ) -o hypermaze.exe

# Individual object files
src/main.o: src/main.c include/keygen.h include/poly.h include/sign.h include/verify.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/poly.o: src/poly.c include/poly.h
	$(CC) $(CFLAGS) -c src/poly.c -o src/poly.o

src/keygen.o: src/keygen.c include/keygen.h include/poly.h
	$(CC) $(CFLAGS) -c src/keygen.c -o src/keygen.o

src/sign.o: src/sign.c include/sign.h include/keygen.h include/poly.h
	$(CC) $(CFLAGS) -c src/sign.c -o src/sign.o

src/verify.o: src/verify.c include/verify.h include/poly.h include/sign.h
	$(CC) $(CFLAGS) -c src/verify.c -o src/verify.o

# Clean build
clean:
	rm -f src/*.o hypermaze.exe