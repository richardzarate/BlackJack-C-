/* Deck.h - The Deck class creates a Deck of cards
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Creates a deck from the 4 suite classes
 * Algorithm:
 *     1.  Create an instance for each of the 4 suite classes
 *     2.  Create a stack of cards for each of the 4 suites
 *     3.  Create a vector of cards that represents the deck
 *     4.  Randomly pick from the 4 stacks to add to the deck 1 by 1 until all cards are added
 *     5.  Save the created deck to the member variable
 */
#include <iostream>
#include <vector>
#include <stack>
#include <string>


#include "Hearts.h"
#include "Clubs.h"
#include "Diamonds.h"
#include "Spades.h"

using namespace std;

#ifndef DECK_H
#define DECK_H

static const int DECK_SIZE = 52; //the size of the deck

class Deck {
private:
    stack<Card> new_deck; //stack of cards that represents the deck
public:
    //constructor that creates a deck of cards
    Deck() {
        new_deck = createShuffledDeck(); //create a shuffled deck of cards
    }
    //getter that returns a deck of cards
    stack<Card> getDeck(){
        return new_deck;
    }
    //displays the deck of cards created but also deletes them once done
    void display() {
        int count = 1;
        while (!new_deck.empty()) {
            cout << count << ": " << new_deck.top().getName() << endl;
            new_deck.pop();
            count++;
        }
    }
private:
    //helper function that creates a shuffled deck of cards
    stack<Card> createShuffledDeck() {
        srand(time(0)); //seed the random number generator

        int current_deck_size = 0; //starting size of the deck

        //instances of the 4 suites
        Spades s = Spades();
        Hearts h = Hearts();
        Clubs c = Clubs();
        Diamonds d = Diamonds();
        //create a stack of cards for each of the 4 suites
        stack<Spades> spades = s.createSuiteCards();
        stack<Hearts> hearts = h.createSuiteCards();
        stack<Clubs> clubs = c.createSuiteCards();
        stack<Diamonds> diamonds = d.createSuiteCards();

        //create a stack that can hold all the cards
        stack<Card> current_deck;
    
        while (current_deck_size < DECK_SIZE) {//check and make sure that all cards are added to the deck
            int random_suite = (rand() % 4) + 1; //generates random number from 1-4 that will pick the stack to pull from and add to the deck stack
            //once a suite is picked, take the top of that suite's stack and add it to the deck stack
            if (random_suite == 1 && !spades.empty()) {
                current_deck.push(spades.top());
                spades.pop();
                current_deck_size++;
            }
            else if (random_suite == 2 && !hearts.empty()) {
                current_deck.push(hearts.top());
                hearts.pop();
                current_deck_size++;
            }
            else if (random_suite == 3 && !clubs.empty()) {
                current_deck.push(clubs.top());
                clubs.pop();
                current_deck_size++;
            }
            else if (random_suite == 4 && !diamonds.empty()) {
                current_deck.push(diamonds.top());
                diamonds.pop();
                current_deck_size++;
            }
        }
        return current_deck; //return the deck stack
    }



};

#endif