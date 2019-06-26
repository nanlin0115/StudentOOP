#include <cassert>
#include <iostream>
#include <string>
#include "../my_code/tvector.h"
//#include "tvector.h"

using namespace std;

template <typename TYP>
int copy_vector(vect<TYP> v) {
    vect<TYP> local_v = v;
    return local_v.size();
}

const int VEC_SZ = 20;



int main() {
    vect<int> iv = vect<int>();
    for (int i = 0; i < VEC_SZ; i++) {
        iv.push_back(i);
        copy_vector(iv);
    }
    
    assert(iv[VEC_SZ - 1] == VEC_SZ - 1);
    
    
    for (int i = 0; i < iv.size(); i++) {
        iv[i] *= 2;
    }
    assert(iv[VEC_SZ - 1] == 38);
    vect<int> v3;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
    }
    assert(v3[1] == 18);
    print_vect(v3);
    
    vect<int> v2 = iv;
    assert(v2 == iv);
    print_vect(v2);
    
    v2 = v3;
    assert(v2 == v3);
    print_vect(v2);
    
    for (int i : v3) {
        assert((i % 9) == 0);
    }
    
    
    vect<string> sv = vect<string>(10, "Hello");
    for (int i = 0; i < sv.size(); i++) {
        assert(sv[i] == "Hello");
    }
    print_vect(sv);
    
}
