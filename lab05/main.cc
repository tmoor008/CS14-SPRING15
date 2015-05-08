//Name: Tia Moore
//SID: 861144845
//Date: 5/5/15
//Approach: 

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
	test3.vertSum(test2.root, 0, m2);
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
	test4.findSumPath(test3.root, 61, buffer3);
	cout << "Part 3" << endl;
	test4.vertSum(test2.root, 0, m3);
    
    
    
    return 0;
}