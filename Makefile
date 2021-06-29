all: program

main:
	g++ -o main.o -c jg.cpp

clean:
	rm -f *.o

program: clean main
	g++ main.o -o program -lsfml-graphics -lsfml-window -lsfml-system

