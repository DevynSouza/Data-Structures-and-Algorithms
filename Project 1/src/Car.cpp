#include "Car.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Cars& i){
	os << "Car: " << i.getMake() << i.getModel() << "| Plate:" << i.getPlateNumber();
		switch(i.getType()) {
					case 0: 
						cout << "| Suv |" << "$";\
						break;
					case 1:
						cout << "| Sedan |" << "$";
						break;
					case 2:
						cout << "| Exotic |" << "$";
						break;
				};
				cout << i.getPricePerDay() << " Per Day";
	return os;
}
        
bool Cars::operator< (const Cars& other){
	return plateNumber < other.plateNumber; 
}

bool Cars::operator== (const Cars& other){
	return plateNumber == other.plateNumber; 
}

void Cars::setAvailable(bool available) {
            isAvailable = available;
}





