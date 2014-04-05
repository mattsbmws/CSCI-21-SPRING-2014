#pragma once

/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Prize Header
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/04/2014
 *
 * CinReader by J. Boyd Trolinger
 */


#include <iostream>
#include <string>
using namespace std;


class Prize {
    public:
        Prize();
        Prize(string name, unsigned int value);
        ~Prize();
        void setPrizeName(string newName);
        string getPrizeName() const;
        void setPrizeValue(unsigned int newValue);
        unsigned int getPrizeValue() const;
        friend bool operator== (Prize prizeOne, Prize prizeTwo);
        
    private:
        string prizeName;
        unsigned int prizeValue;
};
