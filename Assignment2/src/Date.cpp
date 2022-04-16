//
// Created by Ecem Cirakoglu on 29.11.2021.
//
#include "Employee.h"
#include "Date.h"
#include <string>

using namespace std;

Date::Date(string date) {
    day = stoi(date.substr(0,2)) ;
    month =  stoi(date.substr(3,2));
    year = stoi(date.substr(6));
}

Date::~Date() {

}

int Date::getDay() {
    return this->day;
}
void Date::setDay(int the_day){
    day = the_day;
}
void Date::setMonth(int the_month){
    day = the_month;
}
void Date::setYear(int the_year){
    day = the_year;
}
int Date::getMonth() {
    return this->month;
}
int Date::getYear() {
    return this->year;
}

Date::Date() {
    year = 0;
    day = 0;
    month = 0;
}
/*
bool Date::operator<(const Date &rhs) const {
    if (day < rhs.day)
        return true;
    if (rhs.day < day)
        return false;
    if (month < rhs.month)
        return true;
    if (rhs.month < month)
        return false;
    return year < rhs.year;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}
*/