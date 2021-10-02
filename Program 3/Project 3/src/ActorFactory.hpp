#pragma once
#include "Actor.hpp"

class ActorFactory {
  public:
      static Actor* CreateActor(ActorType actorType) {
          Actor* actor = nullptr;
          switch (actorType) {
            case ActorType::Ghost:
                actor = new GhostActor(100, "Ghost"); 
                break;
            case ActorType::Knight:
                actor = new KnightActor(100, "Knight");
                break;
            }
          return actor; 
      }
  };
