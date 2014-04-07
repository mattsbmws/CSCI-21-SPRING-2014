FLAGS = -Wall -Wextra -Werror -pedantic

SLNode: SLNode.o
	g++ $(FLAGS) SLNode.o -o SLNode

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

clean:
	rm -f *.o

cleanall: clean
	rm -f SLNode