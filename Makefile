CXXFLAGS += -w
all: Program


Program: main.o
		g++ $(CXXFLAGS) main.cpp  -o Program

main.o: main.cpp
		   g++ $(CXXFLAGS) -c main.cpp


clean:
		rm -rf *o Program