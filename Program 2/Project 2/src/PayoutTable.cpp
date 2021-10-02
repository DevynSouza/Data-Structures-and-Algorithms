#include "PayoutTable.hpp"

int PayoutTable::Payout(char result) {

    switch(result) {
        case 'A':
            return 6;
            break;
        case 'B':
            return 15;
            break;
        case 'C':
            return 50;
            break;
        case '7':
            return 500;
            break;
    }      
    return 0;
}