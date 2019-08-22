EXEC = bin/runMe
INCLUDE = include
SRC = src/*.c

all:
	gcc -std=c11 -Wall -g -I$(INCLUDE) $(SRC) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

runmem: $(EXEC)
	valgrind -v --leak-check=full --show-leak-kinds=all ./$(EXEC)

cppcheck:
	cppcheck .

clean: $(EXEC)
	rm $(EXEC)
