#ifndef SlotMachine_hpp
#define SlotMachine_hpp

#include "Reel.hpp"
#include "PayoutTable.hpp"
#include <stdio.h>
#include <vector>


class SlotMachine {
    private:
        Reel reel1;
        Reel reel2;
        Reel reel3;
    public:
        SlotMachine();
        vector<char> Spin();
};
#endif