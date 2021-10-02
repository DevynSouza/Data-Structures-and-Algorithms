#include <iostream>
#include <chrono>
#include "UnorderedLinkedList.hpp"
using namespace std;

int main(void) {
    UnorderedList* list = (UnorderedList*)new UnorderedLinkedList();

    cout << "Enter number of items to insert into list: ";
    int x;
    cin >> x;

    srand(time(NULL));

    int lastValue;

    for (int i = 0; i < x; i++) {
        int random = rand() % 1000000 + 1;
        list -> PutItem(Item(i, to_string(random)));
        lastValue = random;
    }


    cout << "Now we will find the last value in the array " << endl;
    cout << "The last value is " << lastValue << endl;

    chrono::time_point<chrono::system_clock> start,end;
    start = chrono::system_clock::now();

    cout << "\nFound Item: " << list -> LookUp(Item(0, to_string(lastValue))) << endl;

    end = chrono::system_clock::now();
    
    chrono::duration<double, micro> TotalTime = end - start;

    cout << "\nTotal Time: " << TotalTime.count() << " Micro seconds" << endl;

}