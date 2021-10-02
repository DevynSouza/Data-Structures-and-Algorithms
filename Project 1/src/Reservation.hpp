#ifndef Reservations_hpp_
#define Reservations_hpp_

#include <string>
#include <iostream>
#define MAX_ELEMS 100

using namespace std;


class Reservation {
    private:
        string personName;  //Key we use to find vehicles for reservations
        string vehicleRented;  
        
        


    public:
        Reservation(){}
        Reservation(string personName, string vehicleRented):
            personName{personName},
            vehicleRented{vehicleRented}
        {}
        string getName() const{return personName;}
        string getVehicleRented() {return vehicleRented;}
        bool operator< (const Reservation& other);
        bool operator== (const Reservation& other);

};
    
ostream& operator<<(ostream& os, const Reservation& i);
#endif