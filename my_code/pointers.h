//
//  pointers.h
//  hwandlab
//
//  Created by Nan Lin on 6/4/19.
//  Copyright © 2019 Nan Lin. All rights reserved.
//


#ifndef POINTERS_H
#define POINTERS_H

#include <string>
#include <vector>

void inc_by_value(int n);
void inc_with_pointer(int* n);
void inc_with_reference(int& n);

//struct creates the object
//it's initializing val in Thing
struct Thing {
    int val;
    Thing(int i) : val(i) {}
};
// **
Thing** create_array_of_things(int n);
void print_all_things(Thing** things, int n);
void double_all_things(Thing** things, int n);
void delete_all_things(Thing** things, int n);

struct Student {
    std::string name;
    Student* ta;
    Student(std::string nm) : name(nm), ta(nullptr) {}
};

void assignTA(Student& s, Student& ta);
void printTAs(std::vector<Student> students);

#endif

