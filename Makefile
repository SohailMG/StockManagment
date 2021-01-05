CXXFLAGS += -w
CXX = g++
.PHONY = all
all: Program


Program: main.o
		$(CXX) $(CXXFLAGS) main.cpp  -o Program

main.o: main.cpp header.h
		$(CXX) $(CXXFLAGS) -c main.cpp

.PHONY : clean
clean:
		rm -rf *o Program