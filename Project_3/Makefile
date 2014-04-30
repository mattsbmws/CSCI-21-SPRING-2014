FLAGS = -Wall -Wextra -Werror -pedantic

DLList: DLList.o project3.o DLNode.o
	g++ $(FLAGS) DLList.o project3.o DLNode.o -o DLList

project3.o: project3.cpp
	g++ -c $(FLAGS) project3.cpp -o project3.o

DLList.o: DLList.cpp DLList.h
	g++ -c $(FLAGS) DLList.cpp -o DLList.o

DLNode.o: DLNode.cpp DLNode.h
	g++ -c $(FLAGS) DLNode.cpp -o DLNode.o
	
clean:
	rm -f *.o

cleanall: clean
	rm -f DLList

