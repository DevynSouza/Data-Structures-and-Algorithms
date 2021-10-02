#pragma once
#include <iostream>
#include "Actor.hpp"
#include "Enum.hpp"
using namespace std;

class UndoableCommand
  {
    public:
      virtual void Execute()=0;
      virtual void Undo()=0;
  };
  
class BattleMove : public UndoableCommand {
  public:
      BattleMove(Actor* self, Actor* other)
          :self{ self },
          other{ other }
      {}

  protected:
      Actor* self;
      Actor* other;
  };

  

  class CurseAttack: public BattleMove {
      public:
        int damage;
        CurseAttack(Actor* player, Actor* enemy):BattleMove(self, other){
          this->self = player;
          this->self = enemy;
        }
        void Execute() {
          srand(time(NULL));
          damage = rand() % 10;
          other -> Hit(damage);
        }
        void Undo() {
          other -> Heal(damage);
  
        }
  };

  class SwordAttack: public BattleMove {
      public:
        int damage;
        SwordAttack(Actor* player, Actor* enemy):BattleMove(self, other){
            this->self = player;
            this->other = enemy;
        }
        void Execute() {
          srand(time(NULL));
          damage = rand() % 10;
          other -> Hit(damage);         //For some reason I can't use cout with other and self or it seg faults
        }                               //But the other options all seg fault too.
        void Undo() {
          other -> Heal(damage);
  
        }
      
  };
  
  class SpellAttack: public BattleMove {
      public:
        int damage;
        SpellAttack(Actor* player, Actor* enemy):BattleMove(self, other){
          this->self = player;
          this->other = enemy;
        }
        void Execute() {
          srand(time(NULL));
          damage = rand() % 10;
          other -> Hit(damage);
        }
        void Undo() {
          other -> Heal(damage);
  
        }
  };

  class MeleeAttack: public BattleMove {
      public:
        int damage; 
        MeleeAttack(Actor* player, Actor* enemy):BattleMove(self, other){
          this->self = player;
          this->other = enemy;
        }
        void Execute() {
          srand(time(NULL));
          damage = rand() % 10;
          other -> Hit(damage);
        }
        void Undo() {
          other -> Heal(damage);
  
        }
  };