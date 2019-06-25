//
//  llist.cpp
//  hwandlab
//
//  Created by Nan Lin on 6/20/19.
//  Copyright © 2019 Nan Lin. All rights reserved.
//

#include <stdio.h>
#include <ostream>
#include "llist.h"
using namespace std;

ostream&operator<<(ostream& os, const Node* nd){
    if (!nd) cout << "Nullptr";
    else {
        os<<"Data:"<<nd->data<<" Next:";
    }
    return os;
}
void print_list(ostream& os, const Node* head){
    os<<head;
    if (head) print_list(os, head->next);
    else os <<endl;
}

Node* last(Node* head){
    if (!head) return nullptr;
    else if (!(head->next)) return head;
    else return last(head->next);
}

void add_at_end(Node*& head, int d){
    if (!head){
        head = new Node(d,head);
    }
    else add_at_end(head->next, d);
}


void add_at_front(Node*& head, int d){
    head = new Node(d,head);
}

bool del_head(Node*& head){
    if (!head) return false;
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
        
    }
}
bool del_tail(Node*& curr){
    if (!curr) return false;
    else {
        if (curr->next ==nullptr){
            delete curr;
            curr = nullptr;
            return true;
        }
        else{
            return del_tail(curr->next);
            }
    }
}

Node* duplicate(Node* head){
    Node* copy=new Node(head->data);
    Node* curr = head->next;
    while(curr != nullptr){
        add_at_end(copy,curr->data);
        curr = curr->next;
    }
    return copy;
}


Node* reverse(Node* curr,Node* prev){
    if(!curr) return prev;
    else{
       return reverse(curr->next, new Node(curr->data,prev));
    }
}

Node* join(Node*& list1, Node* list2){
    last(list1)->next = list2;
    return list1;
}
