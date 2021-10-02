#include "ReservationUnorderedArrayList.hpp"

using namespace std;

void ReservationUnorderedArrayList::MakeEmpty(){
    length = 0;
}

void ReservationUnorderedArrayList::PutItem(Reservation reservation){
    data[length++] = reservation;
}

Reservation ReservationUnorderedArrayList::GetItem(Reservation reservation){
    for(int i = 0; i < length; ++i){
        if (data[i] == reservation) {
            return data[i];
        }
    }
    throw "Item not found";
}

Reservation ReservationUnorderedArrayList::GetItem(string personName){
    for(int i = 0; i < length; ++i) {
        if(data[i].getName() == personName) {
            return data[i];
        }
    }
    throw "Not plateNumber Found!";
}

void ReservationUnorderedArrayList::DeleteItem(Reservation reservation){
    for(int i = 0; i < length; ++i){
        if (data[i] == reservation){
            data[i] = data[--length];
        }
    }
}

void ReservationUnorderedArrayList::ResetList(){
    currentPos = 0;
}

Reservation ReservationUnorderedArrayList::GetNextItem(){
    if(currentPos < length)
        return data[currentPos++];
    
    throw "Out of Range";
}

int ReservationUnorderedArrayList::GetLength(){
    return length;
}

//The destructor works for some reason on this one?
ReservationUnorderedArrayList::~ReservationUnorderedArrayList(){
    
}


ostream& operator<<(ostream& os, ReservationUnorderedArrayList& o){
    o.ResetList();
    os << "Reservations: ";
    for(int i = 0; i < o.GetLength(); ++i){
        Reservation r = o.GetNextItem();
        os << "(Name: " << r.getName() << ", Car: " << r.getVehicleRented() << ")";
        if (i < o.GetLength() - 1) os << ", ";
    }
    return os;
}