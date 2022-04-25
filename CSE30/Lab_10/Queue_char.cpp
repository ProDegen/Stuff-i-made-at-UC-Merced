#include "Queue_char.h"
#include <iostream>
using namespace std;

Queue::Queue(){

}

Queue::~Queue(){
    
}

void Queue::enQueue(char input){
    insertAtBack(input);
}

char Queue::deQueue (){
    int removed = first->val;
    removeFromFront();
    return removed;
    }

char& Queue::front(){
    return first->val;
}