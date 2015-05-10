//Name: Tia Moore
//SID: 861144845
//Date: 5/8/15
//Approach: In this lab, I implemented serveral functions for a BST. One 
//function was the findMinCover which checks the values within the tree that
//must be selected in order to cover all the edges. I used two helper functions,
//one which selected the necessary parents of leaf nodes and another which 
//checked for any remaining nodes which needed to be selected to cover all 
//edges. Both used recursive calls to traverse the tree and if statements as 
//checkers. I then used a display helper function to display the minCover nodes.
//I also implemented a recursive findSumPaths function which finds the paths
//that add up to a given sum. The code uses several checkers, recursive calls
//and a print function to implement. Lastly, I created a vertSum function which
//found the sum of all the vertical-wise nodes. The code recursively calls 
//itself and finds the index at which each node is at. Each nodes value is
//then added into a map at the index position. Finally, the sums are output.


#ifndef __LAB5_H__
#define __LAB5_H__

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template <typename Value>
class BST 
{
	class Node 
	{ // binary tree node
		private:
		
			int height(Node *n) 
			{
				//helper function to find height
				if (n == 0) return -1; //base case if null
				
				int l = height(n->left); //adds up largest left height
				int r = height(n->right); //adds up alrgest right height
				
				return 1 + max(l, r); //compares for larger value and returns
			}
			
			int size(Node *n) 
			{
				//helper function to find overall size
				if (n == 0)  return 0; //base case
				else
				{
					return size(n->left) + size(n->right) + 1; 
					//recusrive calls add each node as it iterates and adds
				}
			}
	
		public:
			Value value;
			Node* left;
			Node* right;
			bool selected;
			
			Node(const Value v = Value())
			: value(v), left(nil), right(nil), selected(false)
			{}
			
			Value& content() { return value; }
			
			bool isInternal() { return left != nil && right != nil; }
			
			bool isExternal() { return left != nil || right != nil; }
			
			bool isLeaf() { return left == nil && right == nil; }
			
			int height() 
			{
				// returns the height of the subtree rooted at this node
				return height(this); //calls helper function
			}
			
			int size() 
			{
				// returns the size of the subtree rooted at this node
				return size(this); //calls size helper function
			}
		}; // Node
	
	    
	private:
		// const Node* nil; // later nil will point to a sentinel node.
		int count;
// 		Node* root;
	
		bool search (Value x, Node *n) //helper function for search
		{
			if (!n) return false; //if the number is not found (leaf reached)
			
			else if (n->value == x) //if the number is found
			{
				return true;
			} 
			
			else if (n->value > x) //if x is smaller
			{
				return search(x, n->left); //recursively call on the left
			}
			
			else //if x is larger
			{
				return search(x, n->right); //recursively call on the right
			}
			
		}
		
		void preorder(Node *n)const 
		{
			//helper function to traverse tree in preorder
			if (n == 0) return;
			
			cout << n->value << " "; //output at beginning
			preorder(n->left); //recursively calls left
			preorder(n->right); //recursively calls right
		}
		
		void postorder(Node *n)const 
		{
			//helper function to traverse tree in postorder
			if (n == 0) return;
			
			postorder(n->left); //recursively calls left side
			postorder(n->right); //recursively calls right side
			cout << n->value << " "; //output at end
		}
		
		void inorder(Node *n)const 
		{
			//helper function to traverse tree in inorder
			if (n == 0) return;
			
			inorder(n->left); //recursively calls left side
			cout << n->value << " "; //output
			inorder(n->right); //recursively calls right side
		}
		
		int size(Node *n) 
		{
			//helper function to find overall size
			if (n == 0)  return 0; //base case
			else
			{
				return size(n->left) + size(n->right) + 1; 
				//recusrive calls add each node as it iterates and adds
			}
		}
	
	public:
	    Node* root;
		int size() 
		{
			// size of the overall tree.
			return size(root); //calls helper function
		}
		
		bool empty() { return size() == 0; }
		
		void print_node(const Node* n) 
		{
			// Print the node’s value.
			cout << n->value << endl;
		}
	
		bool search (Value x) 
		{
			// search for a Value in the BST and return true if it was found.
			if (root->value == x) //if the search value is the same as root
			{
				return true;
			}
			
			else //otherwise call helper funtion to search
			{
				return search(x, root);
			}
			
		}
		
