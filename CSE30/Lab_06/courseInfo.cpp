#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <algorithm>
using namespace std;  
int main()
{
    int size = 0,courseDex = 0,count = 0;
    double grdAvg = 0,courses = 0;;
    string info[100],timeBegin = "",zero = "0",timeEnd = "",credits = "",days = "";
    //open file and copy its contents
    //note when it came to the days of class it wouldnt copy down the whole line so
    //"monday" "and" and "tuesday" were all condisdered different variables
    //i went and added _ to the words as a temp fix for now
    ifstream myinfile("in.txt");
    while(!myinfile.eof()){
        myinfile >> info[size];
        size++;
    }
    myinfile.close();
    courses = stof(info[courseDex]);
    //a copy of how many courses he wants as a float
    cout << "-------------------"<< endl;
    cout << "SCHEDULE OF STUDENT" << endl;
    cout << "-------------------"<< endl;
    //loop incase he wants more than 1 course
    for(int i = 0; i < courses;i++){
        if (info[courseDex] > "0"){
            
            //simple printing and counting up 
            cout << "COURSE " << i+1 << ": ";
            courseDex++;
            cout << info[courseDex] << endl;
            courseDex++;
            credits = info[courseDex];
            courseDex++;
            //simple check to see if the course is requried
            if(info[courseDex] == "1"){
                cout << "Note: this course is a major requirment!" << endl;
                courseDex++;
            }
            else{
                cout << "Note: this course is NOT a major requirment!" << endl;
                courseDex++;
            }
            //prints course credits
            cout << "Number of credits: " << credits << endl;
            //copies gradavg so we can use later
            grdAvg = stof(info[courseDex]);
            courseDex++;
            //prints days of lectur, breaks if the days are seperated by a space
            cout << "Days of lecture: " << info[courseDex] << endl;
            courseDex++;
            //this is just a copy of the last excerise with out new values
            stringstream time(info[courseDex]);
            string segment;
            vector<string> seglist;
            timeBegin = "";
            while(getline(time, segment, ':')){
                seglist.push_back(segment);
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
            courseDex++;
            string timeEnd = " "; 
            count = 0;
            stringstream time2(info[courseDex]);
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
            count = 0;
            //print time and grd avg
            cout << "Lecture time: " << timeBegin << "-" << timeEnd << endl;
            cout << "Stat: on average students get " << grdAvg << "% in this course" << endl;
            cout << "\n";
        }
        //if student says he wants 0 classes this is what runs
        else{
            cout << setfill ('-') << setw (10) << endl;
            cout << "SCHEDULE OF STUDENT" << endl;
            cout << setfill ('-') << setw (10) << endl;
        }
    }
    return 0;
}