#include "Battle.hpp"

void Battle::Start() { //For some reason I can't send 
    bool enemyDead = false;
    bool playerDead = false;
          while (!playerDead || !enemyDead) {    //player->IsDead() and enemy->IsDead() both don't always work and its annoying. Neither does this.
            int attack;
            cout << "\n\nYour current health: " << player->getHealth() <<endl; 
            cout << "Opponents health: " << enemy->getHealth() <<endl;
            attack = PlayerTurn();
            NpcTurn(attack);
            if(enemy->getHealth() < 1) {
                enemyDead = true;      //For some strange reason enemy isDead is not working. But player is....
                cout << "Opponent has died!" << endl;
            } else if (player->getHealth() < 1) {
                playerDead = true;
                cout << "You have died!" << endl;
            }
         } //End of while loop 
        
};

int Battle::PlayerTurn() {
    //Now I have to ask for the player to choose a move. Add that to the stack
            int choice;
            cout << "\nChoose your move! " << endl;
            cout << "1. Sword Attack" << endl;
            cout << "3. Curse Attack" << endl;
            cout << "\n2. Undo" << endl;
            cin >> choice;
switch (choice){
        case 1: 
          undoManager.Execute(BattleMoveFactory::BuildMove(Sword, player, enemy));
          break;
        case 2:
          undoManager.Undo();
          break;
        case 3: 
          undoManager.Execute(BattleMoveFactory::BuildMove(Spell, player, enemy));
          break;
        default:
          cout << "Please select a valid number. Undo automatically selected!" << endl;
          undoManager.Undo();
          break;
        }
        return choice;
      }

    int Battle::NpcTurn(int pmove) {
        cout << "Enemy's turn." << endl;
        srand(time(NULL));
        //int move = rand() % 4 + 1;
        int move = 1;               //For some reason if i switch the 
        switch (move){
        case 1: 
          undoManager.Execute(BattleMoveFactory::BuildMove(Sword, enemy, player));
          break;
        }
    }

    