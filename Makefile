all: Program

Program: main.o
		g++  main.cpp  -o Program

main.o: main.cpp
		   g++ -c main.cpp


clean:
		rm -rf *o Program