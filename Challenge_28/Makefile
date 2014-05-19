FLAGS = -Wall -Wextra -Werror -pedantic

pc28: pc28.cpp item.o fooditem.o magicitem.o
	g++ $(FLAGS) pc28.cpp item.o fooditem.o magicitem.o -o pc28
	
item.o: item.cpp item.h
	g++ -c $(FLAGS) item.cpp -o item.o
	
fooditem.o: fooditem.cpp fooditem.h
	g++ -c $(FLAGS) fooditem.cpp -o fooditem.o
	
magicitem.o: magicitem.cpp magicitem.h
	g++ -c $(FLAGS) magicitem.cpp -o magicitem.o

clean:
	rm -f *.o

cleanall: clean
	rm -f pc28
