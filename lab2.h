//Name: Tia Moore
//SID: 861144845
//Date: 4/18/15
//Approach:

#ifndef __LAB2_H__
#define __LAB2_H__

#include <iostream>
#include <sstream>
#include <forward_list>

// typedef int Type;

using namespace std;

template <typename Type>
class Node
{
    private:
        template <typename T> friend class List;
    
        Type data;
        Node<Type> *next;
        
    public:
        Node<Type>(Type data)
        : data(data), next(0) 
        {}
};

template <typename Type>
class List
{
    private:
        Node<Type> *head;
        Node<Type> *tail;
    
    public:
        List()
        {
            head = 0;
            tail = 0;
        }
        List(List &list)
        {
            head = 0;
            tail = 0;
            for (Node<Type> *curr = list.head; curr != 0; curr = curr->next)
            {
                push(curr->data);
            }
        }
        ~List()
        {
            while(head != NULL)
            {
                Node<Type> *curr = head;
                head = head->next;
                delete curr;
            }
        }
        List(const string &str)
        {
            head = 0;
            tail = 0;
            stringstream ss;
            ss << str;
            char t;
            
            while (ss >> t)
            {
                push(t);
            }
        }
        void display() const
        {
            Node<Type> *temp = head;

            if(head == 0)
            {
                cout << "";
                return;
            }
            
            cout << head->data;
            temp = temp->next;
            
            while (temp != 0)
            {
                cout << " ";
                cout << temp->data;
                temp = temp->next;
            }
        }
        void push(Type val)
        {
            if (head == 0)
            {
                head = new Node<Type>(val);
                tail = head;
            }
            
            else
            {
                Node<Type> *end = new Node<Type>(val);
                tail->next = end;
                tail = end;
            }
        }
        void elementSwap(int pos)
        {
            if (head == 0 || head->next == 0) //makes sure the list is > 1
            {
                cout << "Cannot swap on empty or size one list" << endl;
                return;
            }
            
            if (pos < 0) //makes sure negative position isnt entered
            {
                cout << "Cannot accept negative position, out of bounds" << endl;
                return;
            }
            
            int sz = 0; //size variable
            
            for (Node<Type> *curr = head; curr != 0; curr = curr->next)
            {
                ++sz; //increments to correct size
            }
            
            if (pos >= sz - 1) //amkes sure position isnt out of bounds
            {
                cout << "One of the positions is out of bounds, cancelling swap" 
                    << endl;
                return;
            }
            
            if (head->next->next == 0) //if there are only two nodes
            {
                if (pos == 1) //makes sure not out of bounds
                {
                    cout << "Position out of bounds, cancelling swap" << endl;
                    return;
                }
                Node<Type> *temp = head; //flips nodes
                head = head->next;
                head->next = temp;
                temp->next = 0;
                return;
            }
            
            if (pos == 0) //flips the first and second node
            {
                Node<Type> *temp = head; //sets head and second node
                Node<Type> *nxt = temp->next;
                
                head = nxt; //reassigns arrows
                temp->next = nxt->next;
                nxt->next = temp;
                return;
        
            }
            
            //cases for all other sized nodes and positions
            
            Node<Type> *temp = head; //saves current and previous nodes
            Node<Type> *prev = head;
            
            for (int i = 0; i < pos - 1; ++i) //finds correct position
            {
                prev = prev->next;
                temp = temp->next;
            }
            
            temp = temp->next;
            Node<Type> *nxt = temp->next; //saves next node
            
            if(nxt->next == 0) //resets tail if needed
            {
                tail = temp;
            }
            
            prev->next = nxt; //reassigns arrows
            temp->next = nxt->next;
            nxt->next = temp;
        }
};

bool isPrime(int i);
int primeCount(forward_list<int> lst, forward_list<int>::iterator &itr);
int primeCount(forward_list<int> lst);

template <typename Type>
void listCopy(forward_list<Type> L, forward_list<Type> &P)
{
    if (P.begin() == P.end())
    {
        return;
    }
    class forward_list<Type>::iterator itt; //creates an iterator to traverse list P
    forward_list<Type> K; //temp to save P's vals
    
    for(itt = P.begin(); itt != P.end(); ++itt)
    {
        K.push_front(*itt); //push front values of P into K to reverse order
    }
    
    P.resize(0); //resets P
    
    class forward_list<Type>::iterator itt2; //iterator to traverse L
    
    for(itt2 = L.begin(); itt2 != L.end(); ++itt2)
    {
        P.push_front(*itt2); //push front values of L into P to reverse order
    }
    
    class forward_list<Type>::iterator itt3; //iterator to traverse K
    
    for(itt3 = K.begin(); itt3 != K.end(); ++itt3)
    {
        P.push_front(*itt3); //push front values of K into P to un-reverse order
    }
}

template <typename Type>
void printLots(forward_list<Type> L, forward_list<int> P)
{
    int position = 0;
    
	class forward_list<Type>::iterator it1 = L.begin(); //iterators
	forward_list<int>::iterator it2 = P.begin();
	
	for (it1 = L.begin(); it1 != L.end(); it1++) // print each value in a list
	{
		if(it2 == P.end()) break;
		if(*it2 == position)
		{
			cout << *it1 << ' '; //outputs value at P in L
			it2++; //incrememnts P once found
		}
		position++; //incrememnts position in L
	}
	
	class forward_list<Type>::iterator it3;
	int count = 0;
	for (it3 = L.begin(); it3 != L.end(); ++it3) //finds size of the list
	{
	    ++count;
	}
	
	forward_list<int>::iterator it4;
	for(it4 = P.begin(); it4 != P.end(); ++it4) //checks if there are out of
	                                            //bounds errors
	{
	    if (*it4 >= count)
	    {
	        cout << "Out of bounds position found, aborting." << endl;
	        break;
	    }
	}
	
}

template <typename Type>
void print(forward_list<Type> K)
{
    class forward_list<Type>::iterator it;
    
    for(it = K.begin(); it != K.end(); ++it)
    {
        cout << *it << " ";
    }
}

#endif