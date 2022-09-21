#ifndef STACk_H
#define STACK_H
#include <iostream>
using namespace std;
#include "LinkedList.h"
//currently doesnt work, hoping to get it to work before due date
template<class T>
class Stack : public LinkedList<T>{
    public:
    
    Stack(){

    };
    ~Stack(){

    };
    void push(int value){
        LinkedList<T> insertAtBack(value);
    };
    int pop(){
        int item = first->val;
        LinkedList<T> removeFromBack();
        return item;
    };
    int& top(){
        return last->val;
    };
};

#endif
