#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){

}

Queue::~Queue(){
    
}

void Queue::enQueue(int num){
    insertAtBack(num);
}

int Queue::deQueue (){
    //first finding the value were about to remove by using the first value in the linkedlist function
    //to do that i had to unprivate those variable and then make a new variable
    //the we use the remove function anf return the value we removed
    int removed = first->val;
    removeFromFront();
    return removed;
    }

int& Queue::front(){
    //at first i tried to do that same as the deQueue function and make a new variable that was the 
    //first number and then return it but that didnt work, so i skiped than and just reutrned the 
    //raw value
    return first->val;
}