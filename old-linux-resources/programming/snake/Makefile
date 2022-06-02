
output: main.o snake.o food.o block.o
	g++ -lncurses -o output main.o snake.o food.o block.o

main.o: main.cpp
	g++ -c main.cpp

snake.o: snake.cpp snake.hpp
	g++ -c snake.cpp

food.o: food.cpp food.hpp
	g++ -c food.cpp

block.o: block.cpp block.hpp
	g++ -c block.cpp

clean: 
	rm *.o output

run:
	./output
