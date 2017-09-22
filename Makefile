main: PPM.h PPM.cpp main.cpp
	g++ -o main PPM.cpp main.cpp

run: main
	./main
