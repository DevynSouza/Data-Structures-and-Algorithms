#pragma once
#include <iostream>
#include "CommandManager.hpp"
#include "ActorFactory.hpp"
#include "BattleMoveFactory.hpp"
#include "Enum.hpp"




class Battle
  {
    private:
      CommandManager undoManager;
      Actor* player; 
      Actor* enemy; 

    public:
      Battle(ActorType actor1, ActorType actor2) {
        player = ActorFactory::CreateActor(actor1);
        enemy = ActorFactory::CreateActor(actor2);
      }

      void Start();  
      int PlayerTurn();
      int NpcTurn(int pmove);
  }; 