//Name: Tia Moore
//SID: 861144845
//Date: 4/16/15
//Approach:

#include <iostream>
#include <forward_list>

// template <class Type, class Alloc = allocator<Type>> class forward_list;

// template <typename Type>

typedef int Type;

using namespace std;

// int primeCount(forward_list<int> &lst, int count, forward_list<int> &itr)
// {
//     if (itr == lst.end())
//     {
//         if (isPrime(*itr) == true) 
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
    
//     if(isPrime(*itr) == true)
    
//     return 0 + primeCount(lst, count, ++itr);
// }

// int primeCount(forward_list<int> lst)
// {
//     forward_list<int>::iterator itr = lst.begin();
//     int count = 0;
    
//     int total = primeCount(lst, 0, itr);
    
//     return total;
// }

bool isPrime(int i)
{
    if (i <= 1) //if i <= it is not prime; base case
    {
        return false;
    }
    
    else //checks each number for any divisors systematically
    {
        for (int k = 2; k < i; ++k)
        {
            if (i % k == 0) //if any numbers % == 0 then they are divisors
            {
                return false; //thus not prime
            }
        }
        
        return true; //if the for loop ends then the number must be prime
    }
}

void listCopy(forward_list<Type> L, forward_list<Type> &P)
{
    forward_list<Type>::iterator itt; //creates an iterator to traverse list
    
    P.resize(0); //makes P size 0 if it has any nodes in it
    
    for(itt = L.begin(); itt != L.end(); ++itt)
    {
        P.push_front(*itt); //push front values of L into P to reverse order
    }
}

void printLots(forward_list<Type> L, forward_list<int> P)
{
    int position = 0;
	forward_list<Type>::iterator it1 = L.begin();
	forward_list<int>::iterator it2 = P.begin();
	for(it1 = L.begin(); it1 != L.end(); it1++) // print each value in a list
	{
		if(it2 == P.end()) break;
		if(*it2 == position)
		{
			cout << *it1 << ' ';
			it2++;
		}
		position++;
	}
}

void print(forward_list<Type> K)
{
    forward_list<Type>::iterator it;
    
    for(it = K.begin(); it != K.end(); ++it)
    {
        cout << *it << " ";
    }
}
