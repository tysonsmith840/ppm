main: PPM.h PPM.cpp main.cpp
	g++ -std=c++11 -o main PPM.cpp main.cpp

run: main
	./main
