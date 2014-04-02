FLAGS = -Wall -Wextra -Werror -pedantic

all: project1 pc1 pc2 pc3 pc4 pc5 pc6 pc7 pc8 pc9 pc10 pc11 pc12 pc13 pc14 pc15 pc16

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
	
pc10: Challenge_10/pc10

Challenge_10/pc10: Challenge_10/pc10.cpp
	g++ $(FLAGS) Challenge_10/pc10.cpp -o Challenge_10/pc10
	
pc11: Challenge_11/pc11

Challenge_11/pc11: Challenge_11/pc11.cpp
	g++ $(FLAGS) Challenge_11/pc11.cpp -o Challenge_11/pc11
	
pc12: Challenge_12/pc12

Challenge_12/pc12: Challenge_12/pc12.cpp
	g++ $(FLAGS) Challenge_12/pc12.cpp -o Challenge_12/pc12
	
pc13: Challenge_13/pc13

Challenge_13/pc13: Challenge_13/pc13.cpp
	g++ $(FLAGS) Challenge_13/pc13.cpp -o Challenge_13/pc13
	
pc14: Challenge_14/pc14

Challenge_14/pc14: Challenge_14/pc14.cpp
	g++ $(FLAGS) Challenge_14/pc14.cpp -o Challenge_14/pc14

pc15: Challenge_15/pc15

Challenge_15/pc15: Challenge_15/pc15.cpp
	g++ $(FLAGS) Challenge_15/pc15.cpp -o Challenge_15/pc15

pc16: Challenge_16/pc16

Challenge_16/pc16: Challenge_16/pc16.cpp
	g++ $(FLAGS) Challenge_16/pc16.cpp -o Challenge_16/pc16