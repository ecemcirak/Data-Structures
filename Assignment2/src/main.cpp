#include<iostream>
#include "DoubleDynamicLinkedList.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "CircularArrayLinkedList.h"
#include <vector>
#include <algorithm>

using namespace std;

DoubleDynamicLinkedList <PermanentEmployee> Perm_list;
CircularArrayLinkedList<TemporaryEmployee> Temp_list;
vector<Employee> Employees;
vector<Employee> Employees2;




int main() {

    while (true) {

        int choice;
        cout << "____ Employee Recording System ____" << endl;
        cout << "Please select for the following Menu Operation:" << endl;
        cout << "1) Appointment of a new employee" << endl;
        cout << "2) Appointment of a transferred employee" << endl;
        cout << "3) Updating the title and salary coefficient of an employee" << endl;
        cout << "4) Deletion of an employee" << endl;
        cout << "5) Listing the information of an employee" << endl;
        cout << "6) Listing employees ordered by employee number" << endl;
        cout << "7) Listing employees ordered by appointment date" << endl;
        cout << "8) Listing employees appointed after a certain date" << endl;
        cout << "9) Listing employees assigned in a given year" << endl;
        cout << "10) Listing employees born before a certain date" << endl;
        cout << "11) Listing employees born in a particular month" << endl;
        cout << "12) Listing the information of the last assigned employee with a given title" << endl;
        cin >> choice;

        if (choice == 1) {
            int number;
            int type;
            string name;
            string surname;
            string title;
            int salary;
            string birth_date;
            string appointment;
            cout << "Type the employee number" << endl;
            cin >> number;
            cout << "Type the employee type" << endl;
            cin >> type;
            cout << "Type the name" << endl;
            cin.ignore();
            getline(cin,name);
            //cin >> name;
            cout << "Type surname" << endl;
            cin.ignore();
            //cin >> surname;
            getline(cin,surname);
            cout << "Type title" << endl;
            cin >> title;
            cout << "Type salary coefficient" << endl;
            cin >> salary;
            cout << "The birth date" << endl;
            cin >> birth_date;
            cout << "The appointment date" << endl;
            cin >> appointment;

            if (type == 0) {
                TemporaryEmployee temp(number, salary, type, name, surname, title, 0, birth_date, appointment);
                if (!Temp_list.checkNumberExist(number)) {
                    Temp_list.add(temp);
                    //Temp_Number.push_back(number);
                    Employees.push_back(temp);
                }

            }
            if (type == 1) {
                PermanentEmployee perm(number, salary, type, name, surname, title, 0, birth_date, appointment);
                if (!Perm_list.checkNumberExist(number)) {
                    Perm_list.add(perm);
                    //Perm_Number.push_back(number);
                    Employees.push_back(perm);
                }
            }
        }
        else if (choice == 2) {
            int number;
            int type;
            string name;
            string surname;
            string title;
            int salary;
            int service_in_other_institutions;
            string birth_date;
            string appointment;
            cout << "Type the employee number" << endl;
            cin >> number;
            cout << "Type the employee type" << endl;
            cin >> type;
            cout << "Type the name" << endl;
            cin.ignore();
            //cin >> name;
            getline(cin,name);
            cout << "Type surname" << endl;
            cin.ignore();
            getline(cin,surname);
            //cin >> surname;
            cout << "Type title" << endl;
            cin >> title;
            cout << "Type salary coefficient" << endl;
            cin >> salary;
            cout << "The birth date" << endl;
            cin >> birth_date;
            cout << "The appointment date" << endl;
            cin >> appointment;
            cout << "Type length of service days" << endl;
            cin >> service_in_other_institutions;

            if (type == 0) {
                TemporaryEmployee temp(number, salary, type, name, surname, title, service_in_other_institutions,
                                       birth_date, appointment);
                if (!Temp_list.checkNumberExist(number)) {
                    Temp_list.add(temp);
                    //Temp_Number.push_back(number);
                    Employees.push_back(temp);
                }

            }
            if (type == 1) {
                PermanentEmployee perm(number, salary, type, name, surname, title, service_in_other_institutions,
                                       birth_date, appointment);
                if (!Perm_list.checkNumberExist(number)) {
                    Perm_list.add(perm);
                    //Perm_Number.push_back(number);
                    Employees.push_back(perm);
                }
            }
        }
        else if (choice == 3) {
            int number;
            string title;
            int salary;
            cout << "Type the employee number" << endl;
            cin >> number;
            cout << "Type title" << endl;
            cin >> title;
            cout << "Type salary coefficient" << endl;
            cin >> salary;
            if (Temp_list.checkNumberExist(number)) {
                Temp_list.UpdateSalaryandTitle(number, salary, title);
                //cout << Temp_list.getTempEmp(number).getSalary() << endl;
                //cout << Temp_list.getTempEmp(number).getTitle() << endl;
            } else if (Perm_list.checkNumberExist(number)) {
                Perm_list.UpdateSalaryandTitle(number, salary, title);
                //cout << Perm_list.getPermEmp(number)->data.getSalary() << endl;
                //cout << Perm_list.getPermEmp(number)->data.getTitle() << endl;
            } else {
                cout << "Doesn't exist" << endl;
            }
        }
        else if (choice == 4) {
            int number;
            cout << "Type the employee number" << endl;
            cin >> number;
            if (Temp_list.checkNumberExist(number)) {
                Temp_list.deleteTemp(number);
                //Temp_Number.erase(find(Temp_Number.begin(), Temp_Number.end(), number));
                //cout << "Temp silindiyse 0 = " << Temp_list.checkNumberExist(number);

            } else if (Perm_list.checkNumberExist(number)) {
                Perm_list.removeByNumber(number);
                //Perm_Number.erase(find(Perm_Number.begin(), Perm_Number.end(), number));
                //cout << "Perm silindiyse 0 = " << Perm_list.checkNumberExist(number);
            } else {
                cout << "Doesn't exist" << endl;
            }
        }
        else if (choice == 5) {
            int number;
            cout << "Type the employee number" << endl;
            cin >> number;
            if (Temp_list.checkNumberExist(number)) {
                cout << "Employee Number: " << Temp_list.getTempEmp(number).getNumber() << endl;
                cout << "Employee Type: " << Temp_list.getTempEmp(number).getType() << endl;
                cout << "Employee Name: " << Temp_list.getTempEmp(number).getName() << endl;
                cout << "Employee Surname: " << Temp_list.getTempEmp(number).getSurname() << endl;
                cout << "Employee Salary: " << Temp_list.getTempEmp(number).getSalary() << endl;
                cout << "Employee Birth Date: " << Temp_list.getTempEmp(number).getBirth() << endl;
                cout << "Employee Appointment Date: " << Temp_list.getTempEmp(number).getApp() << endl;
                cout << "Employee Length of service in other institutions: "
                     << Temp_list.getTempEmp(number).getServiceInOtherInstitutions() << endl;
            } else if (Perm_list.checkNumberExist(number)) {
                cout << "Employee Number: " << (Perm_list.getPermEmp(number))->data.getNumber() << endl;
                cout << "Employee Type: " << Perm_list.getPermEmp(number)->data.getType() << endl;
                cout << "Employee Name: " << Perm_list.getPermEmp(number)->data.getName() << endl;
                cout << "Employee Surname: " << Perm_list.getPermEmp(number)->data.getSurname() << endl;
                cout << "Employee Salary: " << Perm_list.getPermEmp(number)->data.getSalary() << endl;
                cout << "Employee Birth Date: " << Perm_list.getPermEmp(number)->data.getBirth() << endl;
                cout << "Employee Appointment Date: " << Perm_list.getPermEmp(number)->data.getApp() << endl;
                cout << "Employee Length of service in other institutions: "
                     << Perm_list.getPermEmp(number)->data.getServiceInOtherInstitutions() << endl;

            } else {
                cout << "Doesn't exist" << endl;
            }
        }
        else if (choice == 6) {
            std::sort(Employees.begin(), Employees.end(), Employee::my_cmp);
            for (int j = 0; j < Employees.size(); j++) {
                //TEMPORARY
                if (Employees.at(j).getType() == 0) {
                    cout << "-------------------" << endl;
                    cout << "Temporary Employee" << endl;
                    cout << "Employee Number: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getNumber()
                         << endl;
                    cout << "Employee Type: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getType() << endl;
                    cout << "Employee Name: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getName() << endl;
                    cout << "Employee Surname: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getSurname()
                         << endl;
                    cout << "Employee Salary: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getSalary()
                         << endl;
                    cout << "Employee Birth Date: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getBirth()
                         << endl;
                    cout << "Employee Appointment Date: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getApp()
                         << endl;
                    cout << "Employee Length of service in other institutions: "
                         << Temp_list.getTempEmp(Employees.at(j).getNumber()).getServiceInOtherInstitutions() << endl;

                }
                    //PERMANENT
                else if (Employees.at(j).getType() == 1) {
                    cout << "-------------------" << endl;
                    cout << "Permanent Employee" << endl;
                    cout << "Employee Number: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getNumber()
                         << endl;
                    cout << "Employee Type: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getType()
                         << endl;
                    cout << "Employee Name: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getName()
                         << endl;
                    cout << "Employee Surname: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getSurname()
                         << endl;
                    cout << "Employee Salary: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getSalary()
                         << endl;
                    cout << "Employee Birth Date: "
                         << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getBirth() << endl;
                    cout << "Employee Appointment Date: "
                         << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getApp() << endl;
                    cout << "Employee Length of service in other institutions: "
                         << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getServiceInOtherInstitutions()
                         << endl;
                }
            }

        }
        else if (choice == 7) {
            sort(Employees.begin(), Employees.end(), Employee::SortByApp);
            for (int j = 0; j < Employees.size(); j++) {
                //TEMPORARY
                if (Employees.at(j).getType() == 0) {
                    cout << "-------------------" << endl;
                    cout << "Temporary Employee" << endl;
                    cout << "Employee Number: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getNumber()
                         << endl;
                    cout << "Employee Type: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getType() << endl;
                    cout << "Employee Name: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getName() << endl;
                    cout << "Employee Surname: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getSurname()
                         << endl;
                    cout << "Employee Salary: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getSalary()
                         << endl;
                    cout << "Employee Birth Date: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getBirth()
                         << endl;
                    cout << "Employee Appointment Date: " << Temp_list.getTempEmp(Employees.at(j).getNumber()).getApp()
                         << endl;
                    cout << "Employee Length of service in other institutions: "
                         << Temp_list.getTempEmp(Employees.at(j).getNumber()).getServiceInOtherInstitutions() << endl;
                }
                    //PERMANENT
                else if (Employees.at(j).getType() == 1) {
                    cout << "-------------------" << endl;
                    cout << "Permanent Employee" << endl;
                    cout << "Employee Number: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getNumber()
                         << endl;
                    cout << "Employee Type: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getType()
                         << endl;
                    cout << "Employee Name: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getName()
                         << endl;
                    cout << "Employee Surname: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getSurname()
                         << endl;
                    cout << "Employee Salary: " << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getSalary()
                         << endl;
                    cout << "Employee Birth Date: "
                         << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getBirth() << endl;
                    cout << "Employee Appointment Date: "
                         << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getApp() << endl;
                    cout << "Employee Length of service in other institutions: "
                         << Perm_list.getPermEmp(Employees.at(j).getNumber())->data.getServiceInOtherInstitutions()
                         << endl;
                }
            }
        }
        else if (choice == 8) {
            string date;
            Date *date_2;
            cout << "Please enter the date:" << endl;
            cin >> date;
            date_2 = new Date(date);

            for (int i = 0; i < Employees.size(); i++) {
                if (Employee::AfterInst(Employees.at(i), date_2)) {
                    Employees2.push_back(Employees.at(i));
                }
            }
            if (Employees2.size() != 0) {
                sort(Employees2.begin(), Employees2.end(), Employee::SortByAppNewToOld);
                for (int j = 0; j < Employees2.size(); j++) {
                    //TEMPORARY
                    if (Employees2.at(j).getType() == 0) {
                        cout << "-------------------" << endl;
                        cout << "Temporary Employee" << endl;
                        cout << "Employee Number: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getNumber() << endl;
                        cout << "Employee Type: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getType()
                             << endl;
                        cout << "Employee Name: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getName()
                             << endl;
                        cout << "Employee Surname: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSurname() << endl;
                        cout << "Employee Salary: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSalary() << endl;
                        cout << "Employee Birth Date: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getBirth() << endl;
                        cout << "Employee Appointment Date: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getApp() << endl;
                        cout << "Employee Length of service in other institutions: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getServiceInOtherInstitutions()
                             << endl;
                    }
                        //PERMANENT
                    else if (Employees2.at(j).getType() == 1) {
                        cout << "-------------------" << endl;
                        cout << "Permanent Employee" << endl;
                        cout << "Employee Number: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getNumber() << endl;
                        cout << "Employee Type: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getType() << endl;
                        cout << "Employee Name: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getName() << endl;
                        cout << "Employee Surname: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSurname() << endl;
                        cout << "Employee Salary: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSalary() << endl;
                        cout << "Employee Birth Date: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getBirth() << endl;
                        cout << "Employee Appointment Date: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getApp() << endl;
                        cout << "Employee Length of service in other institutions: " << Perm_list.getPermEmp(
                                Employees2.at(j).getNumber())->data.getServiceInOtherInstitutions() << endl;
                    }
                }
            }
        }
        else if (choice == 9) {
            int year;
            cout << "Please enter the year:" << endl;
            cin >> year;
            for (int i = 0; i < Employees.size(); i++) {
                if (Employees.at(i).getAppDate()->getYear() == year) {
                    Employees2.push_back(Employees.at(i));
                }
            }
            sort(Employees2.begin(), Employees2.end(), Employee::SortByApp);
            for (int j = 0; j < Employees2.size(); j++) {
                //TEMPORARY
                if (Employees2.at(j).getType() == 0) {
                    cout << "-------------------" << endl;
                    cout << "Temporary Employee" << endl;
                    cout << "Employee Number: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getNumber()
                         << endl;
                    cout << "Employee Type: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getType()
                         << endl;
                    cout << "Employee Name: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getName()
                         << endl;
                    cout << "Employee Surname: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSurname()
                         << endl;
                    cout << "Employee Salary: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSalary()
                         << endl;
                    cout << "Employee Birth Date: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getBirth() << endl;
                    cout << "Employee Appointment Date: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getApp() << endl;
                    cout << "Employee Length of service in other institutions: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getServiceInOtherInstitutions()
                         << endl;
                }
                    //PERMANENT
                else if (Employees2.at(j).getType() == 1) {
                    cout << "-------------------" << endl;
                    cout << "Permanent Employee" << endl;
                    cout << "Employee Number: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getNumber() << endl;
                    cout << "Employee Type: " << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getType()
                         << endl;
                    cout << "Employee Name: " << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getName()
                         << endl;
                    cout << "Employee Surname: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSurname() << endl;
                    cout << "Employee Salary: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSalary() << endl;
                    cout << "Employee Birth Date: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getBirth() << endl;
                    cout << "Employee Appointment Date: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getApp() << endl;
                    cout << "Employee Length of service in other institutions: " << Perm_list.getPermEmp(
                            Employees2.at(j).getNumber())->data.getServiceInOtherInstitutions() << endl;
                }
            }
        }
        else if (choice == 10) {
            string date;
            Date *date_2;
            cout << "Please enter the date:" << endl;
            cin >> date;
            date_2 = new Date(date);
            for (int i = 0; i < Employees.size(); i++) {
                if (Employee::BeforeThisDate(Employees.at(i), date_2)) {
                    Employees2.push_back(Employees.at(i));
                }
            }
            if (Employees2.size() != 0) {
                sort(Employees2.begin(), Employees2.end(), Employee::SortByApp);
                for (int j = 0; j < Employees2.size(); j++) {
                    //TEMPORARY
                    if (Employees2.at(j).getType() == 0) {
                        cout << "-------------------" << endl;
                        cout << "Temporary Employee" << endl;
                        cout << "Employee Number: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getNumber() << endl;
                        cout << "Employee Type: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getType()
                             << endl;
                        cout << "Employee Name: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getName()
                             << endl;
                        cout << "Employee Surname: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSurname() << endl;
                        cout << "Employee Salary: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSalary() << endl;
                        cout << "Employee Birth Date: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getBirth() << endl;
                        cout << "Employee Appointment Date: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getApp() << endl;
                        cout << "Employee Length of service in other institutions: "
                             << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getServiceInOtherInstitutions()
                             << endl;
                    }
                        //PERMANENT
                    else if (Employees2.at(j).getType() == 1) {
                        cout << "-------------------" << endl;
                        cout << "Permanent Employee" << endl;
                        cout << "Employee Number: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getNumber() << endl;
                        cout << "Employee Type: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getType() << endl;
                        cout << "Employee Name: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getName() << endl;
                        cout << "Employee Surname: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSurname() << endl;
                        cout << "Employee Salary: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSalary() << endl;
                        cout << "Employee Birth Date: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getBirth() << endl;
                        cout << "Employee Appointment Date: "
                             << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getApp() << endl;
                        cout << "Employee Length of service in other institutions: " << Perm_list.getPermEmp(
                                Employees2.at(j).getNumber())->data.getServiceInOtherInstitutions() << endl;
                    }
                }
            }

        }
        else if (choice == 11) {
            int month;
            cout << "Please enter the month:" << endl;
            cin >> month;
            for (int i = 0; i < Employees.size(); i++) {
                if (Employees.at(i).getBirthDate()->getMonth() == month) {
                    Employees2.push_back(Employees.at(i));
                }
            }
            sort(Employees2.begin(), Employees2.end(), Employee::SortByApp);
            for (int j = 0; j < Employees2.size(); j++) {
                //TEMPORARY
                if (Employees2.at(j).getType() == 0) {
                    cout << "-------------------" << endl;
                    cout << "Temporary Employee" << endl;
                    cout << "Employee Number: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getNumber()
                         << endl;
                    cout << "Employee Type: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getType()
                         << endl;
                    cout << "Employee Name: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getName()
                         << endl;
                    cout << "Employee Surname: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSurname() << endl;
                    cout << "Employee Salary: " << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getSalary()
                         << endl;
                    cout << "Employee Birth Date: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getBirth() << endl;
                    cout << "Employee Appointment Date: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getApp() << endl;
                    cout << "Employee Length of service in other institutions: "
                         << Temp_list.getTempEmp(Employees2.at(j).getNumber()).getServiceInOtherInstitutions()
                         << endl;
                }
                    //PERMANENT
                else if (Employees2.at(j).getType() == 1) {
                    cout << "-------------------" << endl;
                    cout << "Permanent Employee" << endl;
                    cout << "Employee Number: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getNumber() << endl;
                    cout << "Employee Type: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getType() << endl;
                    cout << "Employee Name: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getName() << endl;
                    cout << "Employee Surname: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSurname() << endl;
                    cout << "Employee Salary: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getSalary() << endl;
                    cout << "Employee Birth Date: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getBirth() << endl;
                    cout << "Employee Appointment Date: "
                         << Perm_list.getPermEmp(Employees2.at(j).getNumber())->data.getApp() << endl;
                    cout << "Employee Length of service in other institutions: " << Perm_list.getPermEmp(
                            Employees2.at(j).getNumber())->data.getServiceInOtherInstitutions() << endl;
                }
            }


        }
        else if (choice == 12) {
            string title;
            cout << "Please Enter the Title" << endl;
            cin >> title;
            for (int i = 0; i < Employees.size(); i++) {
                if (Employees.at(i).getTitle() == title) {
                    Employees2.push_back(Employees.at(i));
                }
            }
            sort(Employees2.begin(), Employees2.end(), Employee::SortByAppNewToOld);
            if (Employees2.at(0).getType() == 0) {
                //TEMPORARY
                cout << "Employee Number: " << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getNumber()
                     << endl;
                cout << "Employee Type: " << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getType() << endl;
                cout << "Employee Name: " << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getName() << endl;
                cout << "Employee Surname: " << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getSurname()
                     << endl;
                cout << "Employee Salary: " << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getSalary()
                     << endl;
                cout << "Employee Birth Date: " << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getBirth()
                     << endl;
                cout << "Employee Appointment Date: "
                     << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getApp() << endl;
                cout << "Employee Length of service in other institutions: "
                     << Temp_list.getTempEmp(Employees2.at(0).getNumber()).getServiceInOtherInstitutions() << endl;
            } else {
                //PERMANENT
                cout << "Employee Number: "
                     << (Perm_list.getPermEmp(Employees2.at(0).getNumber()))->data.getNumber() << endl;
                cout << "Employee Type: " << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getType()
                     << endl;
                cout << "Employee Name: " << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getName()
                     << endl;
                cout << "Employee Surname: "
                     << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getSurname() << endl;
                cout << "Employee Salary: " << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getSalary()
                     << endl;
                cout << "Employee Birth Date: "
                     << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getBirth() << endl;
                cout << "Employee Appointment Date: "
                     << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getApp() << endl;
                cout << "Employee Length of service in other institutions: "
                     << Perm_list.getPermEmp(Employees2.at(0).getNumber())->data.getServiceInOtherInstitutions()
                     << endl;
            }
        }
        else{
            exit(1);
        }




        Employees2.clear();
    }
}



