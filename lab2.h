//Name: Tia Moore
//SID: 861144845
//Date: 4/16/15
//Approach:

#ifndef __LAB2_H__
#define __LAB2_H__

#include <iostream>
#include <sstream>
#include <forward_list>

typedef int Type;

using namespace std;

// template <typename Type>

class Node
{
    friend class List;
    
    private:
        Type data;
        Node *next;
        
    public:
        Node(Type data);
};

class List
{
    private:
        Node *head;
        Node *tail;
    
    public:
        List();
        List(List &list);
        ~List();
        List(const string &str);
        void display() const;
        void push(char val);
        void elementSwap(int pos);
};


#endif