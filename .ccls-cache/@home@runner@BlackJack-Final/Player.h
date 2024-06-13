/* Player.h - Represents the player in the game.
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Gives the player the ability to hit, stand, and split.
 * Algorithm:
 *     1.  The player should have a function that will allow the player to receive cards at the beginning of the game.
 *     2.  The player should have a function that will allow the player to hit.
 *     3.  The player should have a function that will allow the player to stand.
 *     4.  The player should have a function that will allow the player to split.
 *     5.  The player would have a function that will ask them what action to take. Hit, stand, and split. If they bust it will automatically stand.
 *     6.  The player would have a function that checks the value of the cards in their hand and automatically adjuasts the value of the hand if they have an ace.
 *     7.  The player would have a function that updates hand value each hit
 *     8.  The player would have a function that would display their hand
 */
#include <iostream>
#include <vector>
#include "Person.h"
#include "Deck.h"
#include "InvalidInputException.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
class Player : public Person{
    private:
        string name; //name of the player
        vector<Card> hand, split_hand; //container for the actual hand, and a split hand
        int hand_value, split_hand_value; //value of the hand and split hand

    public:
        //default construtor
        Player(){
            Player("");
        }
        //constructor that takes in a name, initializes the hand and hand value, and sets the name
        Player(string name){
            this->name = name;
            hand = vector<Card>();
            hand_value = 0;
        }
        //move function, does the heavy lifting to allow the player to make a move
        vector<int> move(stack<Card> &game_deck){
            //variable for player option, 
            //and the main_hand_value which is the value of either the split hand or the actual hand
            int option = 0, main_hand_value = hand_value; 
            //split_possible is for when it is possible to split the hand, 
            //split is for when the hand is already split, 
            //display_split_hand is for when the split hand can be displayed, 
            //and turn_end is for when the player can't take anymore turns
            bool split_possible = false, split = false, display_split_hand = false, turn_end = false; 
            vector<Card> main_hand = hand; //main hand can either be the split hand or the actual hand
            vector<int> hand_vals = vector<int>(); //hand_vales is for when saving the hand values at the end of the player's turn
            //checks if the player hand can be split
            if(main_hand.size() == 2){
                if(main_hand[0].getName()[0] == main_hand[1].getName()[0]){//if the two cards have the same value, then it's possible to split
                    split_possible = true;
                }
            }
            //loop through as the player make their moves
            do{
                //print the current hand
                cout << "Your hand: ";
                show_hand(hand, hand_value);
                cout << endl;
                //if there's a split hand, print it
                if(display_split_hand){
                    cout << "Your split hand: ";
                    show_hand(split_hand, split_hand_value);
                    cout << endl;
                }
                //ask the player what they want to do
                cout << "What would you like to do?" << endl;
                cout << "1. Hit" << endl;
                cout << "2. Stand" << endl;
                //if it's possible to split, show an option to split
                if(split_possible){
                    cout << "3. Split" << endl;
                }

                cout << "-----------------------------------------------------------------" << endl;
                cout << endl;
                cout << "Input: ";
                cin >> option;
                if (cin.fail()) {//if the input is not an integer, throw an exception
                    cin.clear(); // Clear the error state
                    throw InvalidInputException();
                }
                cin.ignore();//ignore any other characters in the input stream

                switch(option){
                    case 1:

                        hit(game_deck, main_hand, main_hand_value); //hit updates the main_hand and main_hand_value variables, as well as the game_deck
                        
                        //check if the player busted
                        if(main_hand_value > 21){
                            if(!split){//if there is no split hand, then the player busted
                                cout << "You busted!" << endl;
                                hand = main_hand; //update the hand to the main hand in play
                                hand_value = main_hand_value; //update the hand value to the main hand value in play
                                //print the hand that is busted
                                cout << "Your hand: "; 
                                show_hand(hand, hand_value);
                                cout << endl;

                                turn_end = true; //end the turn
                            }
                            else if(split){//if there is a split hand, switch the hand to the split hand
                                split_hand = main_hand; //update the split hand to the main hand in play
                                split_hand_value = main_hand_value; //update the split hand value to the main hand value in play
                                //print the split hand that is busted
                                cout << "Your split hand: ";
                                show_hand(split_hand, split_hand_value);
                                cout << endl;
                                turn_end = stand();//end the turn
                                
                                break;
                            }
                            //if there is a split hand to display, then there is a split hand to switch to
                            if(display_split_hand){
                                cout << "Switching to split hand..." << endl;
                                main_hand = split_hand; //the main hand is now the split hand
                                main_hand_value = split_hand_value; //the main hand value is now the split hand value
                                split = true; //the is a split that happened
                            }
                            //if there is no split hand then the turn ends
                            else{
                                turn_end = true;
                                break;
                            }
                        }
                        //if there is no split then just update the hand and hand value to the current hand in play
                        if(!split){
                            hand = main_hand;
                            hand_value = main_hand_value;
                            break;
                        }
                        //otherwise update the split hand and split hand value to the current hand in play
                        else{
                            split_hand = main_hand;
                            split_hand_value = main_hand_value;
                            break;
                        }
                        break;
                    case 2:
                        //check if player is choosing to stand the split hand
                        if(split){
                            turn_end = stand();
                            break;
                        }
                        //if there is a split hand to display, then there is a split hand to switch to
                        if(display_split_hand){

                            cout << "Switching to split hand..." << endl;
                            main_hand = split_hand;
                            main_hand_value = split_hand_value;
                            split = true;
                        }
                        //otherwise if there is no split, then the turn ends
                        else{
                            turn_end = stand();
                            break;
                        }
                    //if split is possible, then give the player the option to split
                    if(split_possible){
                        case 3:
                        //if people still chose option 3 without it being available, handle it
                        if(!split_possible){
                            cout << "Invalid option. Please try again." << endl << endl;
                            break;
                        }
                        cout << "Splitting hand..." << endl;
                        Player::split();
                        main_hand = hand;
                        display_split_hand = true;
                        split_possible = false;
                        break;
                    }
                    default:
                        cout << "Invalid option. Please try again." << endl << endl;
                        break;
                }

                
                
                

            }while(!turn_end);
            //after the player ends their move, either by busts or standing, then save the hand values
            hand_vals.push_back(hand_value);
            if(split_hand_value != 0){
                hand_vals.push_back(split_hand_value);
            }

            
            return hand_vals;//return the vector of hand values
            
        }
        //function for the beginning of the game where the player receives two cards, to be used in a for loop
        void start_hand(Card c){
            //if player is already holding an ace, and the other card is also an ace, set the value of one of the ace to 1
            if(hand_value >= 11 && c.getValue() == 11){
                c.setValue(1);
            }
            hand.push_back(c);//add the latest card to the hand
            updateValue(hand, hand_value);//update the value of the hand
            
        }

