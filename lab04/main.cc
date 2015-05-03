//Name: Tia Moore
//SID: 861144845
//Date: 5/3/15
//Approach: In this lab I created three different traversal functions to
//traverse through a specific tree and print it's value in a certain order.
//For preorder and postorder traversal I used recursive calls and a specifically
//placed cout statement to output them in the correct order. For the sorted
//order I used a priority_queue class which allows me to store the values in
//a vector. The sorted traversal uses recursive calls to store each set of
//values into the vector using a push function. The push funtion not only stores
//the values but sorts them into the correct ascending sum order. A print
//function then iterates through the vector and prints its values. 

#include <iostream>
#include <cstdlib>
#include "lab4.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Error: No value entered to run program. Aborting." << endl;
        exit(-1);
    }
    
    int num = atoi(argv[1]);
    cout << "Pre-order" << endl;
    preorder(2, 1, num);
    preorder(3, 1, num);
    cout << endl;
    
    cout << "Post-order" << endl;
    postorder(2, 1, num);
    postorder(3, 1, num);
    cout << endl;
    
    cout << "Sorted" << endl;
    priority_queue q;
    inorder(2, 1, num, q);
    inorder(3, 1, num, q);
    q.print();
    cout << endl;
    
    // various test cases
    // cout << "Tests case where no nodes should be printed." << endl;
    // int num1 = 0;
    // cout << "Pre-order" << endl;
    // preorder(2, 1, num1);
    // preorder(3, 1, num1);
    // cout << endl;
    
    // cout << "Post-order" << endl;
    // postorder(2, 1, num1);
    // postorder(3, 1, num1);
    // cout << endl;
    
    // cout << "Sorted" << endl;
    // priority_queue q1;
    // inorder(2, 1, num1, q1);
    // inorder(3, 1, num1, q1);
    // q1.print();
    // cout << endl;
    
    // cout << "Tests case where only (2, 1) should print" << endl;
    // int num2 = 4;
    // cout << "Pre-order" << endl;
    // preorder(2, 1, num2);
    // preorder(3, 1, num2);
    // cout << endl;
    
    // cout << "Post-order" << endl;
    // postorder(2, 1, num2);
    // postorder(3, 1, num2);
    // cout << endl;
    
    // cout << "Sorted" << endl;
    // priority_queue q2;
    // inorder(2, 1, num2, q2);
    // inorder(3, 1, num2, q2);
    // q2.print();
    // cout << endl;
    
    // cout << "Tests normal case" << endl;
    // int num3 = 7;
    // cout << "Pre-order" << endl;
    // preorder(2, 1, num3);
    // preorder(3, 1, num3);
    // cout << endl;
    
    // cout << "Post-order" << endl;
    // postorder(2, 1, num3);
    // postorder(3, 1, num3);
    // cout << endl;
    
    // cout << "Sorted" << endl;
    // priority_queue q3;
    // inorder(2, 1, num3, q3);
    // inorder(3, 1, num3, q3);
    // q3.print();
    // cout << endl;
    
    return 0;
}