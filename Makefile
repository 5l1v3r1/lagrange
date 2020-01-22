CC = gcc

test:
	$(CC) -g -Iinclude test.c src/*.c -o test

all: test

