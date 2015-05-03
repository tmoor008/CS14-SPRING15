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

#ifndef __LAB4_H__
#define __LAB4_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Entry;

class priority_queue //class to hold values for in-order sorting
{
    public:
        vector<Entry> entries;
        Entry& front() { return entries.back(); } //returns the end values
        void pop() { entries.pop_back(); } //pop function 
        void push(Entry e) 
        { 
            entries.push_back(e);
            for (int i = entries.size()-1; i != 0; --i) //iterates through vec
            {
                if (entries[i].first + entries[i].second >= entries[i-1].first
                    + entries[i-1].second) break; 
                    //checks if the sum of the entry is greater than the sum
                    //of the previous entry, and if so breaks out 
                swap(entries[i], entries[i-1]); //otherwise it swaps to adjust
            }
        }
        bool empty() //helper function to determine if the vector is empty
        {
            if (entries.empty()) return true;
            else 
            {
                return false;
            }
        }
        void print() //prints out the values for in-order
        {
            for (unsigned i = 0; i < entries.size(); ++i) //iterates
            {
                cout << entries[i].first << " " << entries[i].second << endl;
                //outputs the first and second values
            }
        }
};

void preorder(int m, int n, int k)
{
    if (m + n >= k) return; //base case to make sure sum is less than K
    
    cout << m << " " << n << endl; //output at beginning for preorder
    preorder(2 * m - n, m, k); //recursive calls that give the various
    preorder(2 * m + n, m, k); //tree values
    preorder(m + 2 * n, n, k);
}

void postorder(int m, int n, int k)
{
    if (m + n >= k) return; //base case to make sure sum is less than K
    
    postorder(2 * m - n, m, k); //recursive calls that give the various
    postorder(2 * m + n, m, k); //tree values
    postorder(m + 2 * n, n, k);
    cout << m << " " << n << endl; //output at end for postorder
}

void inorder(int m, int n, int k, priority_queue &q)
{
    if (m + n >= k) return; //base case to make sure sum is less than K

    Entry T(m, n); //creates an Entry variable to hold m and n
    q.push(T); //pushes the new Entry into the queue to sort
    inorder(2 * m - n, m, k, q); //recursive calls that give the various
    inorder(2 * m + n, m, k, q); //tree values
    inorder(m + 2 * n, n, k, q);
}

#endif