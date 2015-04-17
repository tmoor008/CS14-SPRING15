//Name: Tia Moore
//SID: 861144845
//Date: 4/16/15
//Approach:

#include <iostream>
#include <sstream>
#include <forward_list>

// template <class Type, class Alloc = allocator<Type>> class forward_list;

// typedef int Type;

using namespace std;

template <typename Type>

class Node
{
    friend class List;
    
    private:
        Type data;
        Node<Type> *next;
        
    public:
        Node<Type>(Type data);
};

class List
{
    private:
        Node<Type> *head;
        Node<Type> *tail;
    
    public:
        List();
        List(List &list);
        ~List();
        List(const string &str);
        void display() const;
        void push(char val);
        void elementSwap(int pos);
};

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
    for (Node<Type> *curr = list.head; curr != 0; curr = curr->next)
    {
        push(curr->data);
    }
}

List::~List()
{
    while(head != NULL)
    {
        Node<Type> *curr = head;
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

void List::push(char val)
{
    if (head == 0)
    {
        head = new Node(val);
        tail = head;
    }
    
    else
    {
        Node<Type> *end = new Node(val);
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
    forward_list<Type>::iterator itr = lst.begin(); //starts iterator at beg
    
    int total = primeCount(lst, itr); //calls recursive helper function
    
    return total; //returns total # of primes
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
