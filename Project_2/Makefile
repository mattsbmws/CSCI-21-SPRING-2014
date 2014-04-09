FLAGS = -Wall -Wextra -Werror -pedantic

project2: prize.o box.o project2.o CinReader.o
	g++ $(FLAGS) prize.o box.o project2.o CinReader.o -o project2

project2.o: project2.cpp
	g++ -c $(FLAGS) project2.cpp -o project2.o

box.o: box.h box.cpp
	g++ -c $(FLAGS) box.cpp -o box.o

prize.o: prize.h prize.cpp
	g++ -c $(FLAGS) prize.cpp -o prize.o

CinReader.o: CinReader.h CinReader.cpp
	g++ -c $(FLAGS) CinReader.cpp -o CinReader.o
	
clean:
	rm -f *.o

cleanall: clean
	rm -f project2