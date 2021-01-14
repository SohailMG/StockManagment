CXXFLAGS += -w -g -Wall -Wextra
CXX = g++
RM = rm -rf 
OBJS = main.o Product.o CD.o DVD.o Book.o Magazines.o 

.PHONY = all
all: Program


Program:$(OBJS)
		$(CXX) $(CXXFLAGS)  -o Program  $(OBJS)

main.o: main.cpp  
		$(CXX) $(CXXFLAGS) -c main.cpp
Product.o: Product.cpp Product.h
		$(CXX) $(CXXFLAGS) -c Product.cpp
CD.o: CD.cpp CD.h
		$(CXX) $(CXXFLAGS) -c CD.cpp
DVD.o: DVD.cpp DVD.h
		$(CXX) $(CXXFLAGS) -c DVD.cpp
Book.o: Book.cpp Book.h
		$(CXX) $(CXXFLAGS) -c Book.cpp
Magazines.o: Magazines.cpp Magazines.h
		$(CXX) $(CXXFLAGS) -c Magazines.cpp


.PHONY : clean
clean:
		$(RM) *o Program