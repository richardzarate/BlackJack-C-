/* main.cpp - Runs a BlackJack Game
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Runs a BlackJack Game between the user and a Dealer
 *
 * Algorithm:
 *     1.  Initiate the Deck, Dealer, and Player
 *     2.  Get the deck from the deck class
 *     3.  Print any instructions, messages, or guides
 *     4.  Try to handle the player move and dealer move
 *     5.  Catch any exceptions and print the error
 *     6.  If both player and dealer successfully ends their move, then analyze the results
 */
#include <iostream>
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include <stack>
#include <vector>

using namespace std;


void analyze_game(vector<int> player_hands, int dealer_hand); //analyzes the game once the turn of the player and the dealer ends

int main() {

  //Declaration and initialization of objects
  Deck new_deck = Deck(); //creates a deck of cards
  stack<Card> game_deck = new_deck.getDeck(); //retrieves the deck of cards and stores it in a stack
  vector<int> player_hand_values; //vector to store the final values of the player's hands after their turn
  Dealer game_dealer = Dealer("Bob"); //Dealer
  Player player1 = Player("Jim"); //player

  //deal the initial set of cards to the player and the dealer
  for(int i = 0; i < 2; i++) {
    game_dealer.start_hand(game_deck.top());
    game_deck.pop();
    player1.start_hand(game_deck.top());
    game_deck.pop();
  }
  //Welcome message
  cout << "Welcome to BlackJack!" << endl << endl;
  cout << "Your game will start shortly..." << endl << endl;
  //Quick guide for reading the cards
  cout << "Guide for Reading Cards: " << endl;
  cout << "Each time a card is drawn, it will be displayed as []." << endl;
  cout << "Each [] will contain a value and a suite." << endl;
  cout << "The value will have a number from 2-10 or J, Q, K, or A." << endl;
  cout << "The suite will be a letter from S for Spades, H for Hears, D for Diamonds, or C for Clubs." << endl;
  cout << "For example, if you picked 2 of Hearts, the [] would look like [2H]." << endl << endl;
  cout << "-----------------------------------------------------------------" << endl << endl;

  //display the initial hand of the dealer, since it's not the dealer's turn yet
  //it will only display one card in the dealer's hand
  game_dealer.display_hand();
  cout << endl << endl;

  //will try to run the player's inputs if unsuccessful, it will throw a custom exception and the program will end
  //if no exception is thrown, the program will continue until both the player and the dealer have finished their turns
  //after both finishes their turn, the program will analyze the game and print the results
  try{
    player_hand_values = player1.move(game_deck);
    game_dealer.move(game_deck);
    analyze_game(player_hand_values, game_dealer.get_hand_value());
  }
  catch(InvalidInputException e){
    cerr << e.what() << endl;
  }

}

//analyzes the game once the turn of the player and the dealer ends
//function takes in a vector of the player's hand values and the dealer's hand value
//it will print the results of the game
void analyze_game(vector<int> player_hands, int dealer_hand){
  //temp variable to temporarily store the first value in the player_hands vector
  int player_hand_value = player_hands.at(0);
  
  cout << "Analyzing game..." << endl;
  //display the current values that are being analyzed
  cout << "Player hand value: " << player_hand_value << endl;
  cout << "Dealer hand value: " << dealer_hand << endl;
  if(player_hand_value < 22){ //if the player didn't bust
    if(player_hand_value > dealer_hand){//check if the player's hand value is greater than the dealer's hand value
      cout << "Player wins!" << endl << endl;
    }
    else if(player_hand_value == dealer_hand){//check if the player's hand value is equal to the dealer's hand value
      cout << "Push! It's a tie between the player and the dealer!" << endl << endl;
    }
    else if(dealer_hand > 21){//check if the dealer busted
      cout << "Dealer busts! Player wins!" << endl << endl;
    }
    else{//otherwise, the dealer's hand value is greater than the player's hand value
      cout << "Dealer wins!" << endl << endl;
    }
  }
  else{//if the player busted
    cout << "Player busts! Dealer wins" << endl << endl;
  }

  if(player_hands.size() == 2){//if the player split their hand then do similar comparisons for the split hand value
    player_hand_value = player_hands.at(1); //put the split hand value into the player_hand_value variable to be compared to the dealer's hand value

    //display the values being compared
    cout << "Player split hand value: " << player_hand_value << endl;
    cout << "Dealer hand value: " << dealer_hand << endl;
    if(player_hand_value < 22){//check if the split hand didn't bust
      if(player_hand_value > dealer_hand){//check if the split hand value is greater than the dealer's hand value
        cout << "Player wins!" << endl;
      }
      else if(player_hand_value == dealer_hand){//check if the split hand value is equal to the dealer's hand value
        cout << "Push! It's a tie between the player and the dealer!" << endl;
      }

      else if(dealer_hand > 21){//check if the dealer busted
        cout << "Dealer busts! Player wins!" << endl << endl;
      }
      
      else{//otherwise, the dealer's hand value is greater than the split hand value
        cout << "Dealer wins!" << endl;
      }
      
    }

    else{//if the split hand busted
      cout << "Player busts! Dealer wins" << endl;
    }


  }

  
}