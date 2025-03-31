#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v {2, 3, 5, 7, 11, 13};

    for ( int i = 0; i < 6; ++i )
        cout << v[i] << ' ';
    cout << endl;

    for ( vector<int>::iterator it = v.begin(); it != v.end(); ++it )
        cout << *it << ' ';
    cout << endl;

    for ( auto it = v.rbegin(); it != v.rend(); ++it )
        cout << *it << ' ';
    cout << endl;

    for ( auto it = v.begin(); it != v.end(); ++it )
        cout << *it << ' ';
    cout << endl;

    for ( int i : v )
        cout << i << ' ';
    cout << endl;
    
}
