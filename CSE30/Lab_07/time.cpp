#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "time.h"
using namespace std;
timeStrip::timeStrip(std::string input, int hour, int minute,int second){
    string timeBegin = input; 
    int count = 0,check = 0,Echeck=0;
    string zero = "0";
    stringstream time(timeBegin);
    string segment;
    vector<string> seglist;
    
    while(getline(time, segment, ':')){
        seglist.push_back(segment);
        if (count == 0){
            check = stoi(segment);
            if(check >= 0 && check <= 23){
                hour = check;
            }
            else{
            cout << "your time is not valid" << endl;
            Echeck++;
            exit;
            }
        }
        if (count == 1){
            check = stoi(segment);
            if(check >= 0 && check <= 59){
                minute = check;
            }
            else{
            cout << "your time is not valid" << endl;
            Echeck++;
            exit;
            }
        }
        if (count == 2){
            check = stoi(segment);
            if(check >= 0 && check <= 59){
                second = check;
            }
            else{
            cout << "your time is not valid" << endl;
            Echeck++;
            exit;
            }
        }
        count++;
        
    }
    if(Echeck > 0){
        exit;
    }
    else{
     cout << setw(2) << setfill('0') << hour << ":"
	<< setw(2) << setfill('0') << minute << ":"
 	<< setw(2) << setfill('0') << second << "\n";   
    }
    
}
