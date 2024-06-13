/* Person.h - An abstract class that represents a person. The parent class for both the Dealer and Player classes.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Contains one pure virtual function to be overwritten by the child classes.
 * Algorithm:
 *     1.  Contain one pure virtual function to be overwritten by the child classes.
 */
#include <iostream>
#include "Deck.h"
#include <stack>

#ifndef PERSON_H
#define PERSON_H

using namespace std;
//An abstract class that represents a person. This will be a parent class for both dealer and player
class Person{
    public:
        //pure virtual function that will be overridden in the child classes
        virtual void show_hand(vector<Card> &main_hand, int &hand_val) const = 0;
};

#endif