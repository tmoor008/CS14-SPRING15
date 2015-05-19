#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

template <typename T>
double run(T &t, vector<string> v, int n, double &ftime)
{
    double itime = 0;
    for (int j = n; j < 50000; j = j + 5000)
    {
        double start = clock();
        for(int i = 0; i < j; ++i)
        {
            t.insert(v.at(i));
        }
        itime += clock() - start;
        
        start = clock();
        for (int k = 0; k < j; ++k)
        {
            t.find(v.at(k));
        }
        ftime += clock() - start;
        
        t.clear();
    }
    
    return itime;
}