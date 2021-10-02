#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Item {

private:
    string value;

public:
    Item(){};
    Item(string value):
        value{value}
    {}
    string getValue() const{ return value; }
    bool operator< (const Item& other);
    bool operator== (const Item& other);
};
std::ostream& operator<<(std::ostream& os, const Item& i);

#endif /* Item_hpp */
