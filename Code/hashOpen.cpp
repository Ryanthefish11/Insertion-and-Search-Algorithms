#include "hashOpen.hpp"
#include <iostream>
#include <math.h>
using namespace std;


HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    table = new node*[tableSize];   //allocation
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
        

    }
}


unsigned int HashTable::hashFunction(int key)
{
    return key % tableSize;
}

void HashTable::insertItem(int key)     //Linear Probing Insertion Function
{
    int count = 0;
    bool repeat = false;
    int index = hashFunction(key);      //returns the hash value to the index
    if(table[index] == nullptr)         //if it is an empty bucket
    {
        table[index] = new node;        
        table[index]->key = key;        //sets the key and the index value to this specific bucket
        table[index]->value = index;
        
       
    }
    else
    {
    
        while(table[index] != NULL)        //linear probing
        {


            if(count == 0)
            {
                numOfCollision++;           //adds to collision counter
            }
             index = (index + 1) % tableSize;   //adds one to the index before mod tablesize
            if(index > tableSize)
            {
                index = 0;                  //if it goes over the tablesize, bring the index back to one
            }
           count++;
            
        }

        table[index] = new node();
        table[index]->key = key;
        table[index]->value = index;
    
        
    }
}


void HashTable::QuadInsert(int key)     //Quadratic Probing Insertion Function
{
    int count = 0;
    bool repeat = false;
    //temp->key = key;
    int index = hashFunction(key);      //returns hash key
    if(table[index] == nullptr)         //if bucket is empty, insert key and index value into that bucket
    {
        table[index] = new node;
        table[index]->key = key;
        table[index]->value = index;
    }

    else
    {
        while(table[index] != NULL) 
        {
            if(count == 0)
            {
                numOfCollision++;
            }
            count++;
            int quad = pow(count, 2);       // for quadratic probing, you must square the iteration number, before adding to the index and taking mod tablesize
            index = (index + quad) % tableSize;        
            if(index > tableSize)
            {
                index = 0;              //if index reaches end of table size, make index = 0
            }
           
        }
        table[index] = new node();
        table[index]->key = key;
        table[index]->value = index;

    }
    
}

node* HashTable::QuadSearch(int key)    //Quadratic Probing Search Function
{   
    int index = hashFunction(key);      //returns hash key as index
    bool found = false;
    int count = 0;
    while(found == false)
    {
        if(table[index]->key == key)    //if key is found at index
        {
            found = true;
            return table[index];
            
        }
        count++;
        int quad = pow(count, 2);   //using quadratic probing until key is found
        index = (index + quad) % tableSize;
        if(index > tableSize)
        {
            index = 0;              //resets index to 0 if it reaches table size
        }
    }
    if(found == true)
    {
        cout << "Does not exist." << endl;      //if key is never found
    }

}

node* HashTable::searchItem(int key)    //Linear Probing Search Function
{
    int index = hashFunction(key);      //returns hash key
    bool found = false;
    while(table[index] != nullptr)      //while the table is not an empty bucket
    {
        if(table[index]->key == key)    //if key is found
        {
            return table[index];
            found = true;
        }
        
        index = (index + 1) % tableSize;    //use linear probing until key is found
    }
    if(found == false)
    {
        cout << "Does not exist." << endl;  //if key is never found
    }

}

void HashTable::getNumOfCollision()
{
    
    cout << numOfCollision;
}

void HashTable::display()
{
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i] != nullptr)
        {
            cout << table[i]->key << endl;
        }
    }
}