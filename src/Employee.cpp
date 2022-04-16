//
// Created by Ecem Cirakoglu on 24.11.2021.
//

#include "Employee.h"
#include "Date.h"
#include<string>

using namespace std;

Employee::Employee(int the_number, int the_salary,int the_type, string the_name, string the_surname ,string the_title,
                   int the_institutions, string the_birth, string the_appointment){
    number = the_number;
    salary = the_salary;
    name = the_name;
    surname = the_surname;
    title = the_title;
    type = the_type;
    service_in_other_institutions = the_institutions;
    date_of_appointment2 = the_appointment;
    date_of_birth2 = the_birth;
    //CREATING DATE CLASS MEMBER
    date_of_birth = new Date(the_birth);
    date_of_appointment = new Date(the_appointment);
};

int Employee::getServiceInOtherInstitutions() const {
    return service_in_other_institutions;
}
int Employee::getType() const {
    return type;
}
const string &Employee::getName() const {
    return name;
}
const string &Employee::getSurname() const {
    return surname;
}
Date * Employee::getBirthDate(){
    return date_of_birth ;
}
Date * Employee::getAppDate(){
    return date_of_appointment ;
}
void Employee::setSalary(int n){
    salary = n;
}
int Employee::getSalary(){
    return salary;
}
const string &Employee::getBirth() const {
    return date_of_birth2;
}
const string &Employee::getApp() const {
    return date_of_appointment2;
}

bool Employee::SortByApp(Employee &Emp1, Employee &Emp2) {
    if (Emp1.getAppDate()->getYear() > Emp2.getAppDate()->getYear())
        return true;
    if (Emp1.getAppDate()->getMonth()== Emp2.getAppDate()->getYear() &&
        Emp1.getAppDate()->getMonth() > Emp2.getAppDate()->getMonth())
        return true;

    if (Emp1.getAppDate()->getYear() == Emp2.getAppDate()->getYear() &&
        Emp1.getAppDate()->getMonth() == Emp2.getAppDate()->getMonth() &&
        Emp1.getAppDate()->getDay() > Emp2.getAppDate()->getDay())
        return true;

    // If none of the above cases satisfy, return false
    return false;
}

string &Employee::getTitle(){
    return title;
}
void Employee::setTitle(string s) {
    title = s;
}

int Employee::getNumber() const {
    return number;
}
Employee::~Employee() {

}
Employee::Employee() {

}
bool Employee::SortByAppNewToOld(Employee &Emp1, Employee &Emp2) {

    if (Emp1.getAppDate()->getYear() > Emp2.getAppDate()->getYear())
        return true;
    if (Emp1.getAppDate()->getMonth()== Emp2.getAppDate()->getYear() &&
        Emp1.getAppDate()->getMonth() > Emp2.getAppDate()->getMonth())
        return true;

    if (Emp1.getAppDate()->getYear() == Emp2.getAppDate()->getYear() &&
        Emp1.getAppDate()->getMonth() == Emp2.getAppDate()->getMonth() &&
        Emp1.getAppDate()->getDay() > Emp2.getAppDate()->getDay())
        return true;

    // If none of the above cases satisfy, return false
    return false;

}

bool Employee::my_cmp(const Employee &Emp1,const Employee &Emp2) {
    return Emp1.number < Emp2.number;
}

bool Employee::AfterInst(Employee &Emp1, Date *date) {
    if (Emp1.getAppDate()->getYear() > date->getYear())
        return true;
    if (Emp1.getAppDate()->getMonth()== date->getYear()&&
        Emp1.getAppDate()->getMonth() > date->getMonth())
        return true;

    if (Emp1.getAppDate()->getYear() == date->getYear()&&
        Emp1.getAppDate()->getMonth() == date->getMonth() &&
        Emp1.getAppDate()->getDay() > date->getDay())
        return true;

    return false;
}

bool Employee::BeforeThisDate(Employee &Emp1, Date *date){
        if (Emp1.getAppDate()->getYear() < date->getYear())
            return true;
        if (Emp1.getAppDate()->getMonth()== date->getYear()&&
            Emp1.getAppDate()->getMonth() < date->getMonth())
            return true;

        if (Emp1.getAppDate()->getYear() == date->getYear()&&
            Emp1.getAppDate()->getMonth() == date->getMonth() &&
            Emp1.getAppDate()->getDay() < date->getDay())
            return true;

        return false;
}

