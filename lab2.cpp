#include <iostream>
#include <forward_list>
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
    
    cout << "Tests element swap" << endl;
    List test3;
    test3.push(5); 
    test3.push(6); 
    test3.push(8);
    test3.push(2);
    test3.push(9);
    cout << "List Before: ";
    test3.display();
    cout << endl;
    test3.elementSwap(0);
    cout << "List After: ";
    test3.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap sz 1" << endl;
    List test4;
    test4.push(5); 
    cout << "List Before: ";
    test4.display();
    cout << endl;
    test4.elementSwap(2);
    cout << "List After: ";
    test4.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap sz 2, pos 0" << endl;
    List test5;
    test5.push(57); 
    test5.push(12);
    cout << "List Before: ";
    test5.display();
    cout << endl;
    test5.elementSwap(0);
    cout << "List After: ";
    test5.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap sz 2, pos 1" << endl;
    List test6;
    test6.push(35); 
    test6.push(68);
    cout << "List Before: ";
    test6.display();
    cout << endl;
    test6.elementSwap(1);
    cout << "List After: ";
    test6.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap end" << endl;
    List test7;
    test7.push(22); 
    test7.push(7);
    test7.push(35);
    test7.push(88);
    test7.push(62);
    cout << "List Before: ";
    test7.display();
    cout << endl;
    test7.elementSwap(3);
    cout << "List After: ";
    test7.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests primeCount function" << endl;
    forward_list<Type> l9;
    l9.push_front(23);
    l9.push_front(15);
    l9.push_front(8);
    l9.push_front(56);
    cout << "List: ";
    print(l9);
    cout << endl;
    cout << "Number of primes: " << primeCount(l9) << endl;
    cout << endl;
    
    cout << "Tests primeCount function" << endl;
    forward_list<Type> l10;
    l10.push_front(35);
    l10.push_front(13);
    l10.push_front(29);
    l10.push_front(37);
    cout << "List: ";
    print(l10);
    cout << endl;
    cout << "Number of primes: " << primeCount(l10) << endl;
    cout << endl;
    
}