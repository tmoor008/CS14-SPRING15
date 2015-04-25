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
//using n = 1 as its base case and several calls to its helper functions which 
//change the source, auxiliary and destination stacks accordingly. 

#ifndef __LAB3_H__
#define __LAB3_H__

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

template <typename T>
class TwoStackFixed
{
    private:
        T *arr;
        int top1;
        int top2;
        int sz;
        int mxtop;
        
        bool isFullStack1()
        {
            if (top1 == mxtop + 1 || top1 == -1)
            {
                return true;
            }
            return false;
        }
        
        bool isFullStack2()
        {
            if (top2 == mxtop || top2 == -1)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1()
        {
            if (top1 == 0 || top1 == -1)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2()
        {
            if (top2 == sz - 1|| top2 == -1)
            {
                return true;
            }
            return false;
        }
        
    public:
        TwoStackFixed(int size, int maxtop)
        {
            //constructs the array
            if (maxtop >= size) //allocates array to stack1
            {
                top1 = 0;
                top2 = -1;
                mxtop = size - 1;
            }
            
            else if (maxtop < 0) //allocates array to stack2
            {
                top1 = -1;
                top2 = size - 1;
                mxtop = 0;
            }
            
            else //regular stack case
            {
                mxtop = maxtop;
                top1 = 0;
                top2 = size - 1;
            }
            
            sz = size; //initializes size 
            arr = new T[size]; //creates array for stacks
        }
        
        void pushStack1(T value)
        {
            if (isFullStack1()) //checks if the stack is already full
            {
                cout << "Stack full, unable to push new values." << endl;
                return;
            }
            arr[top1] = value; //stores value
            top1++; //increments top1
            display(); //displays newly pushed list
        }
        
        void pushStack2(T value)
        {
            if (isFullStack2()) //checks if the stack is already full
            {
                cout << "Stack full, unable to push new values." << endl;
                return;
            }
            
            arr[top2] = value; //stores value
            top2--; //decrements top2
            display(); //displays newly pushed list
        }
        
        T popStack1()
        {
            if (isEmptyStack1())
            {
                cout << "Cannot pop on empty list." << endl;
                exit(-1);
            }
            
            top1--;
            
            return arr[top1];
        }
        
        T popStack2()
        {
            if (isEmptyStack2())
            {
                cout << "Cannot pop on empty list." << endl;
                exit(-1);
            }
            top2++;
            
            return arr[top2];
        }
    
        void display()
        {
            int i;
            for (i = 0; i < top1; ++i)
            {
                cout << arr[i];
            }
            int k;
            for (k = i; k <= top2; ++k)
            {
                cout << " _ ";
            }
            
            for (int j = k; j < sz; ++j)
            {
                cout << arr[j];
            }
            cout << endl;
        }
};

template <typename T>
class TwoStackOptimal
{
    private: 
        T *arr;
        int top1;
        int top2;
        int sz;
        
        bool isFullStack1()
        {
            if (top1 == top2 + 1)
            {
                return true;
            }
            else if (top1 == sz)
            {
                return true;
            }
            return false;
        }
        
        bool isFullStack2()
        {
            if (top1 == top2 + 1)
            {
                return true;
            }
            else if (top2 == -1)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1()
        {
            if (top1 == 0)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2()
        {
            if (top2 == sz - 1)
            {
                return true;
            }
            return false;
        }
        
    public:
        TwoStackOptimal(int size)
        {
            if (size <= 0)
            {
                cout << "Invalid Size" << endl;
                exit(-1);
            }
            
            top1 = 0;
            top2 = size - 1;
            sz = size;
            arr = new T[size];
        }
        
        
        void pushFlexStack1(T value)
        {
            if (isFullStack1()) //checks if the stack is already full
            {
                cout << "Stack full, unable to push new values." << endl;
                return;
            }
            arr[top1] = value; //stores value
            top1++; //increments top1
            display(); //displays newly pushed list
        }
        
        void pushFlexStack2(T value)
        {
            if (isFullStack2()) //checks if the stack is already full
            {
                cout << "Stack full, unable to push new values." << endl;
                return;
            }
            
            arr[top2] = value; //stores value
            top2--; //decrements top2
            display(); //displays newly pushed list
        }
        
        T popFlexStack1()
        {
            if (isEmptyStack1())
            {
                cout << "Cannot pop on empty list." << endl;
                exit(-1);
            }
            
            top1--;
            
            return arr[top1];
        }
        
        T popFlexStack2()
        {
            if (isEmptyStack2())
            {
                cout << "Cannot pop on empty list." << endl;
                exit(-1);
            }
            top2++;
            
            return arr[top2];
        }
        
        void display()
        {
            int i;
            for (i = 0; i < top1; ++i)
            {
                cout << arr[i] << " ";
            }
            int k;
            for (k = i; k <= top2; ++k)
            {
                cout << " _ ";
            }
            
            for (int j = k; j < sz; ++j)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
        
};

template <typename T>
void print(stack<T> temp)
{
    if(temp.size() == 0)
    {
        return;
    }
    else
    {
        cout << temp.top() << " ";
        temp.pop();
        print(temp);
    }
}

void showTowerStates(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Moved " << n << " from Peg " << from << " to Peg " << to << endl;
        return;
    }
    
    else
    {
        showTowerStates(n - 1, from, aux, to);
        cout << "Moved " << n << " from Peg " << from << " to Peg " << to << endl;
        showTowerStates(n - 1, aux, to, from);
    }
}

template <typename T>
void showTowerStates(int n, int count, stack<T>& A, stack<T>& B, stack<T>& C)
{
    if (n == 1)
    {
        C.push(A.top());
        A.pop();
    }
    else
    {
        showTowerStates(n - 1, count, A, C, B);
        C.push(A.top());
        A.pop();
        showTowerStates(n - 1, count, B, A, C);
    }
    ++count;
}

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    showTowerStates(n, 'A', 'C', 'B');
    showTowerStates(n, 0, A, B, C);
}

#endif