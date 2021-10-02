#include "UnorderedArrayList.hpp"
using namespace std;

void UnorderedArrayList::MakeEmpty() {
    length = 0; 
} //Sets the array length to 0 effectively deleting everything

void UnorderedArrayList::PutItem(Cars cars) {
    	data[length++] = cars;
} //Sets the current datamember at the value of length++ to cars

Cars UnorderedArrayList::GetItem(Cars cars) {
    for(int i = 0; i < length; ++i){
		if (data[i] == cars) {
			return data[i]; 
		}
	}
	throw "vehicle not found"; 
}

Cars UnorderedArrayList::GetItem(string plateNumber){
    for(int i = 0; i < length; ++i) {
        if(data[i].getPlateNumber() == plateNumber) {
            return data[i];
        }
    }
    throw "Plate number not found!";
}

void UnorderedArrayList::DeleteItem(Cars cars) {
    for(int i = 0; i < length; ++i){
		if (data[i] == cars){
			data[i] = data[--length];
		}
	}
}  /*Sets the current value equal to the last value of the array. 
    also decrements length which thereby decrements the array.
    */

void UnorderedArrayList::ResetList() {
    currentPos = 0;
}

Cars UnorderedArrayList::GetNextItem() {
    if (currentPos < length) {
        return data[currentPos++];
    }
    throw "Out of range";
}//As long as the currentPos is less than length is will be able to ++ and return the value

int UnorderedArrayList::GetLength() {
    return length;
}

Cars& UnorderedArrayList::getItemAtIndex(int index) {
    return data[index];
}

//For some reason the destructor works now but it didn't before
UnorderedArrayList::~UnorderedArrayList() {

}

void UnorderedArrayList::listCars() {
    //I have to list all available cars so loop through the array
    for (int i = 0; i < length; ++i) {
        if(data[i].getAvailable() == 1) {
            cout << i+1 << ". " << data[i].getMake() << "| " << data[i].getModel() << "| Plate:" << data[i].getPlateNumber();
            switch(data[i].getType()) {
                case 0: 
                    cout << "| Suv |" << "$";\
                    break;
                case 1:
                    cout << "| Sedan |" << "$";
                    break;
                case 2:
                    cout << "| Exotic |" << "$";
                    break;
            }
            cout << data[i].getPricePerDay() << " Per Day" << endl;
        } 
    }
}

ostream& operator<<(ostream& os, UnorderedArrayList& o){
    o.ResetList();
    os << "Cars: [";
    for(int i = 0; i < o.GetLength(); ++i){
        os << "(" << o.GetNextItem() << ")";
        if (i < o.GetLength() - 1) os << ", ";
    }
    os << "]";
    return os;
}
//Still have to add in the destructor but it doesn't work for some reason.
