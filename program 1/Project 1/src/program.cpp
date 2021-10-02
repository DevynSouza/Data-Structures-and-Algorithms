#include "Program.hpp"
#include "Car.hpp"
#include "UnorderedArrayList.hpp"
#include "Reservation.hpp"
#include "ReservationUnorderedArrayList.hpp"
using namespace std;

void Program::start() {
    bool exit = false;
    UnorderedArrayList* carList = new UnorderedArrayList();
    ReservationUnorderedArrayList* reservationList = new ReservationUnorderedArrayList();
    

    while(!exit) {
        int input;

        cout << "\nWelcome to Car Rentals" << endl;
        cout << "\n1. List all cars \n";
        cout << "2. Add car to inventory \n";
        cout << "3. Remove car from inventory \n";
        cout << "4. List all reservations \n";
        cout << "5. Add a reservations \n";
        cout << "6. Cancel reservation \n";
        cout << "7. Exit Option \n";
        cin >> input;
        cin.ignore();
        
        if (input == 1) { //Lists all cars
           cout << *carList << endl;
        }
        else if (input == 2) { //Adds a car to inventory
            cout << "Enter plate number \n";
            string plateNumber;
            cin >> plateNumber;

            cout << "Enter manufacturer of car\n";
            string vehicleMake;
            cin.ignore();
            getline(cin, vehicleMake);

            cout << "Enter vehicle model\n";
            string vehicleModel;
            cin >> vehicleModel;

            cout << "Enter the price per day\n $";
            double pricePerDay;
            cin >> pricePerDay;

            cout << "Please select an option of which type of vehicle it is\n0. Suv \n1. Sedan\n2. Exotic\n";
            int vType;
            cin >> vType;
            carList->PutItem(Cars(pricePerDay,plateNumber, vehicleMake, vehicleModel, true, vehicleType(vType)));
            
            
        }
        else if (input == 3) { //Removes a car from inventory
            cout << "Enter the plate number of the car to remove the car: ";
            string plateNumber;
            cin >> plateNumber;
            carList->DeleteItem(carList->GetItem(plateNumber));
        }
        else if (input == 4) { //Displays reservation list
            cout << *reservationList << endl;

        }
        else if (input == 5) { //Creates a reservation
            
            cout << "input 5!" << endl;
            
            cout << "Enter the reservation name: ";
            string personName;
            cin >> personName;
            
            cout << "Please input the number of which car you would like to reserve." << endl;
            carList->listCars(); //Lists the available cars
            int index;
            cin >> index;
            if(index-1 <= carList->GetLength() ) {
                reservationList->PutItem(Reservation(personName, carList->getItemAtIndex(index-1).getModel()));
                carList->getItemAtIndex(index-1).setAvailable(false); 
            }
        }
        else if (input == 6) { //Deletes a reservation
            cout << "Please enter the name of the reservation to remove: ";
            string personName;
            cin >> personName;
            carList->GetItem(reservationList->GetItem(personName).getVehicleRented()).setAvailable(true);
            reservationList->DeleteItem(reservationList->GetItem(personName));
        
        }
        else if (input == 7) {  //Exits the while loop and ends the function
            cout << "input 7!" << endl;
            exit = true;
        }
    }   
}