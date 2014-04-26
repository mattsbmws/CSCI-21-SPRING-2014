/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Prize Implementation
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/04/2014
 *
 * CinReader by J. Boyd Trolinger
 */

#include "prize.h"


Prize::Prize()
:prizeName("NO NAME"), prizeValue(0)
{}

Prize::Prize(string name, unsigned int value)
:prizeName(name), prizeValue(value)
{}

Prize::~Prize() {

}

void Prize::setPrizeName(string newName) {
    prizeName=newName;
}

string Prize::getPrizeName() const {
    return prizeName;
}

void Prize::setPrizeValue(unsigned int newValue) {
    prizeValue=newValue;
}

unsigned int Prize::getPrizeValue() const {
    return prizeValue;
}

bool operator== (Prize prizeOne, Prize prizeTwo) {
    if (prizeOne.prizeValue == prizeTwo.prizeValue && prizeOne.prizeName == prizeTwo.prizeName) {
            return true;
    }
    else {
        return false;
    }
}
