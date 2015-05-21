#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

chrono::milliseconds getAvg(vector<chrono::milliseconds> v)
{
    //code to get the avg 
    chrono::milliseconds avg; //chrono var to store avg
    
    for (unsigned i = 0; i < v.size(); ++i)
    {
        avg = avg + v.at(i); //takes running sum
    }
    
    avg = avg / 10; //divides sum by 10 to get the avg
    
    return avg;
}

template <typename T>
void run(T &t, vector<string> words, int n, vector<chrono::milliseconds> &i_time, vector<chrono::milliseconds> &f_time)
{
    vector<chrono::milliseconds> temp_i; //temp vectors to store each n iterations
    vector<chrono::milliseconds> temp_f; //10 vals

    //sets j to n, will use j as the n variable
    for(unsigned j = n; j <= 50000; j = j + 5000) //to incrememnt n
    {
    	for (int m = 0; m < 10; ++m) //to do each n 10 times
    	{
    		auto str = chrono::high_resolution_clock::now(); //starts clock
    		for(unsigned i = 0; i < j; i++) 
    		{
    			t.insert(words.at(i)); //inserts all the words up to j
    		}
    		auto end = chrono::high_resolution_clock::now(); //ends clock
    		
    		auto amt = chrono::duration_cast<chrono::milliseconds>(end - str);
    		//finds the time taken to complete by subtracting end - start
            temp_i.push_back(amt / j); //divides amt by j to get the time per
            //a single insert and pushes that into vector to get avg
    		
    		str = chrono::high_resolution_clock::now(); //restarts clock
    		for(unsigned k = 0; k < j; k++)
    		{
    			t.find(words.at(k)); //finds all the words up to j
    		}
    		end = chrono::high_resolution_clock::now(); //ends clock
    		
    		amt = chrono::duration_cast<chrono::milliseconds>(end - str);
    		//finds the time taken to complete by subtracting end - start
    		temp_f.push_back(amt / j); //divides the amt by j to get the time per
    		//a single find and pushes tht into a vector to get avg

    		t.clear(); //clears t to start over
    	}
    	i_time.push_back(getAvg(temp_i)); 
    	f_time.push_back(getAvg(temp_f));
    	//takes the avg of a single j iteration
    	//and pushes it into the time vectors to later take the overall avg
    	std::random_shuffle(words.begin(), words.end());
    	//shuffles the words vector to test 
    }
}

int main(int argc, char **argv)
{
    vector<string> words; //declares vector to store the words
    string s; //string to help with inputting words
    vector<chrono::milliseconds> i_time; //vectors to hold 10 avgs for each
    vector<chrono::milliseconds> f_time;
    
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
    
    cout << "Timing the Self-Balancing Tree operations..." << endl;
    set<string> set1; //tests a set (self-balancing tree)
    run(set1, words, n, i_time, f_time); //runs 
    chrono::milliseconds insertTimeT = getAvg(i_time); //gets avg, stores
    chrono::milliseconds findTimeT = getAvg(f_time); //gets avg, stores
    i_time.clear(); //clears vectors to start next operation
    f_time.clear();
    cout << "Completed." << endl;
    
    cout << "Timing the Hash Table operations... " << endl;
    unordered_set<string> set2; //tests an unordered_set (hash table)
    run(set2, words, n, i_time, f_time); //runs
    chrono::milliseconds insertTimeH = getAvg(i_time); //gets avg, stores
    chrono::milliseconds findTimeH = getAvg(f_time); //gets avg, stores
    cout << "Completed." << endl;
    
    cout << "Data being saved to outfile..." << endl;
    ofstream fout; //creates ofstream output variable
    
    fout.open(argv[3]); //opens outfile
    
    if (!fout.is_open()) //checks if the file opens correctly
    {    
        cout << "error opening: " << argv[3] << endl;
        exit(-1); //exits
    }

    //fouts the found overall avg times to the outfile 
    fout << n << " " << std::chrono::duration_cast<std::chrono::milliseconds>(insertTimeT).count() 
        << " " << std::chrono::duration_cast<std::chrono::milliseconds>(insertTimeH).count() << " "
        << std::chrono::duration_cast<std::chrono::milliseconds>(findTimeT).count() << " " 
        << std::chrono::duration_cast<std::chrono::milliseconds>(findTimeH).count() << endl;
        
    fout.close(); //closes the outfile
    cout << "Completed saving." << endl;
    //end program
}

