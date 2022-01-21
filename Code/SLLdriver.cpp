#include "SLL.hpp"
#include "SLL.cpp"
#include <iostream>
#include <string> 
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <vector>




//using namespace std;



int main()
{
    LL linked;
    int testData[40000];
    float insert[400];
    float search[400];
    float startTime;
    float endTime;
    float exec;
    ifstream inFile;
    inFile.open("dataSetB.csv");
    string line;
    int l = 0;
    ofstream outFileIn;
    ofstream outFileSe;
    using namespace std::chrono;
    
    for(int i = 0; i < 40000; i++)  //reads file into testData array
    while(!inFile.eof())
    {
        getline(inFile, line, ',');
        testData[l] = stoi(line);
        l++;
    }
    int iterations = 0;
    int count = 100;
    int prevCount = 0;
    while(iterations < 400)
    {
    

    std::cout << count << " iteration" << std::endl;
    auto start = high_resolution_clock::now();
    
    for(int i = prevCount; i < count; i++)        //inserting 100 elements
    {
        linked.insert(testData[i]);
    }
    
    auto end = high_resolution_clock::now();
    

    duration<double, micro> execTime = end - start;

    execTime = execTime / 100;
 
    std::cout << "Insert: " << execTime.count() << "ms" << std::endl;
    insert[iterations] = execTime.count();


    vector<int> values;
    for(int i = 0; i < count; i++)        //creating random numbers 0-99
    {
        values.push_back(i);
    }

    random_shuffle(values.begin(), values.end());
    start = high_resolution_clock::now();
    
    for(int i = prevCount; i < count; i++)      //searching 100 random elements
    {
        linked.search(values[i]);
    
    }
    end = high_resolution_clock::now();

    execTime = end - start;
    execTime = execTime / 100;
    std::cout << "Search: " << execTime.count() << "ms" << std::endl;
    search[iterations] = execTime.count();
    std::cout << std::endl;
    prevCount = count;
    count = count + 100;    
    iterations++;
    
    }
    //outFileIn.open("SLLInsertTestB.csv");     writes results to another file
    //for(int i = 0; i < 400; i++)
    //{
       // outFileIn << i << "," << insert[i] << endl;
    //}
    
   
    return 0;




}