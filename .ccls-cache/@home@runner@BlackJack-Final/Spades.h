/* Spades.h - The Spades class is a child class of the Card class. It represents the Spades suite of cards.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Contains member functions and a few overridden functions from the Card class.
 * Algorithm:
 *     1.  The Spades class is a child class that represents 1 of the 4 suites of cards.
 *     2.  Contain member functions and a few overridden functions from the Card class.
 *     3.  The createSuiteCards() function will create a stack of 13 cards that represent the Spades suite.
 */
#include <iostream>
#include <stack>
#include <vector>
#include "Card.h"

#ifndef SPADES_H
#define SPADES_H

using namespace std;

class Spades : public Card {
public:

    //constructor that uses the parent class constructor
    Spades(const string& name, int value, string s) : Card(name, value, s) {};

    //default constructor
    Spades() : Card("", 0, ""){}

    //getter for the name variable that is overridden
    virtual string getName() {
        return this->name + " of Spades";
    }
    //getter for the value variable
    virtual int getValue() {
        return this->value;
    }
    //creates a stack of 13 cards that represent the Spades suite
    stack<Spades> createSuiteCards(){
        vector<int> numCards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};//a vector that represents the 13 different cards in a suite
        stack<Spades> suiteDeck;//stack to contain the 13 cards in the Spades suite

        //creates a stack of 13 cards that represent the Spades suite
        for (int c : numCards) {
            if (c == 1) {
                suiteDeck.push(Spades("Ace of Spades", 11, "S"));
            }
            else if (c == 11) {
                suiteDeck.push(Spades("Jack of Spades", 10, "S"));
            }
            else if (c == 12) {
                suiteDeck.push(Spades("Queen of Spades", 10, "S"));
            }
            else if (c == 13) {
                suiteDeck.push(Spades("King of Spades", 10, "S"));
            }
            else {
                suiteDeck.push(Spades(to_string(c) + " of Spades", c, "S"));
            }
        }
        //return the stack of 13 cards
        return suiteDeck;
    }
    
    // Destructor implementation to free any resources
      virtual ~Spades() {}
    
};


#endif