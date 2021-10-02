#include <iostream>
#include <string>
#include "Reservation.hpp"
#define MAX_ELEMS 100
using namespace std;

class ReservationUnorderedArrayList {
private:
    int currentPos;
    int length;
    Reservation data[MAX_ELEMS];
    
public:
    ReservationUnorderedArrayList():currentPos{-1}, length{0}{};
    void MakeEmpty();
    void PutItem(Reservation reservation);
    Reservation GetItem(Reservation reservation);
    Reservation GetItem(string name);
    void DeleteItem(Reservation Reservation);
    void ResetList();
    Reservation GetNextItem();
    int GetLength();
    ~ReservationUnorderedArrayList();
    
};
ostream& operator<<(ostream& os, ReservationUnorderedArrayList& i);
