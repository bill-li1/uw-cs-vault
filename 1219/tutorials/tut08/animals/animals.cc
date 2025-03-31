#include <iostream>
#include <string>
using namespace std;

struct Animal {
    virtual bool fly() const { return false; }
};

struct Cat: public Animal {
};

struct NyanCat final: public Cat {
    bool fly() const override { cout << "NYAN NYAN NYAN NYAN..." << endl; return true; }
};

struct Bird: public Animal {
    bool fly() const override { return true; }
};

struct Goose final: public Bird {
    bool fly() const override { cout << "THANK MR. GOOSE" << endl; return Bird::fly(); }
};

int main(){
    cout << boolalpha;

    Cat cat;
    NyanCat nCat;
    Bird bird;
    Goose goose;

    string junk;

    cout << "Nyan Cat through Animal object. Can it fly?" << endl;
    Animal animal = nCat;
    cout << "Input something to find out!" << endl;
    cin >> junk;
    cout << animal.fly() << endl << endl;

    cout << "Nyan Cat through Animal pointer. Can it fly?" << endl;
    Animal *animalPoint = &nCat;
    cout << "Input something to find out!" << endl;
    cin >> junk;
    cout << animalPoint->fly() << endl << endl;

    cout << "Nyan Cat through Animal reference. Can it fly?" << endl;
    Animal& animalRef = nCat;
    cout << "Input something to find out!" << endl;
    cin >> junk;
    cout << animalRef.fly() << endl << endl;
    
    cout << "Goose through Animal reference. Can it fly?" << endl;
    Animal& goo1 = goose;
    cout << "Input something to find out!" << endl;
    cin >> junk;
    cout << goo1.fly() << endl << endl;

    cout << "Goose through Bird object. Can it fly?" << endl;
    Bird goo2 = goose;
    cout << "Input something to find out!" << endl;
    cin >> junk;
    cout << goo2.fly() << endl;
}
