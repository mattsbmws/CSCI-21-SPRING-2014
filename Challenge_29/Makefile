FLAGS = -Wall -Wextra -Werror -pedantic

pc29: pc29.cpp treasurechest.o
	g++ $(FLAGS) pc29.cpp treasurechest.o -o pc29
	
treasurechest.o: treasurechest.cpp treasurechest.h 
	g++ -c $(FLAGS) treasurechest.cpp -o treasurechest.o

clean:
	rm -f *.o

cleanall: clean
	rm -f pc29
