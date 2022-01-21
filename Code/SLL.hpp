#ifndef SLL_HPP
#define SLL_HPP
#include <iostream>
#include <string>
using namespace std;


struct Node
{
    int key;
    Node* next;
};

class LL
{
    private:
    Node* head;
    Node* tail;

    public:
    LL();
    void insert(int data);
    Node* search(int data);
    void display();

};


#endif