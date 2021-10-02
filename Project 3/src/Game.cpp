#include "Game.hpp"
#include "Battle.hpp"

void Game::Begin() {
    cout << "Hello There";
    ActorType player;
    ActorType enemy;
    bool exit = false; 
    cout << "Quick disclaimer! \nFor some reason only my sword attack class works. \nAlso sometimes the game doesn't like to recognize dead people. \nIn leiu of that I have removed the other options and there is 1 attack and 1 undo. The stack works." << endl;
    cout << "\nWelcome to the Undo Game!" << endl;
    while (!false) {
        int choice;
        bool playerPick = false;
        while(!playerPick) {
            cout << "Pick a character! " << endl;
            cout << "1. Ghost \n2. Knight" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Ghost picked!\n" << endl;
                player = Ghost; //WHYYYYYYYYYYYYYYYYY
                playerPick = true;
            } else if(choice == 2) {
                cout << "Knight picked!\n" << endl;
                player = Knight;
                playerPick = true;
            } else if(choice != 1 || choice != 2) {
                cout << "Please choose Knight or Ghost!"<< endl;
            }
        };//End of first pick while loop
       
        bool EnemyPick = false;
        
        while(!EnemyPick) {
            cout << "Please pick your opponents characer. " << endl;
            cout << "1. Ghost \n2. Knight" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Ghost picked!" << endl;
                enemy = Ghost;
                EnemyPick = true;
            } else if(choice == 2) {
                cout << "Knight picked! " << endl;
                enemy = Knight;
                EnemyPick = true;
            } else if(choice != 1 || choice != 2) {
                cout << "Please choose Knight or Ghost!" << endl;
            } 

        };
        Battle battle(player, enemy);
        battle.Start();
    } //end of while loop
    

};