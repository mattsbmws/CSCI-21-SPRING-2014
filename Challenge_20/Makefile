FLAGS = -Wall -Wextra -Werror -pedantic

SList: SList.o pc20.o SLNode.o
	g++ $(FLAGS) SList.o pc20.o SLNode.o -o SList

pc20.o: pc20.cpp
	g++ -c $(FLAGS) pc20.cpp -o pc20.o

SList.o: SList.cpp SList.h
	g++ -c $(FLAGS) SList.cpp -o SList.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
	
clean:
	rm -f *.o

cleanall: clean
	rm -f SList
	
