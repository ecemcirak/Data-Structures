//
// Created by Ecem Cirakoglu on 26.11.2021.
//


#ifndef AS2_2_PERMANENTEMPLOYEE_H
#define AS2_2_PERMANENTEMPLOYEE_H


#include "Employee.h"
#include "Date.h"

#include <utility>

using namespace std;

class PermanentEmployee : public Employee {
public:
    PermanentEmployee() = default;

    ~PermanentEmployee() = default;

    PermanentEmployee(int the_number, int the_salary,int the_type, string the_name,
                      string the_surname ,string the_title, int the_institutions,string birth_date,string the_appointment):Employee(the_number,the_salary,the_type,std::move(the_name),
                                                                                                                                    std::move(the_surname) ,std::move(the_title),the_institutions,std::move(birth_date),std::move(the_appointment)){}

};

#endif //AS2_2_PERMANENTEMPLOYEE_H
