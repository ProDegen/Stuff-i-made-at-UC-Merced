#ifndef TIME_H
#define TIME_H
#include <iostream>
class timeStrip{
    private:
    int hour;
    int minute;
    int second;
    std::string input;
    public:
    timeStrip(std::string input, int hour, int minute,int second);

};

 
#endif