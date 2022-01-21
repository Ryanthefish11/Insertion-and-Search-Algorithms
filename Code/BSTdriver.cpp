#include "BST.hpp"
#include "BST.cpp"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>




int main()
{
    BST tree;
    int testData[40000];
    float insert[400];
    float search[400];
    float startTime;
    float endTime;
    float exec;
    ifstream inFile;
    inFile.open("dataSetA.csv");
    string line;
    int l = 0;
    ofstream outFileIn;
    ofstream outFileSe;
using namespace std::chrono;
    
    for(int i = 0; i < 40000; i++)      //reads all 40000 elements into testData array
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
    auto start = system_clock::now();               //clock start
    
    for(int i = prevCount; i < count; i++)        //inserting 100 elements per each iteration
    {
        tree.insert(testData[i]);
    }
    
   auto end = system_clock::now();                  //clock end
    

  duration<double, micro> execTime = end - start;

  execTime = execTime / 100;                        //takes the average of the 100 elements inserted 
    std::cout << "Insert: " << execTime.count() << "ms" << std::endl;
    insert[iterations] = execTime.count();          


    vector<int> values;
    for(int i = 0; i < count; i++)        //creating random numbers 0-99
    {
        values.push_back(i);
    }

    random_shuffle(values.begin(), values.end());
    start = system_clock::now();
    
    for(int i = prevCount; i < count; i++)      //searching 100 random elements
    {
        tree.search(values[i]);
    
    }
    end = system_clock::now();

    execTime = end - start;
    execTime = execTime / 100;
    std::cout << "Search: " << execTime.count() << "ms" << std::endl;
    search[iterations] = execTime.count();
    std::cout << std::endl;
    prevCount = count;
    count = count + 100;
    iterations++;
    
    }
    //outFileIn.open("BSTInsertTestA.csv");         writes to a file the results
    //for(int i = 0; i < 400; i++)
    //{
        //outFileIn << i << "," << insert[i] << endl;
    //}
    
   
    return 0;



}