		void preorder()const 
		{
			// Traverse and print the tree one Value per line in preorder.
			preorder(root); //calls helper function
			cout << endl;
		}
		
		void postorder()const 
		{
			// Traverse and print the tree one Value per line in postorder.
			postorder(root); //calls helper function
			cout << endl;
		}
		
		void inorder()const 
		{
			// Traverse and print the tree one Value per line in inorder.
			inorder(root); //calls helper function
			cout << endl;
		}
		
		Value& find(Value x, Node *n) //helper function for search
		{
			if (!n) return root->value; //if the number is not found 
									    //(leaf reached)
			
			else if (n->value == x) //if the number is found
			{
				return n->value;
			} 
			
			else if (n->value > x) //if x is smaller
			{
				return find(x, n->left); //recursively call on the left
			}
			
			else //if x is larger
			{
				return find(x, n->right); //recursively call on the right
			}
			
		}
		
		void sort(Node *n, vector<int> &v) 
		{
			if (n == 0) return;
			
			sort(n->left, v); //calls sort and pushes into vector
			v.push_back(n->value);
			sort(n->right, v);
		}
		
		Value& operator[](int n) 
		{
			// returns reference to the value field of the n-th Node.
			if (n > this->size())
			{
				cout << "Out of bounds, returning root value." << endl;
				return root->value;
			}
			vector<int> v;
			sort(root, v);
			Value temp =  v.at(n - 1);
			return find(temp, root);
			
		}
		
		BST() : count(0), root(nil) {}
		
		void insert(Value X) { root = insert( X, root ); }
		
		Node* insert(Value X, Node* T) 
		{
		// The normal binary-tree insertion procedure ...
			if (T == nil) 
			{
				T = new Node(X); // the only place that T gets updated.
			} 
			
			else if (X < T->value) 
			{
				T->left = insert(X, T->left);
			} 
			
			else if (X > T->value) 
			{
				T->right = insert(X, T->right);
			} 
			
			else 
			{
				T->value = X;
			}
		// later, rebalancing code will be installed here
		return T;
	    }
		
    	void remove(Value X) { root = remove( X, root ); }
    	
    		Node* remove(Value X, Node*& T) 
    		{
    		// The normal binary-tree removal procedure ...
    		// Weiss’s code is faster but way more intricate.
    			if (T != nil) {
    				if (X > T->value) 
    				{
    					T->right = remove(X, T->right);
    				} 
    				
    				else if (X < T->value) 
    				{
    					T->left = remove(X, T->left);
    				} 
    				
    				else 
    				{ // X == T->value
    					if (T->right != nil) 
    					{
    						Node* x = T->right;
    						while (x->left != nil) x = x->left;
    						T->value = x->value; // successor’s value
    						T->right = remove(T->value, T->right);
    					} 
    					
    					else if (T->left != nil) 
    					{
    						Node* x = T->left;
    						while (x->right != nil) x = x->right;
    						T->value = x->value; // predecessor’s value
    						T->left = remove(T->value, T->left);
    					} 
    					
    					else 
    					{ // *T is external
    						delete T;
    						T = nil; // the only updating of T
    					}
    				}
    			}
    		// later, rebalancing code will be installed here
    		return T;
    		}
    	
    	void displayCoverMin_(Node *n, int &count)
    	{
    		if (n == 0) return; //base case
			
			displayCoverMin_(n->left, count); //left recursive call
			if (n->selected) //if selected is true
			{
				cout << n->value << " "; //output the value
				++count; //increment the count
			}
			displayCoverMin_(n->right, count); //right recursive call
    	}
    	
    	
    	void displayCoverMin() //displays the covers
    	{
    		int count = 0; //counter 
    	    displayCoverMin_(root, count); //helper function to output and
    	    //find the count
    	    cout << endl << count;
    	}
		
