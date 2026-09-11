#include <iostream>
using namespace std;
class Resource { 
    string name;
public:
Resource( string n) { name = n; cout << name << " acquired\n"; } 
~Resource() { cout << name << " released\n"; } 
};

class Manager { 
    Resource r1; // declared 1st -> constructed 1st, destroyed last
    Resource r2; // declared 2nd -> constructed 2nd, destroyed first
public:
Manager() : r1(" R1") , r2(" R2") { cout << " Manager ready\n"; } // runs AFTER r1 & r2 are fully built
~Manager() { cout << " Manager shutting down\n"; } // runs BEFORE members are destroyed
};

int main() {
Manager m;
cout << " Main running\n";
}

/* Output:  R1 acquired
          R2 acquired
         Manager ready
         Main running
         Manager shutting down
         R2 released
          R1 released
*/