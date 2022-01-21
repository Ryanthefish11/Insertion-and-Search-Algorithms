#ifndef HASHOPEN_HPP
#define HASHOPEN_HPP
#include <iostream>
using namespace std;


class node
{
    public:
    int key;
    int value;

};


class HashTable
{
    private:
    int tableSize;
    node** table;
    int numOfCollision;

    public:
    
    HashTable(int bsize);
    void insertItem(int key);       //linear insertion
    node* searchItem(int key);      //linear search
    unsigned int hashFunction(int key);
    void getNumOfCollision();
    void display();
    void QuadInsert(int key);       //quadratic insertion
    node* QuadSearch(int key);      //quadratic search

};





#endif