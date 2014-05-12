FLAGS = -Wall -Wextra -Werror -pedantic

bstree: bstree.o BSTNode.o pc27.o
	g++ $(FLAGS) bstree.o BSTNode.o pc27.o -o bstree

bstree.o: BSTNode.o bstree.h bstree.cpp
	g++ -c $(FLAGS) bstree.cpp -o bstree.o

pc27.o: pc27.cpp
	g++ -c $(FLAGS) pc27.cpp -o pc27.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	rm -f *.o

cleanall: clean
	rm -f bstree
	
