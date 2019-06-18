//
//  vector.hpp
//  hwandlab
//
//  Created by Nan Lin on 6/13/19.
//  Copyright © 2019 Nan Lin. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>
#include <cassert>
const int DEF_CAPACITY = 10;

class vect {
    friend void print_vect(vect v);
    friend bool operator == (const vect& v1,const vect&v2);
 public:
    vect();
    // copy control:
    vect(const vect& v2);
    ~vect();
    vect& operator=(const vect& v2);
    
  
    
    void push_back(int val);
    int size() const {return sz;}
   // void print_vect(vect v);
    int operator[](int i) const;
    int& operator[](int i);
 private:
    int* data;
    int sz;
    int capacity;
    
};

#endif /* vector_hpp */
