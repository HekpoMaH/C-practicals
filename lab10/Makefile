DEBUG_FLAGS = -g -fno-omit-frame-pointer -Wall -pedantic

all:
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -c lab10.c
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -c parse.c
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -c expr.c
	gcc -fsanitize=address -fsanitize=undefined ${DEBUG_FLAGS} -o lab10 lab10.o parse.o expr.o 

clean:
	rm -f lab10 lab10.o parse.o expr.o 
