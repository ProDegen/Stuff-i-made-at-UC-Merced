#include <iostream>
#include "Queue_char.h"
using namespace std;

int main()
{
 Queue queue;
 //this will look really messy since were doing the table thing 
cout<<"Function Call\t\t"<<"Output\t\t"<<"Front  Queue  Rear"<<endl;
//first check for list which there isnt one rn so itll just print out exception in the correct section
cout<<"deQueue()\t\t";
    try{
        if(queue.isEmpty()){
            throw "exception";
        }
        else{
            cout << queue.deQueue(); cout << "\t\t";
            queue.print();
            cout<<endl;
        }
    }
    catch(...){
        cout << "exception"<< endl;
    }
    //first input
    
cout<<"enQueue(D)\t\t";
queue.enQueue('D');
cout << "\t\t";
queue.print();
cout << endl;
    //second input
cout<<"enQueue(A)\t\t";
queue.enQueue('A');
cout << "\t\t";
queue.print();
cout << endl;
//dequeue
cout<<"deQueue()\t\t";
try{
        if(queue.isEmpty()){
            throw "exception";
        }
        else{
            cout << queue.deQueue(); cout << "\t\t";
            queue.print();
            cout<<endl;
        }
    }
    catch(...){
        cout << "exception"<< endl;
    }
//size check
cout<<"size()\t\t\t";
cout << queue.size();
cout << "\t\t";
queue.print();
cout << endl;
//3rd input
cout<<"enQueue(D)\t\t";
queue.enQueue('D');
cout << "\t\t";
queue.print();
cout << endl;
//empty check
cout<<"isEmpty()\t\t";
    if(!queue.isEmpty()){
        cout << "False";
    }
    else{
        cout <<"True";
    }
cout << "\t\t";
queue.print();
cout << endl;
//front check
cout<<"front()\t\t\t";
try{
        if(queue.isEmpty()){
            throw "exception";
        }
        else{
            cout << queue.front(); cout << "\t\t";
            queue.print();
            cout<<endl;
        }
    }
    catch(...){
        cout << "exception"<< endl;
    }
//4th input
cout<<"enQueue(T)\t\t";
queue.enQueue('T');
cout << "\t\t";
queue.print();
cout << endl;
//another front check
cout<<"front()\t\t\t";
try{
        if(queue.isEmpty()){
            throw "exception";
        }
        else{
            cout << queue.front(); cout << "\t\t";
            queue.print();
            cout<<endl;
        }
    }
    catch(...){
        cout << "exception"<< endl;
    }
}


