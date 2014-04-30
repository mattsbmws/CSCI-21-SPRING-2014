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
        prizes[index] = scratch;
        --prizeCount;
        for (unsigned int i = index; i < prizeCount; ++i) {
            prizes[i] = prizes[i+1];
        }
        return holder;
    }
}
