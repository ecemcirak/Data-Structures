//
// Created by Ecem Cirakoglu on 21.11.2021.
//

#ifndef AS2_2_EMPLOYEE_H
#define AS2_2_EMPLOYEE_H

#include<iostream>
#include<string>
#include "Date.h"

using namespace std;

class Employee{
private:
    int number;
    int type;
    string name;
    string surname;
    string title;
    int salary;
    int service_in_other_institutions;
    string date_of_birth2;
    string date_of_appointment2;
    Date *date_of_birth;
    Date *date_of_appointment;

public:

    Employee();
    ~Employee();
    Employee(int, int ,int,string ,string,string,int, string, string);
    int getNumber() const;
    int getSalary();
    void setSalary(int);
    string &getTitle();
    void setTitle(string);
    const string &getSurname() const;
    const string &getName() const;
    int getType() const;
    int getServiceInOtherInstitutions() const;
    static bool my_cmp( const Employee &Emp1,const Employee &Emp2);
    const string &getBirth() const;
    const string &getApp() const;
    Date * getBirthDate();
    Date * getAppDate();
    static bool SortByApp(Employee &Emp1, Employee &Emp2);
    static bool AfterInst(Employee &Emp1, Date *date);
    static bool SortByAppNewToOld(Employee &Emp1, Employee &Emp2);
    static bool BeforeThisDate(Employee &Emp1, Date *date);
};


#endif //AS2_2_EMPLOYEE_H
