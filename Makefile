CXXFLAGS += -w -g -Wall -Wextra
CXX = g++
RM = rm -rf 
OBJS = main.o Product.o addProduct.o sellProduct.o RestockProduct.o updateStock.o menu.o

.PHONY = all
all: Program


Program:$(OBJS)
		$(CXX) $(CXXFLAGS)  -o Program  $(OBJS)

main.o: main.cpp  
		$(CXX) $(CXXFLAGS) -c main.cpp
Product.o: Product.cpp Product.h
		$(CXX) $(CXXFLAGS) -c Product.cpp
addProduct.o: addProduct.cpp addProduct.h
		$(CXX) $(CXXFLAGS) -c addProduct.cpp
sellProduct.o: sellProduct.cpp sellProduct.h
		$(CXX) $(CXXFLAGS) -c sellProduct.cpp
RestockProduct.o: RestockProduct.cpp RestockProduct.h
		$(CXX) $(CXXFLAGS) -c RestockProduct.cpp
updateStock.o: updateStock.cpp updateStock.h
		$(CXX) $(CXXFLAGS) -c updateStock.cpp
menu.o: menu.cpp menu.h
		$(CXX) $(CXXFLAGS) -c menu.cpp


.PHONY : clean
clean:
		$(RM) *o Program