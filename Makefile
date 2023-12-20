CC=gcc
CFLAGS=-Wall  

FILE_NAME=tilingCombinations

all:
	$(CC) $(CFLAGS) $(FILE_NAME).c -o $(FILE_NAME)

generator:
	g++ -std=c++11 -O3 -Wall validTilingGenerator.cpp -lm -o generator

clean:
	rm -rf $(FILE_NAME) generator *.o