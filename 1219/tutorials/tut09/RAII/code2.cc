#include <new>
#include <memory>
using namespace std;

// Using RAII to handle resources
int main() {
    try {
        int *arr1 = new int[10];
        int *arr2 = nullptr;
        try { 
            arr2 = new int[20];
        } catch( std::bad_alloc &e ) {
            delete [] arr1;
            throw;
        }
        delete [] arr1;
        delete [] arr2;
    } catch( std::bad_alloc &e ) {
        // handler
    }
}
