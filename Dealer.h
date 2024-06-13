/* Dealer.h - Represents the Dealer in the game.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Gives the Dealer the ability to hit, stand, and split.
 * Algorithm:
 *     1.  The dealer should have a function that will allow the dealer to receive cards at the beginning of the game.
 *     2.  The dealer should have a function that will allow the dealer to hit.
 *     3.  The dealer should have a function that will allow the dealer to stand.
 *     4.  The dealer should have a function that will allow the dealer to split.
 *     5.  The dealer would have a function that would determine if they would hit or stand. If they bust it will automatically stand.
 *     6.  The dealer would have a function that checks the value of the cards in their hand and automatically adjuasts the value of the hand if they have an ace.
 *     7.  The dealer would have a function that updates hand value each hit
 *     8.  The dealer would have a function that would display their hand
 */
#include <iostream>
#include <vector>
#include <stack>
#include "Person.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

#ifndef DEALER_H
#define DEALER_H
class Dealer : public Person{
    private:
        string name; //name of the dealer
        vector<Card> hand; //hand of the dealer
        int hand_value; //value of the dealer's hand

        bool turn = false; //boolean for when it's the dealer's turn

    public:
        //default constructor
        Dealer(){
            Dealer("");
        }
        //constructor that takes in a name, sets the name and initializes the hand and hand_value
        Dealer(string name){
            this->name = name;
            hand = vector<Card>();
            hand_value = 0;
        }

        //getter for hand_value variable
        int get_hand_value() const{
            return hand_value;
        }


        //move function that will handle the move of the dealer
        //based on the rule that the dealer will hit if they have less than 17 and stand if they have 17 or more
        bool move(stack<Card> &game_deck){
            bool turn_end = false; //check for when the dealer's turn ends
            turn = true; //if the move function is called, it's the dealer's turn

            do{
                //check iif the dealer has less than 17
                if(hand_value >= 17){
                    turn_end = stand();
                }
                //otherwise continue hitting and display the hand
                else{

                    cout << endl << "Dealer hits." << endl;
                    hit(game_deck);
                    display_hand();
                }

            }while(!turn_end);
            cout << endl;
            return turn_end;

        }
        //function for the beginning of the game when the dealer receives two cards. Supposed to be used in a for-loop
        void start_hand(Card c){
            if(hand_value >= 11 && c.getValue() == 11){//check for aces, if one of the two cards is an ace, set one value to 1
                c.setValue(1);

            }
            //add the card to the dealer's hand and update hand value
            hand.push_back(c);
            updateValue(hand, hand_value);
        }
        //displays hand, uses the overridden show_hand helper function
        void display_hand(){
            show_hand(hand, hand_value);
        }
    //helper functions
    private:
        //allows the dealer to stand
        bool stand() const{
            return true;
        }
        //allows the dealer to hit
        void hit(stack<Card> &game_deck){
            //takes the top card in the game deck
            Card card = game_deck.top();
            game_deck.pop();

            //check if the card is an ace
            //if needed set the value of ace to 1
            if(hand_value > 10 && card.getValue() == 11){
                card.setValue(1);
            }
            //add the card to dealer's hand and update hand value
            hand.push_back(card);
            updateValue(hand, hand_value);
        }
        //shows dealer's hand
        virtual void show_hand(vector<Card> &main_hand, int &hand_val) const override{
            if(turn){
                //if it's the dealer's turn, then you can show all cards
                cout << "Dealer's hand: ";
                for(Card c : main_hand){
                    //checks if the value is 10 and if it's not one of the royal cards
                    if(c.getValue() == 10 && (c.getName()[0] != 'J' && c.getName()[0] != 'Q' && c.getName()[0] != 'K')){
                        //if it passes the check, then it's a 10 and print it and the suite of the card
                        cout << "[" << c.getName().substr(0, 2) << c.getSuite() << "] ";
                    }
                    else{
                        //otherwise print it like normal
                        cout << "[" << c.getName()[0] << c.getSuite() << "] ";
                    }

                }
                //display the hand value
                cout << endl << "Dealer Hand Value: " << hand_val << endl;
            }

    
            //if it's not the dealer's turn, then you can only show one card
            else{
                
                cout << "Dealer's hand: ";
                for(Card c : main_hand){
                    //checks if the value is 10 and if it's not one of the royal cards
                    if(c.getValue() == 10 && (c.getName()[0] != 'J' && c.getName()[0] != 'Q' && c.getName()[0] != 'K')){
                        //if it passes the check, then it's a 10 and print it and the suite of the card
                        cout << "[" << c.getName().substr(0, 2) << c.getSuite() << "] ";
                        break;
                    }
                    else{
                        //otherwise print it like normal
                        cout << "[" << c.getName()[0] << c.getSuite() << "] ";
                        break;
                    }

                }
                cout << "[?]" << endl;
            }
        }
        //update the hand value
        void updateValue(vector<Card> &hand, int &held_value){
            held_value = 0; //resets the hand value to 0 so that it doesn't accidentally add the value of the previous hand
            for(Card c : hand){
                held_value += c.getValue(); //go through each card in hand and add its values
            }
        }

};


#endif