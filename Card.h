/* Card.h - The Card class is a parent class to the Hearts, Clubs, Diamonds, and Spades classes.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Contains the member variables and methods for the Card class that will be in the child classes.
 * Algorithm:
 *     1.  The Card class is a parent class to the Hearts, Clubs, Diamonds, and Spades classes
 *     2.  Contain member variables for the name(string), value(int), and suite of the card(string)
 *     3.  Contains a contructor, a copy contructor, getters, setters, and a destructor
 */
#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card{
    protected:
        string name, suite; //name of the card represents the full name of the card like "Ace of Spades" and suite represents the suite of the card like Spades would be represented as an "S"
        int value; //value of the card, can be 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, and 11


    public:

        //constructor
        Card(const string& n, int v, string s) : name(n), suite(s), value(v)  {};

        //copy constructor
        Card(const Card& copy) : name(copy.name), suite(copy.suite), value(copy.value)  {} 

        //getters
        virtual string getName() {
            return name;
        };

        virtual int getValue() {
            return value;
        };

        virtual string getSuite(){
            return suite;
        }

        //setters
        void setValue(int val) {
            this->value = val;
        }

        void setName(string& name) {
            this->name = name;
        }
        //destructor
        virtual ~Card(){}
};




#endif