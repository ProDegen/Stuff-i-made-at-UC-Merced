#include <iostream>
#include <string>
#include <fstream>
using namespace std;  
void Asortcheck(string arr[],int n,int sort);
void Dsortcheck(string arr[],int n,int sort);
int main()
{
    int size = 0;
    int i = 0;
    int as = 1,ds = 1;
    string words[30];
    ifstream myinfile("words_in.txt");
    //open file and copy strings
    while(!myinfile.eof()){
        myinfile >> words[size];
        size++;
    }
    //check if they are sorted and mark down if they are ascending or descending 
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
    }
    //print whether or not its ascending or descending 
    cout << as << ds << endl;
    if (as == size){
        cout << "1" << endl;
    }
    if (ds == size){
        cout << "-1" << endl;
    }
    if(as != size && ds != size){
        cout << "0" << endl;
    }
  return 0;
}