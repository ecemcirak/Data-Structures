//
// Created by Ecem Cirakoglu on 26.11.2021.
//

#ifndef AS2_2_DOUBLEDYNAMICLINKEDLIST_H
#define AS2_2_DOUBLEDYNAMICLINKEDLIST_H

#include "iostream"
#include <string.h>
#include "Employee.h"

using namespace std;

template<class K>
struct Node2{
    K data;
    Node2<K> *next;
    Node2<K> *prev;
};

template<class K>
class DoubleDynamicLinkedList {
public:
    Node2<K> *head;
    Node2<K> *tail;

    DoubleDynamicLinkedList<K>() {
        head = NULL;
        tail = NULL;
    }

    void add(K data) {

        if(head == NULL)
        {
            head = new Node2<K>;
            head->data = data;
            head->next = head;
            tail = head;
            head->prev = tail;
        }
        else
        {
            Node2<K> *newNode = new Node2<K>;
            tail->next = newNode;
            newNode->data = data;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void removeByNumber(int number){
        struct Node2<K>* temp = head;
        struct Node2<K>* tempAhead = head->next;

        //
        //
        // if linked list empty
        if(head == NULL)
        {
            cout << "There's no user in linked list" << endl;
            return;
        }



        //If only there's 1 element in linked list
        if(tail == head)
        {
            head = NULL;
            tail = NULL;
            delete(temp);
            return;
        }


        if(head->data.getNumber() == number)
        {
            head = tempAhead;
            delete(temp);
            head->prev = tail;
            tail->next = head;
            return;
        }
        //
        //If searhing number at the end of the linked list
        if(tail->data.getNumber() == number)
        {
            while (tempAhead->next != head)
            {
                temp = temp->next;
                tempAhead = tempAhead->next;
            }
            tail = temp;
            tail->prev = temp->prev;
            tail->next = head; // connecting circular linked listed again
            delete(tempAhead);
            return;
        }
        //
        while(tempAhead->next != head)
        {
            if(tempAhead->data.getNumber() == number)
            {
                temp->next = tempAhead->next;
                tempAhead->next->prev = temp;
                delete(tempAhead);
            }
            temp = temp->next;
            tempAhead = tempAhead->next;
        }
    }

    void display() {
        Node2<K> *temp;
        temp = head;
        if(head == NULL)
        {
            cout << "Empty list" << endl; // DELETE
            return;
        }
        else
        {
            while (temp != tail)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << tail->data << endl;
        }

    }


    bool checkNumberExist(int number)
    {
        struct Node2<K> *temp = head;

        if(temp == NULL)
            return false;

        if(tail->data.getNumber() == number)
        {
            return true;
        }

        while (temp != tail)
        {
            if(temp->data.getNumber() == number)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void UpdateSalaryandTitle(int the_number,int salary, string title){
        struct Node2<K> *exmp;
        exmp = getPermEmp(the_number);
        exmp->data.setSalary(salary);
        exmp->data.setTitle(title);

    }

    Node2<K>* getPermEmp(int the_number)
    {
        struct Node2<K> *temp = head;

        if(tail->data.getNumber() == the_number)
        {
            return tail;
        }
        while(temp != tail)
        {
            if(temp->data.getNumber() == the_number)
            {
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }
};

#endif //AS2_2_DOUBLEDYNAMICLINKEDLIST_H
