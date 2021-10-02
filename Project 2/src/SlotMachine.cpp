//generate spins and hold the data 

#include "SlotMachine.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

SlotMachine::SlotMachine() {
    srand(int(time(NULL)));
    char array[10] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', '7'}; 
        //Null terminator is being weird sometimes its a part of the array sometimes its not. I don't get

    random_shuffle(&array[0], &array[10]);
    for(int i = 0; i < 10; i++) {
        string temp;
        temp = array[i];
        reel1.PutItem(Item(temp)); //Putting into the linked list
    }

    random_shuffle(&array[0], &array[10]);
    for(int i = 0; i < 10; i++) {
        string temp;
        temp = array[i];
        reel2.PutItem(Item(temp));
    }

    random_shuffle(&array[0], &array[10]); 
    for(int i = 0; i < 10; i++) {
        string temp;
        temp = array[i];
        reel3.PutItem(Item(temp));
    }
}
//Lets go back and rework this
vector<char> SlotMachine::Spin() {
    vector<char> reelVal;
    srand((int)time(NULL));
    int rSelector1 = rand() % 100; //Randomly assigns the index on the shuffled array for the shuffling to begin reading
    int rSelector2 = rand() % 100; //For some reason 10 adds in the null terminator but 100 doesnt?
    int rSelector3 = rand() % 100; //The null terminator is being weird
    
    Item item1;
    for(int i = 0; i < rSelector1; i++) {      
        item1 = reel1.GetNextItem();               
    }
    
    Item item2;
    for(int i = 0; i < rSelector2; i++) {
        item2 = reel2.GetNextItem();
    }
    
    Item item3;
    for(int i = 0; i < rSelector3; i++) {
        item3 = reel3.GetNextItem();
    }
    
    cout <<  " ---------\n|  Slots!  |\n ---------- \n";
    
    for (int i = 0; i < 3; i++) {
        cout << "| " << item1.getValue() << " | " << item2.getValue() << " | " << item3.getValue() << " |\n";
        reelVal.push_back(item1.getValue()[0]);
        reelVal.push_back(item2.getValue()[0]);
        reelVal.push_back(item3.getValue()[0]);
        item1 = reel1.GetNextItem();
        item2 = reel2.GetNextItem();
        item3 = reel3.GetNextItem();
    }
    
    return reelVal;
    
}
