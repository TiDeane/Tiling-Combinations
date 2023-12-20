# type of compiler
CC=gcc
# falta -Wextra so que os erros que aparecem la nao interessam muito
CFLAGS=-Wall  

FILE_NAME=tilingCombinations

all:
	$(CC) $(CFLAGS) $(FILE_NAME).c -o $(FILE_NAME)

clean:
	rm -rf $(FILE_NAME) *.o