		void minCover_L(Node *n) //gets all leaf parents selected
		{
			if (!n) return; //base case
			
			if (n->left == NULL && n->right == NULL)
			{
				return; //checks if both are null and if so returns
			}
			
			else if (n->left == NULL || n->right == NULL) 
			//checks if either null
			{
				if (n->left == NULL) //if the left is null, check right leaf
				{
					if (n->right->isLeaf()) n->selected = true;
					//if its a leaf, make the parent node selected
				}
				
				if (n->right == NULL) //if the right is null, check left leaf
				{
					if (n->left->isLeaf()) n->selected = true;
					//if its a lead, make the parent node selected
				}
			}
			
			else if (n->right->isLeaf() || n->left->isLeaf())
			{
				n->selected = true; //if either are a leaf node, select parent
			}
			
			minCover_L(n->left); //recursively calls left
			minCover_L(n->right); //recursively calls right
		}
		
		void minCover_P(Node *n) //parent node checker
		{
			if (!n) return; //base case
			
			if (n->left == NULL && n->right == NULL)
			{
				return; //checks if both are null, and if so returns
			}
			
			if (n->left == NULL || n->right == NULL)
			{
				return; //checks if either side is null, and if so returns
			}
			
			if (n->right->selected == false || n->left->selected == false)
			{
				n->selected = true; //if either of the children are not selected
				//then the parent node is selected 
			}
			
			minCover_P(n->left); //recursive call on the left
			minCover_P(n->right); //recursive call on the left
			
		}
		
    	void minCover()
    	{
    		//checks if the first two children are null
    		if (root->left == NULL && root->right == NULL) return;
			//checks if the left child is null, then sets right to selected
    		if (root->left == NULL)
    		{
    			root->right->selected = true;
    		}
    		//checks if right child is null, then sets left to selected
    		else if (root->right == NULL)
    		{
    			root->left->selected = true;
    		}
    		else
    		{
    			root->left->selected = true;
    			root->right->selected = true;
    		}
    	    minCover_L(root); //selects all the leaf nodes parents
    	    minCover_P(root); //gets the remaining parents that need selection
    	    displayCoverMin(); //displays the selected nodes in cover
    	    cout << endl;
    	}
    	
    	void print(int buffer[], int count)
    	{
    		vector<int> v;//creates vector to store and sort vals
    		
	        for(unsigned i = 0; i < count; ++i) //puts values into a vector
	        {
	            v.push_back(buffer[i]);
	        }
	        
	        std::sort(v.begin(), v.end()); //sorts the values
	        
	        for(unsigned i = 0; i < v.size(); ++i)
	        {
	            cout << v.at(i) << ' '; //outputs the values
	        }
	        cout << endl;
    	}
    	
    	void findSumPath(Node* n, int sum, int buffer[], int count, int &checker)
		{
			if(!n) return; //base case
			
			buffer[count] = n->value; // adds node to the buffer
			
			if(sum - n->value == 0 && n->isLeaf()) // 
			{
			    count = count + 1; // updates coutner
			    buffer[count] = n->value; //last node placed in buffer
			    print(buffer, count); //calls the print function
			    ++checker; //increments to see if path is found
			    count = 0; //resets the count
			}
			
			//checks if a leaf is reached and the sum was not found
			if(((sum - n->value) < 0 || (sum - n->value) > 0) && n->isLeaf())
			{
			    count = 0;
			}
			
			// recursive calls on the left and right
			findSumPath(n->left, sum - n->value, buffer, count + 1, checker);
			findSumPath(n->right, sum - n->value, buffer, count + 1, checker);
		}
    	
		void findSumPath(Node* n, int sum, int buffer[])
		{
			int checker = 0;
			findSumPath(n, sum, buffer, 0, checker);
			// cout << "Checker: " << checker << endl;
			if (checker == 0)
			{
				cout << "0" << endl;
			}
		}
    	
    	void vertSum_(Node *node, int hd, std::map<int, int> &m)
    	{
    	    if (node == NULL) return; //returns if null
			else
			{
			    m[hd] += node->value; //adds the value to whats at the index
			    vertSum_(node->left, hd - 1, m); //left call, decrements hd
			    vertSum_(node->right, hd + 1, m); //right call, increments hd
			}
    	}
    	
    	void vertSum(Node *node, int hd, std::map<int, int> &m)
    	{
    	    vertSum_(node, hd, m); //calls helper function
			for (auto itr = m.begin(); itr != m.end(); ++itr)
			{
				cout << itr->second << " "; //displays the contents of each 
				//index to give the vertical sum
			}
			cout << endl; 
		
    	}
    	
}; // BST


#endif