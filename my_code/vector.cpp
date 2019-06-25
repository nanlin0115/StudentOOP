//
//  vector.cpp
//  hwandlab
//
//  Created by Nan Lin on 6/13/19.
//  Copyright © 2019 Nan Lin. All rights reserved.
//

#include "vector.hpp"
#include <cassert>
#include <iostream>

using namespace std;

void print_vect(vect v){
    for (int i :v) cout << i <<" ";
    cout << endl;
}

vect::vect(){
    sz = 0;
    capacity =DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}

vect::vect(const vect& v2){
    capacity = v2.capacity;
    sz = v2.size();
    data = new int[capacity];
    //copy over existing data
    for (int i = 0; i < size();i++){
        data[i] = v2.data[i];
    }
}

vect::~vect(){
    delete[] data;
}
vect::vect(int sz,int val):sz(sz){
    capacity =DEF_CAPACITY + sz;
    data = new int[DEF_CAPACITY + sz];
    for(int i = 0; i<sz;i++){
        data[i]=val;
    }
}
vect& vect::operator=(const vect& v2){
    if (&v2 != this){
        delete [] data;
        capacity = v2.capacity;
        sz = v2.size();
        data = new int[capacity];
        //copy over existing data
        for (int i = 0; i < size();i++){
            data[i] = v2.data[i];
        }
    }
    return *this;
}

bool operator == (const vect& v1,const vect&v2){
    for (int i = 0; i<v2.size();i++){
        if (v1.data[i]!=v2.data[i]){
            return false;
        }
    }
    
    return true;
}

void vect::push_back(int val){
    if (sz == capacity){
        // get new array of capacity *2
        capacity *= 2;
        int* new_data = new int[capacity];
        // copy over exsiting data
        for (int i = 0;i<size();i++){
            new_data[i] = data[i];
        }
        // delete old array
        delete []data;
        // set pointer to new array
        data = new_data;
    }
    data[sz++] = val;
}

int vect::operator[](int i) const{
    return data[i];
}

int& vect::operator[](int i){
    return data[i];
}

bool operator !=(vect::Iterator& rhs, vect::Iterator& lhs) {
    return rhs.iptr != lhs.iptr;
}

vect::Iterator::Iterator(int* ip) : iptr(ip) {
}

vect::Iterator vect::begin() const{
    return Iterator(data);
}
vect::Iterator vect::end() const{
    return Iterator(data+sz);
}
