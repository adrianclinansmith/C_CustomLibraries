INCLUDE = -Iinclude
SRC = impls/*.c

all:
	gcc -std=c11 -Wall -g $(INCLUDE) $(SRC) maintest.c -o test

run: test
	./test

runmem: test
	valgrind -v --leak-check=full --show-leak-kinds=all ./test

cppcheck: test
	cppcheck .

clean: test
	rm test
