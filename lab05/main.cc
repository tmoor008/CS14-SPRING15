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

#include <iostream>
#include <map>
#include "lab5.h"

using namespace std;

int main()
{
	//given test case
	cout << "Testcase 1" << endl;
    BST<int> test1;
    map<int, int> m;
    int buffer[100];
	test1.insert(50);
	test1.insert(20);
	test1.insert(10);
	test1.insert(40);
	test1.insert(35);
	test1.insert(45);
	test1.insert(60);
	test1.insert(70);
	cout << "Part 1" << endl;
	test1.minCover();
	cout << "Part 2" << endl;
	test1.findSumPath(test1.root, 80, buffer);
	cout << "Part 3" << endl;
	test1.vertSum(test1.root, 0, m);
	cout << endl;
	
	//own test case which should find a path
	cout << "Testcase 2" << endl;
    BST<int> test2;
    map<int, int> m1;
    int buffer1[100];
	test2.insert(15);
	test2.insert(10);
	test2.insert(13);
	test2.insert(12);
	test2.insert(14);
	test2.insert(5);
	test2.insert(7);
	test2.insert(2);
	test2.insert(1);
	test2.insert(20);
	test2.insert(17);
	test2.insert(25);
	test2.insert(23);
	cout << "Part 1" << endl;
	test2.minCover();
	cout << "Part 2" << endl;
	test2.findSumPath(test2.root, 33, buffer1);
	cout << "Part 3" << endl;
	test2.vertSum(test2.root, 0, m1);
	cout << endl;
	
	cout << "Testcase 3" << endl;
    BST<int> test3;
    map<int, int> m2;
    int buffer2[100];
	test3.insert(10);
	test3.insert(7);
	test3.insert(5);
	test3.insert(12);
	cout << "Part 1" << endl;
	test3.minCover();
	cout << "Part 2" << endl;
	test3.findSumPath(test3.root, 22, buffer2);
	cout << "Part 3" << endl;
	test3.vertSum(test3.root, 0, m2);
	cout << endl;
	
	//testcase that shouldnt find a path
	cout << "Testcase 4" << endl;
    BST<int> test4;
    map<int, int> m3;
    int buffer3[100];
	test4.insert(16);
	test4.insert(26);
	test4.insert(1);
	test4.insert(8);
	test4.insert(35);
	test4.insert(2);
	test4.insert(4);
	test4.insert(22);
	cout << "Part 1" << endl;
	test4.minCover();
	cout << "Part 2" << endl;
	test4.findSumPath(test4.root, 61, buffer3);
	cout << "Part 3" << endl;
	test4.vertSum(test4.root, 0, m3);
	cout << endl;
	
	cout << "Testcase 5" << endl;
    BST<int> test5;
    map<int, int> m4;
    int buffer4[100];
	test5.insert(12);
	test5.insert(10);
	test5.insert(3);
	test5.insert(13);
	cout << "Part 1" << endl;
	test5.minCover();
	cout << "Part 2" << endl;
	test5.findSumPath(test5.root, 25, buffer4);
	cout << "Part 3" << endl;
	test5.vertSum(test5.root, 0, m4);
    cout << endl;
    
    cout << "Testcase 6" << endl;
    BST<int> test6;
    map<int, int> m5;
    int buffer5[100];
	test6.insert(8);
	test6.insert(5);
	test6.insert(4);
	test6.insert(2);
	test6.insert(6);
	test6.insert(11);
	cout << "Part 1" << endl;
	test6.minCover();
	cout << "Part 2" << endl;
	test6.findSumPath(test6.root, 19, buffer5);
	cout << "Part 3" << endl;
	test6.vertSum(test6.root, 0, m5);
    
    
    return 0;
}