#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
using namespace std;

int main()
{
 Queue queue;
 int array[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++){
     queue.enQueue(array[i]);
 }
//checking if it worked
    if(queue.isEmpty()){
        cout<< "Queue is empty" << endl;
}
    else{
        cout << "current Queue: "; 
        queue.print(); cout << endl;
    }
        if(queue.isEmpty()){
        cout<< "Queue is empty" << endl;
}
    else{
        for(int i = 0; i < 5; i++){
        cout<< "Value: " << queue.deQueue() << " was removed" << endl;
    }
}
//just always checking it its empty just incase i miscounted
        if(queue.isEmpty()){
        cout<< "Queue is empty" << endl;
}
    else{
        cout << "next in queue: " << queue.front() << endl;
        cout<< "Value: " << queue.deQueue() << " was removed" << endl;
        cout << "next in queue: " << queue.front() << endl;
    }
}


