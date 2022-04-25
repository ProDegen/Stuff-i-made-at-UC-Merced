#ifndef QUEUELIST_H 
#define QUEUELIST_H
#include "LinkedList_char.h"
class Queue: public LinkedList{
    public:

    Queue();
    ~Queue();
    void enQueue(char input);
    char deQueue ();
    char& front();


};

#endif