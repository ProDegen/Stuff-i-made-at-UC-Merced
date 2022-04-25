#ifndef QUEUELIST_H 
#define QUEUELIST_H
#include "LinkedList.h"
class Queue: public LinkedList{
    public:

    Queue();
    ~Queue();
    void enQueue(int num);
    int deQueue ();
    int& front();


};

#endif