        //displays the current hand
        virtual void show_hand(vector<Card> &main_hand, int &hand_val) const{
            //go through the hand
            for(Card c : main_hand){
                //check if the value is 10 and it's not one of the royal cards
                if(c.getValue() == 10 && (c.getName()[0] != 'J' && c.getName()[0] != 'Q' && c.getName()[0] != 'K')){
                    //if it's not, then it's a 10 of something, so print the first two letters of its name and its suite
                    cout << "[" << c.getName().substr(0, 2) << c.getSuite() << "] ";
                }
                else{
                    //otherwise just print the first letter of the name and its suite
                    cout << "[" << c.getName()[0] << c.getSuite() << "] ";
                }
                
            }
            //print the hand value
            cout << endl << "This hand's value: " << hand_val << endl;
        }

        

    //helper functions
    private:
        //function that will allow the player to hit
        void hit(stack<Card> &game_deck, vector<Card> &main_hand, int &main_hand_value){
            //take the top of the deck
            Card card = game_deck.top();
            game_deck.pop();
            //check if the pulled card is an ace and if the current hand value would bust
            if(main_hand_value > 10 && card.getValue() == 11){
                card.setValue(1); //if it is, then that ace's value would be 1
            }
            main_hand.push_back(card);//once all checks are done, add the card to the hand
            updateValue(main_hand, main_hand_value);//update the hand value
        }
        //function that will allow the player to stand, returns true
        bool stand() const{
            return true;
        }
        //function that will allow the player to split
        void split(){
            //initialize the split_hand and split_hand_value
            split_hand_value = 0;
            split_hand = vector<Card>();
            //if the hand has two aces, check if their value has been set to 1 and set it back to 11
            if(hand[0].getValue() == 1){
                hand[0].setValue(11);
            }
            if(hand[1].getValue() == 1){
                hand[1].setValue(11);
            }
            //take the first card and add it to the split hand
            split_hand.push_back(hand[0]);
            hand.erase(hand.begin());

            //update main hand
            updateValue(hand, hand_value);


            //update split hand
            updateValue(split_hand, split_hand_value);
            
        }
        //function that will update the hand value
        void updateValue(vector<Card> &hand, int &held_value){
            held_value = 0;//reset the held value so that it doesn't accidentally add to the previous hand value
            //go through each card in the hand and add their values to the held value
            for(Card c : hand){
                held_value += c.getValue();
            }
        }
};


#endif