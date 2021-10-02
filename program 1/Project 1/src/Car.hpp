#ifndef Car_hpp_
#define Car_hpp_

#include <iostream>
#include <string>
#include "enum.hpp"
#define MAX_ELEMS 100

using namespace std;





class Cars {
    private:
        double pricePerDay; //Price of car per day
        string plateNumber; //Plate number of car
        string vehicleMake; //The manufacturer
        string vehicleModel;   //The model of the car
        bool isAvailable = true;;   //Whether the car is available or not
        vehicleType vType; //Vehicle type enum 0 = suv, 1 = sedan, 2 = exotic

            
    public:
        Cars(){}
        Cars(double pricePerDay, string plateNumber, string vehicleMake, string vehicleModel, bool isAvailable, vehicleType vType):
            pricePerDay{pricePerDay},
            plateNumber{plateNumber},
            vehicleMake{vehicleMake},
            vehicleModel{vehicleModel},
            isAvailable{isAvailable},
            vType{vType}
        {}

        string getPlateNumber() const{return plateNumber; }
        string getModel() const{ return vehicleModel; }
        string getMake() const{ return vehicleMake; }
        double getPricePerDay() const{return pricePerDay; }
        bool getAvailable() const{return isAvailable; }
        vehicleType getType() const{return vType; }

        void setAvailable(bool available);
    

        bool operator< (const Cars& other);
	    bool operator== (const Cars& other);
   

       

};
ostream& operator<<(ostream& os, const Cars& i);
#endif