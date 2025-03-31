#include <iostream>
using namespace std;

// One exception class
class BadInput{};

// Another exception class
class BadNumber: public BadInput{
  public:
    string what() { return "no number given"; }
};

int main(){
    try { // Let's try this block:
        int x;
        cout << "Give me a number" << endl;
        cin >> x;
        if (x < 50) throw BadNumber{};
        // Which catch block will run?
    } catch(BadInput &b) {
        cerr << "This is caught" << endl;
    } catch(BadNumber &b) { 
        // Accessing auxilliary information from caught object
        cerr << b.what() << " is caught" << endl;
    }
}
