#ifndef Reel_hpp
#define Reel_hpp

#include <stdio.h>
#include <string>
#include "ReelNode.hpp"

class Reel {
    private:
        
        ReelNode* currentPos;
        ReelNode* head;
        int length;
        
        

    public:
        
        Reel(): currentPos{nullptr}, head{nullptr}, length{0}{}
        ~Reel();
        void MakeEmpty();
        void PutItem(Item item);
        Item GetItem(Item item);
        void DeleteItem(Item item);
        void ResetList();
        Item GetNextItem();
        int GetLength();


};
ostream& operator<<(ostream& os, Reel& o);

#endif /* Reel_hpp */