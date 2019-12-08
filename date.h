#include<bits/stdc++.h>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{public:
    int day;
    int month;
    int year;
    Date() 
    {
      day = 0;
      month = 0;
      year =0;
    }
    Date(int day, int month, int year) 
    {
    this->day = day;
    this->month = month;
    this->year = year;
    }
};

#endif