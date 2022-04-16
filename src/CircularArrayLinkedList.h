//
// Created by Ecem Cirakoglu on 26.11.2021.
//
#ifndef AS2_2_CIRCULARARRAYLINKEDLIST_H
#define AS2_2_CIRCULARARRAYLINKEDLIST_H

#include<iostream>
#include "Employee.h"

#define NUMNODES 20

using namespace std;


template<class K>
struct Nodetype{
    K info;
    int next;
};


template<class K>
class CircularArrayLinkedList{
public:

    int avail=0;
    int head=-1;
    int tail=-1;
    int countEmp;


    Nodetype<K> node[NUMNODES];

    CircularArrayLinkedList<K>(){

        for(int i=0; i<NUMNODES-1; i++){
            node[i].next = i+1;

        }
        node[NUMNODES-1].next = -1;
    }

    void add(K data){
        if(head == -1 && tail == -1){
            int q1;
            q1 = getnode();
            node[q1].info = data;
            tail = q1;
            head = q1;
            countEmp++;
        }
        else{
            int q2;
            q2 = getnode();
            node[tail].next = q2;
            node[q2].info = data;
            tail = q2;
            node[q2].next = head;
            countEmp++;
        }

    }
    int getnode(){
        int p;
        if(avail == -1){
            exit(1);
        }
        p = avail;
        avail = node[avail].next;
        return p;
    }
    void UpdateSalaryandTitle(int the_number,int salary, string title){
        for(int i=head; i <= tail; i++){
            if(node[i].info.getNumber() == the_number && i != avail){
                node[i].info.setSalary(salary);
                node[i].info.setTitle(title);
                break;
            }
        }
    }
    bool checkNumberExist(int the_number){
        for(int i=head; i <= tail; i++){
            if(node[i].info.getNumber() == the_number && i != avail){
                return true;
            }
        }
        return false;
    }
    K getTempEmp(int the_number){
        int i=0;
        for( i=head; i <= tail; i++){
            if(node[i].info.getNumber() == the_number && i != avail ){
                return node[i].info;
            }
        }
        return node[i].info;
    }

    void freenode(int p){
        node[p].next = avail;
        avail = p;
        return;
    }
    void deleteTemp(int the_number) {
        int k;
        if (head != -1 && tail != -1) {
            int i = head;
            while (node[i].next != head) {
                k = node[i].next;
                //ONE ELEMENT
                if(head == tail){
                    freenode(i);
                    countEmp=0;
                    return;
                }
                //Deleting from the end
                if(node[k].next== head && node[k].info.getNumber() == the_number && countEmp > 1){
                    tail = i;
                    node[i].next = head;
                    avail = k;
                    countEmp--;
                    //cout << "1";
                    return;
                }
                    //DELETING THE FIRST ELEMENT
                else if (i == head && node[i].info.getNumber() == the_number && countEmp > 1) {
                    head = node[i].next;
                    node[tail].next = head;
                    freenode(i);
                    node[head].next = avail;
                    countEmp--;
                    return;
                }
                else if (node[k].next != head && node[k].info.getNumber() == the_number ) {
                    node[i].next = node[k].next;
                    node[k].next = k;
                    avail = k;
                    countEmp--;
                    return;
                }

                i = node[i].next;

            }
        }
    }
};

#endif //AS2_2_CIRCULARARRAYLINKEDLIST_H
