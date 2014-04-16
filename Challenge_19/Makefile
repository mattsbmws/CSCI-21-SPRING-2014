FLAGS = -Wall -Wextra -Werror -pedantic

SList: SList.o pc19.o SLNode.o
	g++ $(FLAGS) SList.o pc19.o SLNode.o -o SList

pc19.o: pc19.cpp
	g++ -c $(FLAGS) pc19.cpp -o pc19.o

SList.o: SList.cpp SList.h
	g++ -c $(FLAGS) SList.cpp -o SList.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
	
clean:
	rm -f *.o

cleanall: clean
	rm -f SList
	
