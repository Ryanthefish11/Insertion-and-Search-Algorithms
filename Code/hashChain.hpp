#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP
#include <iostream>
#include <list>
using namespace std;



struct node
{
    int key;
    node* next;

};

class HashTable
{
    private:
    node** table;
    int tableSize;
    public:
    HashTable(int bsize);
    int hashFunc(int key);
    void insert(int key);
    node* search(int key);
    void display();

};


#endif