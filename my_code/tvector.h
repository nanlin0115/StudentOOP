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
#include <ostream>
const int DEF_CAPACITY = 10;

template <typename TYP>
class vect {
    friend void print_vect(vect<TYP> v){
        for (int i = 0;i<v.size();i++){
            std::cout <<v.data[i]<<std::endl;
        }
    }
    
    friend bool operator == (const vect<TYP>& v1,const vect<TYP>&v2){
        for (int i = 0; i < v1.size();i++){
            if (v1.data[i]!=v2.data[i]) return false;
            
        }
        return true;
    }
public:
    class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
        friend bool operator!=(Iterator& rhs, Iterator& lhs){
            return rhs.iptr != lhs.iptr;
        }
        
    public:
        Iterator(TYP* ip): iptr(ip) {}
        
        Iterator& operator++() {
            iptr++;
            return *this;
        }
        
        const TYP& operator*() const { return *iptr; }
        TYP& operator*() {return *iptr;}
        
    private:
        TYP* iptr;
    };
    
    vect(){
        sz = 0;
        capacity = DEF_CAPACITY;
        data = new TYP[DEF_CAPACITY];
    }
    // copy control:
    vect(const vect& v2){
        capacity = v2.capacity;
        sz = v2.size();
        data = new TYP[capacity];
        for (int i = 0; i<v2.size();i++){
            data[i] = v2.data[i];
        }
    }
    
    ~vect(){
        delete[] data;
    }
    
    vect& operator=(const vect& v2){
        if (&v2 != this){
            delete [] data;
            capacity = v2.capacity;
            sz = v2.size();
            data = new TYP[capacity];
            //copy over existing data
            for (int i = 0; i < size();i++){
                data[i] = v2.data[i];
            }
        }
        return *this;
        
    }
    
    void push_back(TYP val){
        if (sz == capacity){
            capacity *=2;
            TYP* new_data = new TYP[capacity];
            for (int i = 0; i <size();i++){
                new_data[i] = data[i];
            }
            delete data;
            data = new_data;
        }
        data[sz++] = val;
    }
    
    int size() const {return sz;}
    
    
    
    const TYP& operator[](int i) const{
        return data[i];
    }
    
    TYP& operator[](int i){
        return data[i];
    }
    
    Iterator begin() const{
        Iterator result(data);
        return result;
    }
    Iterator end() const{
        
        return Iterator(data+sz);
    }
    
    vect(int sz, TYP val){
        capacity = DEF_CAPACITY + sz;
        data = new TYP[capacity];
        for (int i = 0; i<sz; i++){
            data[i] = val;
        }
    }
private:
    TYP* data;
    int sz;
    int capacity;
    void copy(const vect& v2);
    
};

template <typename TYP>
void print_vect(const vect<TYP>& v){
    for (const TYP& val : v){
        std::cout <<val<<" ";
    }
    std::cout << std::endl;
}


#endif /* vector_hpp */
