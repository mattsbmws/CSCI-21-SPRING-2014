FLAGS = -Wall -Wextra -Werror -pedantic

all: project1 pc1 pc2 pc3 pc4 pc5 pc6 pc7 pc8 pc9

project1: Project_1/project1

Project_1/project1: Project_1/project1.cpp
	g++ $(FLAGS) Project_1/project1.cpp -o Project_1/project1

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
	
pc6: Challenge_6/pc6

Challenge_6/pc6: Challenge_6/pc6.cpp
	g++ $(FLAGS) Challenge_6/pc6.cpp -o Challenge_6/pc6
	
pc7: Challenge_7/pc7

Challenge_7/pc7: Challenge_7/pc7.cpp
	g++ $(FLAGS) Challenge_7/pc7.cpp -o Challenge_7/pc7

pc8: Challenge_8/pc8

Challenge_8/pc8: Challenge_8/pc8.cpp
	g++ $(FLAGS) Challenge_8/pc8.cpp -o Challenge_8/pc8
	
pc9: Challenge_9/pc9

Challenge_9/pc9: Challenge_9/pc9.cpp
	g++ $(FLAGS) Challenge_9/pc9.cpp -o Challenge_9/pc9