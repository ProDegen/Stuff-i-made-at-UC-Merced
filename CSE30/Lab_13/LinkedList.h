#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

// Representation of an element in the linked list
template<class T>
struct Node
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template<class T>
class LinkedList
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(){ // Constructor
            first = NULL;
            last = NULL;
            };
        ~LinkedList(){ // Destructor
            while(!isEmpty()){
                removeFromBack();
            }
        }; 
        void insertAtBack(T valueToInsert){ // insert back
            Node<T>* v = new Node<T>;
            v->val = valueToInsert;
            if(first == NULL){
                v->next = NULL;
                first = v;
                last = v;
            }
            else{
                v->next = NULL;
                last->next = v;
                last = v;
            }
        };
        bool removeFromBack(){
            if(first == NULL){
                return false;
            }
            if(first == last){
                delete first;
                first = NULL;
                last = NULL;
                return true;
            }
            else{
                Node<T>* old = first;
                while(old->next != last){
                    old = old->next;
                }
                delete last;
                last = old;
                return true;
            }
        };
        void print(){
            if(first != NULL){
                Node<T>* n = first;
                while(n != last){
                    cout << n->val << ",";
                    n = n->next;
                }
                if(n != NULL){
                    cout << n->val;
                }
            }
        };
        bool isEmpty(){
            if(first == NULL){
                return true;
            }
            else{
                return false; 
            }
        };
        int size(){
            Node<T>* tempNode = first;
            int count = 1;
            if(!isEmpty()){
                while(tempNode != last){
                    count++;
                    tempNode = tempNode->next;
                }
                return count;
            }
            else{
                return 0;
            }
        };
        void clear(){
            while(!isEmpty()){
                removeFromBack();
            }
        };

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert){
            Node<T>* v = new Node<T>;
            v->val = valueToInsert;
            if(first == NULL){
                v->next = NULL;
                first = v;
                last = v;
            }
            else{
                v->next = first;
                first = v;
            }
        };
        bool removeFromFront(){
            if(first == NULL){
                return false;
            }
            if(first == last){
                delete first;
                first = NULL;
                last = NULL;
                return true;
            }
            else{
                Node<T>* old = first;
                old = old->next;
                delete first;
                first = old;
                return true;
            }
        };

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};

// Implement your functions here:



#endif

