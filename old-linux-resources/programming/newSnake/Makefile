
output: main.o snake.o
	g++ -lncurses -o output main.o snake.o

main.o: main.cpp
	g++ -c main.cpp

snake.o: snake.cpp snake.h
	g++ -c snake.cpp

clean: 
	rm *.o output

run:
	./output
