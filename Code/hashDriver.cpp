#include "hashOpen.hpp"     //change to hashChain.hpp when testing the hash chaining method
#include "hashOpen.cpp"       //as well as .cpp file
#include <iostream>
#include <string> 
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <vector>








int main()
{
    HashTable hashT(40009);
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
    ofstream outFile;
    using namespace std::chrono;

    for(int i = 0; i < 40000; i++)  //reads from file and stores into testData array
    {
        getline(inFile, line, ',');
        testData[i] = stoi(line);
        l++;
    }
    
    int iterations = 0;
    int count = 100;
    int prevCount = 0;
    while(iterations < 400)
    {
    

    std::cout << iterations << " iteration" << std::endl;
    auto start = high_resolution_clock::now();      //clock start
    
    for(int i = prevCount; i < count; i++)        //inserting 100 elements
    {
        hashT.QuadInsert(testData[i]);          //NOTE\\ When using Linear probing, use hashT.insertItem()
    }

    auto end = high_resolution_clock::now();        //clock end
    

   auto execTime = duration_cast<microseconds> (end - start);

   execTime = execTime / 100;                   //taking average time of each element inserted
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
         hashT.QuadSearch(testData[i]);         //NOTE\\ when using Linear Probing use hashT.searchItem()
     }
     end = high_resolution_clock::now();

     execTime = duration_cast<microseconds> (end - start);
     execTime = execTime / 100;
     std::cout << "Search: " << execTime.count() << "ms" << std::endl;
     search[iterations] = execTime.count();
     std::cout << std::endl;
     prevCount = count;
     count = count + 100;
     iterations++;
    
 
    }
    //hashT.display();
    //outFile.open("hashQuadraticInsertTestB.csv");     writes the results to another file
    //for(int i = 0; i < 400; i++)
    //{
        //outFile << i << "," << insert[i] << endl;
    //}

    return 0;

}


