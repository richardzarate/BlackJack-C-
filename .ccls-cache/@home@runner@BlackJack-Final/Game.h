//This class for handling an entire game of blackjack

#include <iostream>
#include <vector>
#include <stack>
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

#ifndef GAME_H
#define GAME_H
class Game{
    private:
        Dealer dealer;
        Player player;
        stack<Card> current_deck;

    public:
        Game(){
            Deck game_deck = Deck();
            dealer = Dealer("Dealer");
            player = Player("Player1");
            stack<Card> current_deck = game_deck.getDeck();
        };

        void run_game(){
            cout << "Running game..." << endl;
            bool dealer_end_turn = false;
            vector<int> player_hand_values;

            cout << "test 1" << endl;
            for(int i = 0; i < 2; i++){
                cout <<"Test a" << endl;
                dealer.start_hand(current_deck.top());
                current_deck.pop();
                cout << "Test b" << endl;
                player.start_hand(current_deck.top());
                current_deck.pop();
            }
            cout << "Test2" << endl;
            player_hand_values = player.move(current_deck);
            dealer_end_turn = dealer.move(current_deck);

            if(dealer_end_turn && !player_hand_values.empty()){
                if(player_hand_values[0] > dealer.get_hand_value()){
                    cout << "Player wins!" << endl;
                }
                else{
                    cout << "Dealer wins!" << endl;
                }
            }
        }
};


#endif
