#include "selectionsort.h"
#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

int main()
{
    cout << " - Sample Output - " << endl;
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(9);
    selectionsort(v);
    
    vector<int> vv;
    selectionsort(vv);
    
    vector<pair<int, int>> p;
    pair<int, int> p1(1, 2);
    pair<int, int> p2(3, -1);
    pair<int, int> p3(-1, 3);
    pair<int, int> p4(0, 0);
    pair<int, int> p5(2, 3);
    pair<int, int> p6(1, 2);
    pair<int, int> p7(1, -2);
    pair<int, int> p8(8, 10);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    p.push_back(p6);
    p.push_back(p7);
    p.push_back(p8);
    selectionsort(p);
    
    list<pair<int, int>> w;
    pair<int, int> w1(10, 2);
    pair<int, int> w2(-3, -1);
    pair<int, int> w3(-8, 0);
    pair<int, int> w4(1, 1);
    pair<int, int> w5(1, 1);
    pair<int, int> w6(0, 0);
    pair<int, int> w7(10, 2);
    pair<int, int> w8(5, 5);
    pair<int, int> w9(5, -5);
    pair<int, int> w10(0, 0);
    pair<int, int> w11(10, 2);
    w.push_back(w1);
    w.push_back(w2);
    w.push_back(w3);
    w.push_back(w4);
    w.push_back(w5);
    w.push_back(w6);
    w.push_back(w7);
    w.push_back(w8);
    w.push_back(w9);
    w.push_back(w10);
    w.push_back(w11);
    selectionsort(w);
    
    vector<pair<int, int>> q;
    pair<int, int> q1(-1, 3);
    pair<int, int> q2(0 ,0);
    pair<int, int> q3(1, -2);
    pair<int, int> q4(1, 2);
    pair<int, int> q5(1, 2);
    pair<int, int> q6(2, 3);
    pair<int, int> q7(3, -1);
    pair<int, int> q8(8, 10);
    q.push_back(q1);
    q.push_back(q2);
    q.push_back(q3);
    q.push_back(q4);
    q.push_back(q5);
    q.push_back(q6);
    q.push_back(q7);
    q.push_back(q8);
    selectionsort(q);
    
    cout <<  " - Extra Tests - " << endl;
    list<int> l;
    l.push_back(3);
    l.push_back(7);
    l.push_back(1);
    l.push_back(9);
    l.push_back(4);
    l.push_back(6);
    l.push_back(5);
    l.push_back(2);
    l.push_back(8);
    selectionsort(l);
    
    int arr[8];
    arr[0] = 7;
    arr[1] = 4;
    arr[2] = 9;
    arr[3] = 1;
    arr[4] = 8;
    arr[5] = 2;
    arr[6] = 3;
    arr[7] = 6;
    int size = sizeof(arr) / sizeof(int);
    selectionsort(arr, size); //have to pass in the size because sizeof will 
    //not work in a function with a passed in array
    
    cout << " - Stability Tests - " << endl;
    
    //this test shows stability because the numbers are already inputted
    //in sorted order and have duplicates. Since its already sorted, and is 
    //stable, the number of moves should be zero, because it should not be
    //sorting any of the numbers and the duplicates will keep their relative
    //positions to each other
    vector<pair<int, int>> f;
    pair<int, int> f1(-2, 3);
    pair<int, int> f2(3 ,4);
    pair<int, int> f3(3, 4);
    pair<int, int> f4(5, 1);
    f.push_back(f1);
    f.push_back(f2);
    f.push_back(f3);
    f.push_back(f4);
    selectionsort(f);
    
    //this test shows stability because though there are moves, it does not
    //swap the duplicate inputs, therefore keeping their relative positions. 
    //Thus this output should only have 3 moves if it is considered stable, 
    //which it is.
    vector<pair<int, int>> b;
    pair<int, int> b1(5, 5);
    pair<int, int> b2(2 ,1);
    pair<int, int> b3(2, 1);
    pair<int, int> b4(2, 1);
    pair<int, int> b5(-1, 2);
    b.push_back(b1);
    b.push_back(b2);
    b.push_back(b3);
    b.push_back(b4);
    b.push_back(b5);
    selectionsort(b);
    
    //this test is also stable. the 2 and 1 will swap with each other, but the 
    //fives will not swap, thus staying in their same relative positions.
    //Therefore this will only have 3 moves
    vector<int> cv;
    cv.push_back(2);
    cv.push_back(1);
    cv.push_back(5);
    cv.push_back(5);
    selectionsort(cv);
    
    //this last test is stable because although the duplicate values are 
    //swapped with other numbers, they still keep their relative positions
    //to each other because the first instance of the duplicates is always
    //going to be swapped first, thus keeping it earlier than the next instance
    //and so on
    vector<int> ccv;
    ccv.push_back(102);
    ccv.push_back(124);
    ccv.push_back(23);
    ccv.push_back(102);
    selectionsort(ccv);
    
}