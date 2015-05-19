#include <iostream>
#include <string>
#include <fstream>
#include "lab7.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<string> words; //declares vector to store the words
    string s; //string to help with inputting words
    double ftime = 0;
    
    int n = atoi(argv[2]); //gets the given number to start with

    ifstream fin; //fstream to get inputs
    
    fin.open(argv[1]); //opens file
    
    if (!fin.is_open()) //checks if open
    {
        cout << "error opening: " << argv[1] << endl;
        exit(-1); //ends program
    }
    
    while (fin >> s) //pushes words into the vector using stream
    {
        words.push_back(s);
    }
    fin.close(); //closes file
    
    //tests a set (self-balancing tree)
    set<string> set1;
    
    cout << " - Self-Balancing Tree - " << endl;
    double total = 0;
    double total2 = 0;
    for (int i = 0; i < 10; ++i) //makes sure to get 10 runs
    {
        total += run(set1, words, n, ftime);
        total2 += ftime;
        ftime = 0;
        set1.clear();
        std::random_shuffle(words.begin(), words.end());
    }
    
    double avg = total / 10;
    double avgf = total2 / 10;
    double insertTimeT= avg / CLOCKS_PER_SEC;
    double findTimeT = avgf / CLOCKS_PER_SEC;
    cout << "Avg Insert: " << insertTimeT << endl;
    cout << "Avg Find: " << findTimeT << endl;
    cout << endl;
    
    
    cout << " - Hash Table - " << endl;
    unordered_set<string> set2;
    
    double total1 = 0;
    double total3 = 0;
    double ftime1 = 0;
    for (int i = 0; i < 10; ++i)
    {
        total1 += run(set2, words, n, ftime1);
        total3 += ftime1;
        ftime1 = 0;
        set2.clear();
        std::random_shuffle(words.begin(), words.end());
    }
    
    double avg1 = total1 / 10;
    double avgf1 = total3 / 10;
    double insertTimeH = avg1 /  CLOCKS_PER_SEC;
    double findTimeH = avgf1 / CLOCKS_PER_SEC;
    cout << "Avg Insert: " << insertTimeH << endl;
    cout << "Avg Find: " << findTimeH << endl;
    cout << endl;
    
    cout << "Data being saved to outfile..." << endl;
    ofstream fout;
    
    fout.open(argv[3]);
    
    if (!fout.is_open()) 
    {    
        cout << "error opening: " << argv[3] << endl;
        exit(-1); //exits
    }

    fout << n << " " << insertTimeT << " " << insertTimeH << " "
        << findTimeT << " " << findTimeH << endl;
        
    fout.close();
    cout << "Completed saving." << endl;

    
}