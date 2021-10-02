#include <iostream>
#include "Car.hpp"
using namespace std;

class UnorderedArrayList {
    private:
    int currentPos;
    int length;
    Cars data[MAX_ELEMS];

    public:
        UnorderedArrayList(): currentPos{-1}, length{0}{};	
        void MakeEmpty();
        void PutItem(Cars cars);
        Cars GetItem(Cars cars);
        Cars GetItem(string plateNumber);
        void DeleteItem(Cars cars);
        void ResetList();
        Cars GetNextItem();
        int GetLength();
        ~UnorderedArrayList(); 
        void listCars();
        Cars& getItemAtIndex(int index);



};
ostream& operator<<(ostream& os, UnorderedArrayList& i);