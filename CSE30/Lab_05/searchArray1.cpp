#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;  
void Asortcheck(string arr[],int n,int sort);
void Dsortcheck(string arr[],int n,int sort);
void binarySearchR(string arr[],int n, int size, string key);
int main()
{
    int size = 0;
    int i = 0;
    int as = 1,ds = 1;
    string key = "";
    string words[30];
    ifstream myinfile("words_in.txt");
    //open txt and copy strings
    while(!myinfile.eof()){
        myinfile >> words[size];
        size++;
    }
    myinfile.close();
    for (i = 1;i <= size-1; ){
        if (words[i] > words[i-1]){
            as++;
            
        }
        i++;
    }
    for (i = 1;i <= size-1; ){
        if (words[i] < words[i-1]){
            ds++;
            
        }
        i++;
        //checks if any of them are sorted and if they are they go into the search funtion 
    }
    if (as == size){
        cout << "Enter a key to find in the array: " << endl;
        cin >> key;
        binarySearchR(words,0,size,key);   
    }
    if (ds == size){
        cout << "Enter a key to find in the array: " << endl;
        cin >> key;
        binarySearchR(words,0,size,key);   
    }
    if(as != size && ds != size){
        cout << "ERROR ARRAY IS NOT SORTED" << endl;
        return 0;
    }
  return 0;
}
void binarySearchR(string arr[],int n, int size,string key){
    if (size >= n) {
        //find the middle
        int mid = n + (size - n) / 2;
        //if we find the key print its position
        if (arr[mid] == key)
            cout << "key: " << key << " found at index: " << mid << endl;
            exit;
        //adjust search range id its not in our search area
        if (arr[mid] > key)
            return binarySearchR(arr, n, mid - 1, key);
        return binarySearchR(arr, mid + 1, size, key);
    }
    exit;
}