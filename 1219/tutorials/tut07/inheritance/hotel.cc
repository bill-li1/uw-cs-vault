#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Guest {
    string name;
    int moneyInPocket;
};

class Hotel {    
    struct Room {
        int roomNumber = 0;
    };

    vector<Guest> guests;        // The Hotel has-a (or many) guests
    vector<Room> rooms;          // The Hotel own-a (or many) rooms

//protected:  
    const int rating = 3;

public:
    explicit Hotel( int rating ); 
    void addGuest( Guest g );
    void printGuestList() const;
};

class  LuxuryHotel : public Hotel { // LuxuryHotel is-a Hotel
    const int numOfSwimmingPool = 1;
public:
    LuxuryHotel( int rating, int numOfSwimmingPool );
    void describe() const;
};

int main() {
    LuxuryHotel h {5, 3};
    h.addGuest({"Jason", 800});
    h.addGuest({"Amy", 1000});
    h.addGuest({"Tony", 1000000000});
    h.printGuestList();  
    cout << endl;
    h.describe();
    return 0;
}

Hotel::Hotel( int rating ) : rating{rating} {} 

void Hotel::addGuest( Guest g ) { guests.push_back(g); }

void Hotel::printGuestList() const { 
    for (auto g : guests) cout << g.name << endl; 
}

LuxuryHotel::LuxuryHotel( int rating, int numOfSwimmingPool ) 
   : Hotel{rating}, numOfSwimmingPool{numOfSwimmingPool} {}    

void LuxuryHotel::describe() const {
    cout << "Our luxury hotel has " << 
        // rating << " stars rating and " << // rating is private
        numOfSwimmingPool << " swimming pool." << endl;
}
