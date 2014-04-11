#pragma once

/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Box Header
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/04/2014
 *
 * CinReader by J. Boyd Trolinger
 */

#include "prize.h"
#include <iostream>
#include <string>
using namespace std;

/*
private data members: boxNumber (unsigned int), boxColor (string), scratch (Prize), prizes (Prize*, for dynamic array), prizeCapacity (unsigned int), prizeCount (unsigned int)
            public default constructor: initial values boxNumber (0), boxColor ("NO COLOR"), prizeCapacity (5), prizeCount(0); in the definition, prizes array must be initialized to match prizeCapacity
            public overloaded constructor: parameters for boxNumber, boxColor, prizeCapacity; in the definition, prizes array must be initialized to match prizeCapacity
            public destructor: free memory associated with prizes
            public accessors/gets AND mutators/sets for boxNumber, boxColor
            public accessor/get ONLY for data members prizeCapacity, prizeCount
            public addPrize: parameters prize (Prize), return value (bool); place prize in prizes array if there is space and return true, else return false
            public getPrize: parameters index (unsigned int), return value Prize&; return a Prize if index is valid, else return scratch (data member declared in class header)
            public removePrize: parameters index (unsigned int), return value Prize; remove and return Prize if index is valid, else return scratch (data member declared in class header)
*/


//
// Grader comments 2014.04.11
// Need full documentation on functions in headers.
// Deducted 10 points.
//
class Box {
    public:
        Box();
        Box(unsigned int number, string color, unsigned int capacity);
        ~Box();
        void setBoxNumber(unsigned int newNumber);
        unsigned int getBoxNumber() const;
        void setBoxColor(string newColor);
        string getBoxColor() const;
        unsigned int getPrizeCapacity() const;
        unsigned int getPrizeCount() const;
        bool addPrize(Prize newPrize);
        Prize& getPrize(unsigned int index);
        Prize removePrize(unsigned int index);
        
    
    private:
        unsigned int boxNumber;
        string boxColor;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
        Prize scratch;
        Prize* prizes;
};
