/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Box Implementation
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/04/2014
 *
 * CinReader by J. Boyd Trolinger
 */

#include "box.h"

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

Box::Box()
:boxNumber(0), boxColor("NO COLOR"), prizeCapacity(5), prizeCount(0) {
    prizes = new Prize[prizeCapacity];
}

Box::Box(unsigned int number, string color, unsigned int capacity)
:boxNumber(number), boxColor(color), prizeCapacity(capacity), prizeCount(0) {
    prizes = new Prize[prizeCapacity];
}

Box::~Box() {
    delete [] prizes;
}

void Box::setBoxNumber(unsigned int newNumber) {
    boxNumber = newNumber;
}

unsigned int Box::getBoxNumber() const {
    return boxNumber;
}

void Box::setBoxColor(string newColor) {
    boxColor = newColor;
}

string Box::getBoxColor() const {
    return boxColor;
}

unsigned int Box::getPrizeCapacity() const {
    return prizeCapacity;
}

unsigned int Box::getPrizeCount() const {
    return prizeCount;    
}

bool Box::addPrize(Prize thePrize) {
    if (prizeCount < prizeCapacity) {
        prizes[prizeCount++] = thePrize;
        return true;
    }
    else {
        return false;
    }
}

Prize& Box::getPrize(unsigned int index) {
    if (index >= prizeCapacity) {
        return scratch;
    }
    else {
        return prizes[index];
    }
}

Prize Box::removePrize(unsigned int index) {
    if (index >= prizeCapacity) {
        return scratch;
    }
    else if (prizeCount == 0) {
        return scratch;
    }
    else {
        Prize holder = prizes[index];
        if (holder == scratch) {
            return holder;
        }
        prizes[index]=scratch;
        --prizeCount;
        for (unsigned int i = index; i < prizeCount; ++i) {
            prizes[i] = prizes[i+1];
        }
        return holder;
    }
}
