#
# Grader comments 2014.02.13
#
# Oh no! I think you forgot to commit and push your
# source code for pc6. I have to give you a zero on
# this one, sorry. I don't think I can get away with
# sneaking points in for you. I don't want to get
# into trouble with Boyd. But talk to him directly and
# see if he'll grant you some leniency. --Rob
#
FLAGS = -Wall -Wextra -Werror -pedantic

all: pc1 pc2 pc3 pc4 pc5 pc6

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
