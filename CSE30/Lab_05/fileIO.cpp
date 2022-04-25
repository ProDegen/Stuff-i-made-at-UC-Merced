#include <iostream>
#include <string>
#include <fstream>
using namespace std;  
int main()
{
    int size = 0;
    int i = 0;
    string words[30];
    ifstream myinfile("words_in.txt");
    //open file and check its size whil copying strings
    while(!myinfile.eof()){
        myinfile >> words[size];
        size++;
    }
    //open new file and copy down every string per line in our size
    myinfile.close();
    ofstream myoutfile("words_out.txt");
    while (i < size){
            myoutfile << words[i] << "\n";
            i++;
    }
    myoutfile.close();
  return 0;
}
