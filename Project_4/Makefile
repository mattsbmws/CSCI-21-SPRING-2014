FLAGS = -Wall -Wextra -Werror -pedantic

bstree: BSTNode.h bstree.h word.o driver.o
	g++ $(FLAGS) word.o driver.o -o bstree
	
word.o: word.cpp word.h
	g++ -c $(FLAGS) word.cpp -o word.o

driver.o: driver.cpp
	g++ -c $(FLAGS) driver.cpp -o driver.o

clean:
	rm -f *.o

cleanall: clean
	rm -f bstree
