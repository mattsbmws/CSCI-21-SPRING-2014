#pragma once

/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Prize Header
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/11/2014
 *
 * CinReader by J. Boyd Trolinger
 */

#include <iostream>
#include <string>
using namespace std;


class Prize {
    public:
        /* 
         * The default constructor.
         * Initializes prizeName to "NO NAME" and prizeValue to 0.
         */
        Prize();
        
        /*
         * The overloaded constructor.
         * Initlizes prizeName and prizeValue to the values passed in.
         * @param name a string containing the new name for prizeName.
         * @param value an unsigned int containing the new value for prizeValue. 
         */
        Prize(string name, unsigned int value);
        
        /*
         * The destructor.
         */
        ~Prize();
        
        /*
         * Sets prizeName to the value passed in.
         * @param newName a string containing the new value for prizeName.
         */
        void setPrizeName(string newName);
        
        /*
         * Retrieves the current name of a prize.
         * @return the string stored in prizeName.
         */
        string getPrizeName() const;
        
        /*
         * Sets prizeValue to the value passed in.
         * @param newValue an unsigned int containing the new value for prizeValue.
         */
        void setPrizeValue(unsigned int newValue);
        
        /*
         * Retrieves the current value of a prize.
         * @return the unsigned int stored in prizeValue.
         */
        unsigned int getPrizeValue() const;
        
        /*
         * Overloaded operator == to compare two prizes.
         * @param prizeOne first prize object to compare.
         * @param prizeTwo second prize object to compare.
         * @return true if both objects have the same name and value, otherwise false.
         */
        friend bool operator== (Prize prizeOne, Prize prizeTwo);
        
    private:
        string prizeName;
        unsigned int prizeValue;
};
