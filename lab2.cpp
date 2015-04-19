#include <iostream>
#include <forward_list>
#include "lab2.h"

using namespace std;

Node::Node(Type data)
: data(data), next(0) 
{}

List::List()
{
    head = 0;
    tail = 0;
}

List::List(List &list)
{
    head = 0;
    tail = 0;
    for (Node *curr = list.head; curr != 0; curr = curr->next)
    {
        push(curr->data);
    }
}

List::~List()
{
    while(head != NULL)
    {
        Node *curr = head;
        head = head->next;
        delete curr;
    }
}

List::List(const string &str)
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

void List::display() const
{
    Node *temp = head;

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

void List::push(char val)
{
    if (head == 0)
    {
        head = new Node(val);
        tail = head;
    }
    
    else
    {
        Node *end = new Node(val);
        tail->next = end;
        tail = end;
    }
}

void List::elementSwap(int pos)
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
    
    for (Node *curr = head; curr != 0; curr = curr->next)
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
        Node *temp = head; //flips nodes
        head = head->next;
        head->next = temp;
        temp->next = 0;
        return;
    }
    
    if (pos == 0) //flips the first and second node
    {
        Node *temp = head; //sets head and second node
        Node *nxt = temp->next;
        
        head = nxt; //reassigns arrows
        temp->next = nxt->next;
        nxt->next = temp;
        return;

    }
    
    //cases for all other sized nodes and positions
    
    Node *temp = head; //saves current and previous nodes
    Node *prev = head;
    
    for (int i = 0; i < pos - 1; ++i) //finds correct position
    {
        prev = prev->next;
        temp = temp->next;
    }
    
    temp = temp->next;
    Node *nxt = temp->next; //saves next node
    
    if(nxt->next == 0) //resets tail if needed
    {
        tail = temp;
    }
    
    prev->next = nxt; //reassigns arrows
    temp->next = nxt->next;
    nxt->next = temp;
    
}

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

int primeCount(forward_list<int> lst, forward_list<Type>::iterator &itr)
{
    if (itr == lst.end()) //base case once the iterator reaches the end
    {
        return 0;
    }
    
    else if (isPrime(*itr) == true) //if the # is prime, add one
    {
        return 1 + primeCount(lst, ++itr);
    }
    
    else //if not add 0 and do recursive call 
    {
        return 0 + primeCount(lst, ++itr);
    }
    
    return -1; 
}

int primeCount(forward_list<int> lst)
{
    forward_list<int>::iterator itr = lst.begin(); //starts iterator at beg
    
    int total = primeCount(lst, itr); //calls recursive helper function
    
    return total; //returns total # of primes
}

void listCopy(forward_list<Type> L, forward_list<Type> &P)
{
    forward_list<Type>::iterator itt; //creates an iterator to traverse list P
    forward_list<Type> K; //temp to save P's vals
    
    for(itt = P.begin(); itt != P.end(); ++itt)
    {
        K.push_front(*itt); //push front values of P into K to reverse order
    }
    
    P.resize(0); //resets P
    
    forward_list<Type>::iterator itt2; //iterator to traverse L
    
    for(itt2 = L.begin(); itt2 != L.end(); ++itt2)
    {
        P.push_front(*itt2); //push front values of L into P to reverse order
    }
    
    forward_list<Type>::iterator itt3; //iterator to traverse K
    
    for(itt3 = K.begin(); itt3 != K.end(); ++itt3)
    {
        P.push_front(*itt3); //push front values of K into P to un-reverse order
    }
}

