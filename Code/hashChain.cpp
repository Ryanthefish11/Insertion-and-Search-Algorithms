#include "hashChain.hpp"
#include <iostream>
using namespace std;


HashTable::HashTable(int bsize)
{
    tableSize = bsize;          //sets tablesize to given amount
    table = new node*[tableSize];   //allocation
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;        
    }
}

int HashTable::hashFunc(int key)
{
    return key % tableSize;     
}

void HashTable::insert(int key)
{
    int index = hashFunc(key);  //returns the hashFunc result as the index
    node* previous = NULL;
    node* active = table[index];    
    while(active != NULL)
    {
        previous = active;      
        active = active->next;      //traversal
    }
    if(active == NULL)      //if there is an open spot in the linked list
    {
        active = new node;      
        active->key = key;  //sets the key to the new location in the linked list and sets ->next to NULL
        active->next = NULL;        
        if(previous == NULL)
        {
            table[index] = active;
        }
        else
        {
            previous->next = active;
        }
        
    }

}


node* HashTable::search(int key)
{
    bool found = false;
    int index = hashFunc(key);      //returns the hash value
    node* active = table[index];      //sets active to the location where the index is located
    while(active != NULL)
    {
        if(active->key == key)  
        {
            return active;          
            found = true;
        }
        active = active->next;      //traverses until key is found
    }
    if(found == false)
    {                       //if key is not found
        return NULL;
    }
}



void HashTable::display()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << i << ": ";
        while(table[i]!= NULL)
        {
            cout << table[i]->key << " -> ";
            table[i] = table[i]->next;
            
        }
        cout << endl;
    }
}