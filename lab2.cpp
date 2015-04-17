#include <iostream>
#include "lab2.h"

using namespace std;

int main()
{
    cout << "Welcome" << endl;
    
    cout << "Test is prime: ";
    int test = 1;
    bool a = isPrime(test);
    
    if (a == true)
    {
        cout << "Prime" << endl;
    }
    
    else
    {
        cout << "Not Prime" << endl;
    }
    cout << endl;
    
    cout << "Tests listCopy: " << endl;
    cout << "Empty second list case: " << endl;
    forward_list<Type> l1;
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(7);
    l1.push_front(1);
    cout << "List 1: ";
    print(l1);
    cout << endl;
    forward_list<Type> l2;
    listCopy(l1, l2);
    cout << "List 2: ";
    print(l2);
    cout << endl << endl;
    
    cout << "Filled second list case" << endl;
    forward_list<Type> l3;
    l3.push_front(6);
    l3.push_front(2);
    l3.push_front(8);
    l3.push_front(4);
    cout << "List 1: ";
    print(l3);
    cout << endl;
    forward_list<Type> l4;
    l4.push_front(5);
    l4.push_front(7);
    l4.push_front(11);
    l4.push_front(9);
    cout << "List 2: ";
    print(l4);
    cout << endl; 
    cout << "Copied List 2: ";
    listCopy(l3, l4);
    print(l4);
    cout << endl << endl;
    
    cout << "Tests printLots: " << endl;
    forward_list<Type> l5;
    l5.push_front(15);
    l5.push_front(18);
    l5.push_front(12);
    l5.push_front(19);
    l5.push_front(11);
    cout << "List 1(Inputs): ";
    print(l5);
    cout << endl;
    forward_list<int> l6;
    l6.push_front(3);
    l6.push_front(2);
    l6.push_front(1);
    cout << "List 2 (Positions): ";
    print(l6);
    cout << endl; 
    cout << "Printlots: ";
    printLots(l5, l6);
    cout << endl << endl;
    
    cout << "Tests printLots: " << endl;
    forward_list<Type> l7;
    l7.push_front(23);
    l7.push_front(35);
    l7.push_front(67);
    l7.push_front(79);
    l7.push_front(51);
    l7.push_front(13);
    cout << "List 1(Inputs): ";
    print(l7);
    cout << endl;
    forward_list<int> l8;
    l8.push_front(9); //should go out of bounds and print nothing
    l8.push_front(5);
    l8.push_front(2);
    l8.push_front(0);
    cout << "List 2 (Positions): ";
    print(l8);
    cout << endl; 
    cout << "Printlots: ";
    printLots(l7, l8);
    cout << endl << endl;
    
}