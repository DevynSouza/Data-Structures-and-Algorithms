#include "Reservation.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Reservation& i){
    os << "Reservation: [" << i.getName() << "]";
    return os;
}

bool Reservation::operator< (const Reservation& other){
    return personName < other.personName;
}

bool Reservation::operator== (const Reservation& other){
    return personName == other.personName;
}