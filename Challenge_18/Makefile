FLAGS = -Wall -Wextra -Werror -pedantic

SList: SList.o pc18.o SLNode.o
	g++ $(FLAGS) SList.o pc18.o SLNode.o -o SList

pc18.o: pc18.cpp
	g++ -c $(FLAGS) pc18.cpp -o pc18.o

SList.o: SList.cpp SList.h
	g++ -c $(FLAGS) SList.cpp -o SList.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
	
clean:
	rm -f *.o

cleanall: clean
	rm -f SList
	
