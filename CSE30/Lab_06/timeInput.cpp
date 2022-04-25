#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;  
int main()
{
    string timeBegin = " "; 
    int count = 0;
    string zero = "0";
    cout << "enter what time your class begins in 24 hour format: " << endl;
    cin >> timeBegin;
    //obtain time in 24hour format
    //this is using strings and vectors so i can then seperate the numbers by the : 
    //and check if theyre in range of what i want
    stringstream time(timeBegin);
    string segment;
    vector<string> seglist;
    timeBegin = "";
    while(getline(time, segment, ':')){
        seglist.push_back(segment);
        //uses count statment to tell where i am in the timeframe
        //checks if the enter time is only 2 number and  it does it adds a 0 tot eh star
        //ex: input: 2 output: 02
        // this loops for all the positions in times
        if (count == 0){
            if(segment.length() == 1 ){
                zero.append(segment);
                segment = zero;
                zero = "0";
            }
            if(segment >= "0" && segment <= "23"){
                timeBegin.append(segment);
                timeBegin.append(":");
            }
            else{
            cout << "your time is not in 24 hour format" << endl;
            return 0;
            }
        }
        if (count == 1){
            if(segment.length() == 1 ){
                zero.append(segment);
                segment = zero;
                zero = "0";
            }
            if(segment >= "0" && segment <= "59"){
                timeBegin.append(segment);
                timeBegin.append(":");
            }
            else{
            cout << "your time is not in 24 hour format" << endl;
            return 0;
            }
        }
        if (count == 2){
            if(segment.length() == 1 ){
                zero.append(segment);
                segment = zero;
                zero = "0";
            }
            if(segment >= "0" && segment <= "59"){
                timeBegin.append(segment);
            }
            else{
            cout << "your time is not in 24 hour format" << endl;
            return 0;
            }
        }
        count++;
    }
    //the code is just repeated for out end time, i probably couldve just made this code loop
    //and make everything smaller but i think it would be confusing to implement into other code
    string timeEnd = " "; 
    count = 0;
    cout << "enter what time your class ends in 24 hour format: " << endl;
    cin >> timeEnd;
    stringstream time2(timeEnd);
    timeEnd = "";
    while(getline(time2, segment, ':')){
        seglist.push_back(segment);
        if (count == 0){
            if(segment.length() == 1 ){
                zero.append(segment);
                segment = zero;
                zero = "0";
            }
            if(segment >= "0" && segment <= "23"){
                timeEnd.append(segment);
                timeEnd.append(":");
            }
            else{
            cout << "your time is not in 24 hour format" << endl;
            return 0;
            }
        }
        if (count == 1){
            if(segment.length() == 1 ){
                zero.append(segment);
                segment = zero;
                zero = "0";
            }
            if(segment >= "0" && segment <= "59"){
                timeEnd.append(segment);
                timeEnd.append(":");
            }
            else{
            cout << "your time is not in 24 hour format" << endl;
            return 0;
            }
        }
        if (count == 2){
            if(segment.length() == 1 ){
                zero.append(segment);
                segment = zero;
                zero = "0";
            }
            if(segment >= "0" && segment <= "59"){
                timeEnd.append(segment);
            }
            else{
            cout << "your time is not in 24 hour format" << endl;
            return 0;
            }
        }
        count++;
    }
    cout << "your class Begins at: " << timeBegin << " And ends at: " << timeEnd << endl;
    return 0;
}