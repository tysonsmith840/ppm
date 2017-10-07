all: main
	./main

memtest: main.cpp Todo.cpp Todo.h
	g++ -o memory_test -std=c++11 -Wall -Werror -g main.cpp PPM.cpp PPM.h
	valgrind --leak-check=full ./memory_test

main: PPM.h PPM.cpp main.cpp
	g++ -std=c++11 -o main PPM.cpp main.cpp

run: main
	./main
