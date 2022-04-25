#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;  
void Asortcheck(string arr[],int n,int sort);
void Dsortcheck(string arr[],int n,int sort);
void binarySearchL(string arr[],int n, int size, string key);
int main()
{
    int size = 0;
    int i = 0;
    int as = 1,ds = 1;
    string key = "";
    string words[30];
    ifstream myinfile("words_in.txt");
    //open my txt and copy down the strings
    while(!myinfile.eof()){
        myinfile >> words[size];
        size++;
    }
    myinfile.close();
    //check if theyre sorted
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
        //printing if theyre sorted, if they are the go into the search funtion
    }
    if (as == size){
        cout << "Enter a key to find in the array: " << endl;
        cin >> key;
        binarySearchL(words,0,size,key);   
    }
    if (ds == size){
        cout << "Enter a key to find in the array: " << endl;
        cin >> key;
        binarySearchL(words,0,size,key);   
    }
    if(as != size && ds != size){
        cout << "ERROR ARRAY IS NOT SORTED" << endl;
        return 0;
    }
  return 0;
}
void binarySearchL(string arr[],int n, int size,string key){
    //make the loop requirments
    while (n <= size) {
        //get the midfle area
        int mid = n + (size - n) / 2;
        //check where the key is, if its there then print its location
        if (arr[mid] == key)
            cout << "key: " << key << " found at index: " << mid << endl;
            exit;
        if (arr[mid] < key)
            n = mid +1;
        else
        size = mid -1;
    }
    exit;
}