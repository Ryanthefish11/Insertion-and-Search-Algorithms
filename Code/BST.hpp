#ifndef BST_HPP
#define BST_HPP
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    
};

class BST
{
    public:
    BST();

    
    void insert(int key);
    Node* search(int key);
    void display();


    private:
    Node* root;
    void insertFunc(int key, Node* leaf);
    Node* searchFunc(int key, Node* leaf);
    void ioDisplay(Node* leaf);

};



#endif