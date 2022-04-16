//
// Created by Ecem Cirakoglu on 29.11.2021.
//

#ifndef AS2_2_DATE_H
#define AS2_2_DATE_H

#include "Employee.h"
#include <iostream>

using namespace std;

class Date{
public:

    Date(string);
    Date();
    ~Date();
    int getDay();
    int getMonth();
    int getYear();

    void setDay(int);
    void setMonth(int);
    void setYear(int);
    //static bool SortByApp(Employee &Emp1,Employee &Emp2);

private:
    int day;
    int month;
    int year;

};

#endif //AS2_2_DATE_H
