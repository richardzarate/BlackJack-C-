/* Diamonds.h - The Diamonds class is a child class of the Card class. It represents the Diamonds suite of cards.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Contains member functions and a few overridden functions from the Card class.
 * Algorithm:
 *     1.  The Diamonds class is a child class that represents 1 of the 4 suites of cards.
 *     2.  Contain member functions and a few overridden functions from the Card class.
 *     3.  The createSuiteCards() function will create a stack of 13 cards that represent the Diamonds suite.
 */
#include <iostream>
#include <stack>
#include <vector>
#include "Card.h"

#ifndef DIAMONDS_H
#define DIAMONDS_H




using namespace std;

class Diamonds : public Card {
public:
    //constructor that uses the parent class constructor
    Diamonds(const string &name, int value, string s) : Card(name, value, s) {};

    //default constructor
    Diamonds() : Card("", 0, "") {};

    //getter for the name variable that is overridden
    virtual string getName() {
        return this->name + " of Diamonds";
    }

    //getter for the value variable
    virtual int getValue() {
        return this->value;
    }

    //creates a stack of 13 cards that represent the Diamonds suite
    stack<Diamonds> createSuiteCards(){
        vector<int> numCards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //a vector that represents the 13 different cards in a suite
        stack<Diamonds> suiteDeck; //stack to contain the 13 cards in the Diamonds suite
    
        //creates a stack of 13 cards that represent the Diamonds suite
        for (int c : numCards) {
            if (c == 1) {
                suiteDeck.push(Diamonds("Ace of Diamonds", 11, "D"));
            }
            else if (c == 11) {
                suiteDeck.push(Diamonds("Jack of Diamonds", 10, "D"));
            }
            else if (c == 12) {
                suiteDeck.push(Diamonds("Queen of Diamonds", 10, "D"));
            }
            else if (c == 13) {
                suiteDeck.push(Diamonds("King of Diamonds", 10, "D"));
            }
            else {
                suiteDeck.push(Diamonds(to_string(c) + " of Diamonds", c, "D"));
            }
        }

        //return the stack of 13 cards
        return suiteDeck;
    }
    // Destructor implementation to free any resources
    virtual ~Diamonds() {}
};


#endif