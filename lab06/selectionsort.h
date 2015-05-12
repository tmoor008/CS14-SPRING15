//Name: Tia Moore
//SID: 861144845
//Date: 5/12/15
//Approach: In this lab, I implemented a selection sort algorithm using 
//iterators which works with several std containers (specifically tested are 
//list, vector, and array). My code first calls the selectionsort fuction from
//main which then calls one of the helper functions. The call to the helper
//function will determine which type of container it is being called on and 
//use the appropriate helper function. Each helper function has three main
//sections. First, a for loop using iterators will traverse the container and
//output its original, unsorted state (using either *itr or itr->first and
//itr->second depending on if a pair type is called). Next, an iterator to 
//keep track of the minimum value is declared and a counter is also declared to
//keep track of how many moves it takes to sort. Then the actual sort function
//is implemented using nested for loops. The first for loop iterates through 
//the container and sets the min iterator to the current value its on. Then the
//nested for loops iterates through the list at the next index, checking if
//any of the values are smaller. If a smaller value is found, the min is set to
//it. Then it breaks out of the for loop and goes to an if statement that 
//determines whether a swap should be made (as long as the two vals arent the
//same) and increments the counter. Then another for loop iterates through
//the now sorted container, outputting its contents Lastly, the number of moves
//made is output via the counter.

#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <array>
#include <iterator>

using namespace std;

template <typename T, typename U>
void selectionsort_(vector<pair<T, U>> &l) //vector pairs version
{
    cout << "pre: "; //before
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ") ";
        //outputs the original state of the vector of pairs
    }
    cout << endl;
    
    auto minIt = l.begin(); //declares min
    int count = 0; //sets the count

    for(auto it = l.begin(); it != l.end(); ++it)
    {
        minIt = it; //sets min to current to check against
        for(auto it2 = it + 1; it2!= l.end(); ++it2)
        {
            if (*it2 < *minIt)
            {
                minIt = it2; //if it2 is smaller, set min to it
            }
        }
        if (*it != *minIt) //only swaps if they arent the same
        {
            swap(*it, *minIt); //swaps min and current
            count += 3; //incrememnts the moves
        }
    }
    
    cout << "post: "; //after
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ") ";
        //outputs sorted values in the vector of pairs
    }
    cout << endl;
    //outputs number of moves
    cout << "0 copies and " << count << " moves" << endl << endl;
}


template <typename V>
void selectionsort_(vector<V> &l) //vector version
{
    cout << "pre: "; //before
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " "; //outputs original vector
    }
    cout << endl;
    
    auto minIt = l.begin(); //declares min
    int count = 0; //sets count

    for(auto it = l.begin(); it != l.end(); ++it) //iterates through vector
    {
        minIt = it; //sets the min to check against
        for(auto it2 = it + 1; it2!= l.end(); ++it2)
        {
            if (*it2 < *minIt)
            {
                minIt = it2; //if it2 is smaller than min, sets min to it2
            }
        }
        if (*it != *minIt) //only swaps if they arent the same
        {
            swap(*it, *minIt); //swaps min and current
            count += 3; //increments number of moves
        }
    }
    
    cout << "post: "; //after
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " "; //outputs newly sorted vector
    }
    cout << endl;
    //outputs the number of moves
    cout << "0 copies and " << count << " moves" << endl << endl;
}

template <typename G, typename H>
void selectionsort_(list<pair<G, H>> &l) //list pairs version
{
    cout << "pre: "; //before
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ") ";
        //outputs the pairs in their original state
    }
    cout << endl;
    
    auto minIt = l.begin(); //declares min
    int count = 0; //sets count to count moves

    for(auto it = l.begin(); it != l.end(); ++it) //iterates through pair list
    {
        minIt = it; //sets min to current
        for(auto it2 = it; it2!= l.end(); ++it2)
        {
            if (*it2 < *minIt) 
            {
                minIt = it2; //only sets min to it2 if it2 is smaller
            }
        }
        if (*it != *minIt) //only swaps if they are not equal
        {
            swap(*it, *minIt); //swaps current and min
            count += 3; //increments the number of moves
        }
    }
    
    cout << "post: "; //after
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ") ";
        //outputs both values in the sorted list of pairs
    }
    cout << endl;
    //outputs the number of moves
    cout << "0 copies and " << count << " moves" << endl << endl;
}

template <typename T>
void selectionsort_(list<T> &l) //list version
{
    cout << "pre: "; //before
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " "; //displays values in current state in list
    }
    cout << endl;
    
    auto minIt = l.begin(); //declares the min
    int count = 0; //sets the count to check moves

    for(auto it = l.begin(); it != l.end(); ++it) //iterates through list
    {
        minIt = it; //sets min to current
        for(auto it2 = it; it2!= l.end(); ++it2)
        {
            if (*it2 < *minIt) //only changes if it2 is smaller
            {
                minIt = it2; //sets min to the it2
            }
        }
        if (*it != *minIt) //only swaps if the values arent the same
        {
            swap(*it, *minIt); //swaps min and current
            count += 3; //increments number of moves
        }
    }
    
    cout << "post: "; //after
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " "; //outputs values in the newly sorted list
    }
    cout << endl;
    //outputs the move count
    cout << "0 copies and " << count << " moves" << endl << endl;
}

template <typename T>
void selectionsort(T l[], int size) //array version
{
    cout << "pre: "; //before
    for(auto it = l; it != l + size; ++it)
    {
        cout << *it << " "; //outputs all values in the array
    }
    cout << endl;
    
    auto minIt = l; //sets a min
    int count = 0; //sets count

    for(auto it = l; it != l + size; ++it) //iterates through list
    {
        minIt = it; //sets min to it ur at
        for(auto it2 = it; it2!= l + size; ++it2)
        {
            if (*it2 < *minIt) //checks second iterator against min
            {
                minIt = it2; //if it2 is smalled, set min to it
            }
        }
        if (*it != *minIt) //only swap if the values arent the same
        {
            swap(*it, *minIt); //swaps min and current 
            count += 3; //increments number of moves
        }
    }
    
    cout << "post: "; //after
    for(auto it = l; it != l + 8; ++it)
    {
        cout << *it << " "; //outputs newly sorted array
    }
    cout << endl;
    //outputs the move count
    cout << "0 copies and " << count << " moves" << endl << endl; 
}

template<typename L>
void selectionsort(L &l)
{
    selectionsort_(l); //calls helper function to determine which type it needs
    //to use
}

#endif