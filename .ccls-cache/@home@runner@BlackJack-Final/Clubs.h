/* Clubs.h - The Clubs class is a child class of the Card class. It represents the clubs suite of cards.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Contains member functions and a few overridden functions from the Card class.
 * Algorithm:
 *     1.  The Clubs class is a child class that represents 1 of the 4 suites of cards.
 *     2.  Contain member functions and a few overridden functions from the Card class.
 *     3.  The createSuiteCards() function will create a stack of 13 cards that represent the clubs suite.
 */
#include <iostream>
#include <stack>
#include <vector>
#include "Card.h"


#ifndef CLUBS_H
#define CLUBS_H

using namespace std;

class Clubs : public Card {
public:


    //constructor that uses the parent class constructor
    Clubs(const string& name, int value, string s) : Card(name, value, s) {};
    //default constructor
    Clubs() : Card("", 0, ""){};

    //getter for the name variable that is overridden
    virtual string getName() {
        return this->name + " of Clubs";
    }
    //getter for the value variable
    virtual int getValue() {
        return this->value;
    }

    //creates a stack of 13 cards that represent the clubs suite
    stack<Clubs> createSuiteCards(){
        vector<int> numCards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //a vector that represents the 13 different cards in a suite
        stack<Clubs> suiteDeck;//stack to contain the 13 cards in the Clubs suite

        //creates a stack of 13 cards that represent the clubs suite
        for (int c : numCards) {
            if (c == 1) {
                suiteDeck.push(Clubs("Ace of Clubs", 11, "C"));
            }
            else if (c == 11) {
                suiteDeck.push(Clubs("Jack of Clubs", 10, "C"));
            }
            else if (c == 12) {
                suiteDeck.push(Clubs("Queen of Clubs", 10, "C"));
            }
            else if (c == 13) {
                suiteDeck.push(Clubs("King of Clubs", 10, "C"));
            }
            else {
                suiteDeck.push(Clubs(to_string(c) + " of Clubs", c, "C"));
            }
        }
        //return the stack of 13 cards
        return suiteDeck;
    }

    // Destructor implementation to free any resources
      virtual ~Clubs() {}
};


#endif