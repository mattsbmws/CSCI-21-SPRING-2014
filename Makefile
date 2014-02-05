all: pc1 pc2 pc3 pc4

pc1: Challenge_1/pc1.cpp
	g++ Challenge_1/pc1.cpp -o Challenge_1/pc1
  
pc2: Challenge_2/pc2.cpp
	g++ Challenge_2/pc2.cpp -o Challenge_2/pc2
  
pc3: Challenge_3/pc3.cpp
	g++ Challenge_3/pc3.cpp -o Challenge_3/pc3
	
pc4: Challenge_4/pc4.cpp
	g++ Challenge_4/pc4.cpp -o Challenge_4/pc4