FLAGS = -Wall -Wextra -Werror -pedantic

BSTNode: BSTNode.o pc25.o
	g++ $(FLAGS) BSTNode.o pc25.o -o BSTNode

pc25.o: pc25.cpp
	g++ -c $(FLAGS) pc25.cpp -o pc25.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	rm -f *.o

cleanall: clean
	rm -f BSTNode
	
