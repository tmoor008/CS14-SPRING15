//Name: Tia Moore
//SID: 861144845
//Date: 4/25/15
//Approach: In this lab I implemented Fixed and Optimal two stack classes which
//use a single array to hold their stacked values. Stack1 starts from the left 
//hand side of the array and Stack2 starts at the end of the array. They move 
//in opposite directions. Both classes have a push funtion which adds a value
//on "top" on the stack, incrementing the top holder and inserting the value.
//The push checks if the stack is full and then increments the top holder as
//well as adds the value. Both also have a pop fuction which decrements the top 
//holder and deletes the value using a simple decrementation of the top holder 
//and checking if the list is empty. I also implemented a function which
//solves the Tower of Hanoi problem. The function calls itself recursively,
//using n = 1 as its base case and several calls to itself which change the
//source, auxiliary and destination stacks accordingly. 

#include <iostream>
#include "lab3.h"

using namespace std;

int main()
{
    // int size;
    // int maxtop;
    
    // cout << "Enter size: ";
    // cin >> size;
    // cout << endl;
    
    // cout << "Enter maxtop: ";
    // cin >> maxtop;
    // cout << endl;
    
    cout << " - TwoStackFixed Tests - " << endl;
    TwoStackFixed<int> test1(8, 3);
    cout << "Tests push on stack1: " << endl;
    test1.pushStack1(30);
    test1.pushStack1(12);
    test1.pushStack1(45);
    cout << endl << endl;
    
    cout << "Tests push on stack2: " << endl;
    test1.pushStack2(56);
    test1.pushStack2(73);
    test1.pushStack2(13);
    test1.pushStack2(38);
    cout << endl << endl;
    
    cout << "Tests pop on stack1: " << endl;
    cout << "Value popped: " << test1.popStack1() << endl;
    cout << "Value popped: " << test1.popStack1();
    cout << endl << endl;
    
    cout << "Tests pop on stack2: " << endl;
    cout << "Value popped: " << test1.popStack2() << endl;
    cout << "Value popped: " << test1.popStack2();
    cout << endl << endl;
    
    cout << "Tests display: " << endl;
    test1.display();
    cout << endl << endl;
    
    cout << " - Tests TwoStackOptimal - " << endl;
    TwoStackOptimal<int> test2(10);
    cout << "Tests push on stack1: " << endl;
    test2.pushFlexStack1(44);
    test2.pushFlexStack1(17);
    test2.pushFlexStack1(84);
    test2.pushFlexStack1(66);
    test2.pushFlexStack1(24);
    cout << endl << endl;
    
    cout << "Tests push on stack2: " << endl;
    test2.pushFlexStack2(35);
    test2.pushFlexStack2(62);
    test2.pushFlexStack2(47);
    test2.pushFlexStack2(96);
    test2.pushFlexStack2(22);
    test2.pushFlexStack2(11); //will go out of bounds bc run out of room
    cout << endl << endl;
    
    cout << "Tests pop on stack1: " << endl;
    cout << "Value popped: " << test2.popFlexStack1() << endl;
    cout << "Value popped: " << test2.popFlexStack1() << endl;
    test2.display();
    cout << endl << endl;
    
    cout << "Tests pop on stack2: " << endl;
    cout << "Value popped: " << test2.popFlexStack2() << endl;
    cout << "Value popped: " << test2.popFlexStack2() << endl;
    test2.display();
    cout << endl << endl;
    
    cout << "Test if stack1 fills entire array" << endl;
    TwoStackOptimal<int> test3(5);
    test3.pushFlexStack1(9);
    test3.pushFlexStack1(2);
    test3.pushFlexStack1(5);
    test3.pushFlexStack1(3);
    test3.pushFlexStack1(1);
    test3.pushFlexStack1(8); //should output error bc goes out of array
    cout << endl;
    
    cout << "Tests pop on full array stack1" << endl;
    cout << "Value Popped: " << test3.popFlexStack1() << endl;
    test3.display();
    cout << endl;
    
    cout << "Test if stack2 fills entire array" << endl;
    TwoStackOptimal<int> test4(3);
    test4.pushFlexStack2(2);
    test4.pushFlexStack2(4);
    test4.pushFlexStack2(6);
    test4.pushFlexStack2(7); //should output error bc goes out of array
    cout << endl;
    
    cout << "Tests pop on full array stack2" << endl;
    cout << "Value Popped: " << test4.popFlexStack2() << endl;
    test4.display();
    cout << endl;
    
    cout << " - Tests Tower of Hanoi - " << endl;
    int n = 3;
    stack<int> A;
    for(int i = n; i > 0; --i) 
    {
        A.push(i);
    }

    cout<<"Stack start: "<< endl;
    print(A);
    cout << endl << endl;
    stack<int> B;
    stack<int> C;
    showTowerStates(n, A, B, C);
    cout << endl;
    cout<<"Stack end: "<< endl;
    print(C);
    cout << endl;
    
    return 0;
}