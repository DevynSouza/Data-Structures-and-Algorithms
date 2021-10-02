#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Enum.hpp"
using namespace std;

class Actor {
      private:
        string type;
      protected:
        int health;
        vector<MoveType> moves = {Spell,Curse, Sword, Melee};
      public:
          Actor(int health, string type) :
              health{ health },
              type{ type }
          {}
          virtual void Hit(int damage) {
              this -> health = health - damage;
          }
          virtual void Heal(int amount) {
              this -> health = health + amount;
          }
          int getHealth() {return health;}
          const vector<MoveType>& GetMoves() const {
              return moves;
          }

          bool IsDead() { return health <= 0; } //This don't wont
          friend ostream& operator<<(ostream& out, const Actor& actor){};
};



class GhostActor: public Actor {
    public: 
        GhostActor(int health, string type):Actor(health, type){};
    

}; 

class KnightActor: public Actor {
    public:
        KnightActor(int health, string type):Actor(health, type){};
};
