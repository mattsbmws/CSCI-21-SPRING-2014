FLAGS = -Wall -Wextra -Werror -pedantic

all: pc1 pc2 pc3 pc4 pc5

pc1: Challenge_1/pc1

Challenge_1/pc1: Challenge_1/pc1.cpp
	g++ $(FLAGS) Challenge_1/pc1.cpp -o Challenge_1/pc1
	
pc2: Challenge_2/pc2
  
Challenge_2/pc2: Challenge_2/pc2.cpp
	g++ $(FLAGS) Challenge_2/pc2.cpp -o Challenge_2/pc2
	
pc3: Challenge_3/pc3
  
Challenge_3/pc3: Challenge_3/pc3.cpp
	g++ $(FLAGS) Challenge_3/pc3.cpp -o Challenge_3/pc3

pc4: Challenge_4/pc4
	
Challenge_4/pc4: Challenge_4/pc4.cpp
	g++ $(FLAGS) Challenge_4/pc4.cpp -o Challenge_4/pc4

pc5: Challenge_5/pc5

Challenge_5/pc5: Challenge_5/pc5.cpp
	g++ $(FLAGS) Challenge_5/pc5.cpp -o Challenge_5/pc5
	