void printLots(forward_list<Type> L, forward_list<int> P)
{
    int position = 0;
    
	forward_list<Type>::iterator it1 = L.begin(); //iterators
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
	
	forward_list<Type>::iterator it3;
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

void print(forward_list<Type> K)
{
    forward_list<Type>::iterator it;
    
    for(it = K.begin(); it != K.end(); ++it)
    {
        cout << *it << " ";
    }
}


int main()
{
    cout << "Welcome" << endl;
    
    cout << "Test is prime: ";
    int test = 1;
    bool a = isPrime(test);
    
    if (a == true)
    {
        cout << "Prime" << endl;
    }
    
    else
    {
        cout << "Not Prime" << endl;
    }
    cout << endl;
    
    cout << "Tests listCopy: " << endl;
    cout << "Empty second list case: " << endl;
    forward_list<Type> l1;
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(7);
    l1.push_front(1);
    cout << "List 1: ";
    print(l1);
    cout << endl;
    forward_list<Type> l2;
    listCopy(l1, l2);
    cout << "List 2: ";
    print(l2);
    cout << endl << endl;
    
    cout << "Filled second list case" << endl;
    forward_list<Type> l3;
    l3.push_front(6);
    l3.push_front(2);
    l3.push_front(8);
    l3.push_front(4);
    cout << "List 1: ";
    print(l3);
    cout << endl;
    forward_list<Type> l4;
    l4.push_front(5);
    l4.push_front(7);
    l4.push_front(11);
    l4.push_front(9);
    cout << "List 2: ";
    print(l4);
    cout << endl; 
    cout << "Copied List 2: ";
    listCopy(l3, l4);
    print(l4);
    cout << endl << endl;
    
    cout << "Tests printLots: " << endl;
    forward_list<Type> l5;
    l5.push_front(15);
    l5.push_front(18);
    l5.push_front(12);
    l5.push_front(19);
    l5.push_front(11);
    cout << "List 1(Inputs): ";
    print(l5);
    cout << endl;
    forward_list<int> l6;
    l6.push_front(3);
    l6.push_front(2);
    l6.push_front(1);
    cout << "List 2 (Positions): ";
    print(l6);
    cout << endl; 
    cout << "Printlots: ";
    printLots(l5, l6);
    cout << endl << endl;
    
    cout << "Tests printLots: " << endl;
    forward_list<Type> l7;
    l7.push_front(23);
    l7.push_front(35);
    l7.push_front(67);
    l7.push_front(79);
    l7.push_front(51);
    l7.push_front(13);
    cout << "List 1(Inputs): ";
    print(l7);
    cout << endl;
    forward_list<int> l8;
    l8.push_front(9); //should go out of bounds and print nothing
    l8.push_front(5);
    l8.push_front(2);
    l8.push_front(0);
    cout << "List 2 (Positions): ";
    print(l8);
    cout << endl; 
    cout << "Printlots: ";
    printLots(l7, l8);
    cout << endl << endl;
    
    cout << "Tests element swap" << endl;
    List test3;
    test3.push(5); 
    test3.push(6); 
    test3.push(8);
    test3.push(2);
    test3.push(9);
    cout << "List Before: ";
    test3.display();
    cout << endl;
    test3.elementSwap(0);
    cout << "List After: ";
    test3.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap sz 1" << endl;
    List test4;
    test4.push(5); 
    cout << "List Before: ";
    test4.display();
    cout << endl;
    test4.elementSwap(2);
    cout << "List After: ";
    test4.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap sz 2, pos 0" << endl;
    List test5;
    test5.push(57); 
    test5.push(12);
    cout << "List Before: ";
    test5.display();
    cout << endl;
    test5.elementSwap(0);
    cout << "List After: ";
    test5.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap sz 2, pos 1" << endl;
    List test6;
    test6.push(35); 
    test6.push(68);
    cout << "List Before: ";
    test6.display();
    cout << endl;
    test6.elementSwap(1);
    cout << "List After: ";
    test6.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests element swap end" << endl;
    List test7;
    test7.push(22); 
    test7.push(7);
    test7.push(35);
    test7.push(88);
    test7.push(62);
    cout << "List Before: ";
    test7.display();
    cout << endl;
    test7.elementSwap(3);
    cout << "List After: ";
    test7.display();
    cout << endl << "End" << endl << endl;
    
    cout << "Tests primeCount function" << endl;
    forward_list<Type> l9;
    l9.push_front(23);
    l9.push_front(15);
    l9.push_front(8);
    l9.push_front(56);
    cout << "List: ";
    print(l9);
    cout << endl;
    cout << "Number of primes: " << primeCount(l9) << endl;
    cout << endl;
    
    cout << "Tests primeCount function" << endl;
    forward_list<Type> l10;
    l10.push_front(35);
    l10.push_front(13);
    l10.push_front(29);
    l10.push_front(37);
    cout << "List: ";
    print(l10);
    cout << endl;
    cout << "Number of primes: " << primeCount(l10) << endl;
    cout << endl;
    
}