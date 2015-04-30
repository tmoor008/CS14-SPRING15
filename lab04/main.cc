//Name: Tia Moore
//SID: 861144845
//Date: 5/1/15
//Approach:

#include <iostream>
#include <cstdlib>
#include "lab4.h"

using namespace std;

int main(int argc, char* argv[])
{
    int num = atoi(argv[1]);
    cout << "Pre-order" << endl;
    preorder(2, 1, num);
    preorder(3, 1, num);
    cout << endl;
    
    cout << "Post-order" << endl;
    postorder(2, 1, num);
    postorder(3, 1, num);
    cout << endl;
    
    // cout << "In-order" << endl;
    // inorder(2, 1, num);
    // inorder(3, 1, num);
    // cout << endl;
    
    return 0;
}