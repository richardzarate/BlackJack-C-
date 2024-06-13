/* Hearts.h - The Hearts class is a child class of the Card class. It represents the Hearts suite of cards.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Contains member functions and a few overridden functions from the Card class.
 * Algorithm:
 *     1.  The Hearts class is a child class that represents 1 of the 4 suites of cards.
 *     2.  Contain member functions and a few overridden functions from the Card class.
 *     3.  The createSuiteCards() function will create a stack of 13 cards that represent the Hearts suite.
 */
#include <iostream>
#include <stack>
#include <vector>
#include "Card.h"

#ifndef HEARTS_H
#define HEARTS_H

using namespace std;

class Hearts : public Card {
public:
    //constructor that uses the parent class constructor
    Hearts(const string& name, int value, string s) : Card(name, value, s) {};
    //default constructor
    Hearts() : Card("", 0, ""){};
    //getter for the name variable that is overridden
    virtual string getName() {
        return this->name + " of Hearts";
    }
    //getter for the value variable
    virtual int getValue() {
        return this->value;
    }
    //creates a stack of 13 cards that represent the hearts suite
    stack<Hearts> createSuiteCards(){
        vector<int> numCards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //a vector that represents the 13 different cards in a suite
        stack<Hearts> suiteDeck; //stack to contain the 13 cards in the Hearts suite
        
        //creates a stack of 13 cards that represent the hearts suite
        for (int c : numCards) {
            if (c == 1) {
                suiteDeck.push(Hearts("Ace of Hearts", 11, "H"));
            }
            else if (c == 11) {
                suiteDeck.push(Hearts("Jack of Hearts", 10, "H"));
            }
            else if (c == 12) {
                suiteDeck.push(Hearts("Queen of Hearts", 10, "H"));
            }
            else if (c == 13) {
                suiteDeck.push(Hearts("King of Hearts", 10, "H"));
            }
            else {
                suiteDeck.push(Hearts(to_string(c) + " of Hearts", c, "H"));
            }
        }
        //return the stack of 13 cards
        return suiteDeck;
    }
// Destructor implementation to free any resources
  virtual ~Hearts() {}

};


#endif