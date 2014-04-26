FLAGS = -Wall -Wextra -Werror -pedantic

SLNode: SLNode.o pc17.o
	g++ $(FLAGS) SLNode.o -o SLNode

pc17.o: pc17.cpp
	g++ -c $(FLAGS) pc17.cpp -o pc17.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

clean:
	rm -f *.o

cleanall: clean
	rm -f SLNode