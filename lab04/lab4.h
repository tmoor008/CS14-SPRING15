//Name: Tia Moore
//SID: 861144845
//Date: 5/1/15
//Approach:

#ifndef __LAB4_H__
#define __LAB4_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Entry;

class priority_queue 
{
    public:
        vector<Entry> entries;
        Entry& front() { return entries.back(); }
        void pop() { entries.pop_back(); }
        void push(Entry e) 
        { 
            entries.push_back(e);
            for (int i = entries.size() - 1; i != 0; --i) 
            {
              if (entries[i] <= entries[i - 1]) break;
              swap(entries[i], entries[i - 1]);
            }
        }
};

void preorder(int m, int n, int k)
{
    if (m + n > k) return;
    
    cout << m << " " << n << endl;
    preorder(2 * m - n, m, k);
    preorder(2 * m + n, m, k);
    preorder(m + 2 * n, n, k);
}

void postorder(int m, int n, int k)
{
    if (m + n > k) return;
    
    postorder(2 * m - n, m, k);
    postorder(2 * m + n, m, k);
    postorder(m + 2 * n, n, k);
    cout << m << " " << n << endl;
}

void inorder(int m, int n, int k, priority_queue &q)
{
    
}

void inorder(int m, int n, int k)
{
    priority_queue q;
    inorder(m, n, k, q);
    //iterate over q and print
}

#endif