FLAGS = -Wall -Wextra -Werror -pedantic

bstree: bstree.o BSTNode.o pc26.o
	g++ $(FLAGS) bstree.o BSTNode.o pc26.o -o bstree

bstree.o: BSTNode.o bstree.h bstree.cpp
	g++ -c $(FLAGS) bstree.cpp -o bstree.o

pc26.o: pc26.cpp
	g++ -c $(FLAGS) pc26.cpp -o pc26.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	rm -f *.o

cleanall: clean
	rm -f bstree
	
