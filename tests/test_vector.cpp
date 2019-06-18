#include <cassert>
#include <iostream>
#include "../my_code/vector.hpp"
//#include "vector.hpp"

using namespace std;

int copy_vector(vect v) {
    vect local_v = v;
    return local_v.size();
}

int main() {
    vect v = vect();
    for (int i = 0; i < 200; i++) {
        v.push_back(i);
        copy_vector(v);
    }
    assert(v[199] == 199);
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    assert(v[199] == 398);
    vect v3;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
    }
    assert(v3[1] == 18);
    
    vect v2 = v;
    cout << "V: ";
    print_vect(v);
    cout << endl << "V2: ";
    print_vect(v2);
    assert(v2 == v);
    
    v2 = v3;
    cout <<endl<< "V3:";
    print_vect(v3);
    cout << endl<<"V2:";
    print_vect(v2);
    cout <<endl;
    assert(v2 == v3);
}
