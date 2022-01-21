#include "BST.hpp"
#include <iostream>
using namespace std;


BST::BST()
{
    root = NULL;
}

void BST::insertFunc(int key, Node* leaf)
{
    if(leaf->key > key)     //if the input key is less than the leaf's key
    {
        if(leaf->left != NULL)
        {
            insertFunc(key, leaf->left);    // check the left leaf and repeat process
        }
        else
        {
            leaf->left = new Node;      //if this leaf is empty, set values to it
            leaf->left->key = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
        
    }
    else if(leaf->key <= key)       //if input key is greater than or equal to the leaf's key
    {
        if(leaf->right != NULL)         //if the right leaf is already taken, call the function on the right leaf
        {   
            insertFunc(key, leaf->right);
        }
        else
        {
            leaf->right = new Node;     //if the right leaf is null add values to it
            leaf->right->key = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
        
    }
}

void BST::insert(int key)
{
    if(root != NULL)    //if there are already elements in the BST
    {
        insertFunc(key, root);
    }
    else        //if this is the first element added to the BST
    {
        root = new Node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
    }
    
}


Node* BST::search(int key)
{
    return searchFunc(key, root);       //recursive call 
}

Node* BST::searchFunc(int key, Node* leaf)
{
    if(leaf != NULL)
    {
        if(key == leaf->key)        //if key has been found
        {
            return leaf;
        }
        if(leaf->key > key)
        {
            return searchFunc(key, leaf->left); //if key is less than the current leaf's key, call function again on the left leaf
        }
        else
        {
            return searchFunc(key, leaf->right);    //if the key is greater than the current leafs key, call function on the right leaf
        }
        
    }
    else
    {
        return NULL;            //key was not found
    }
    

}



void BST::display()
{
    ioDisplay(root);
}

void BST::ioDisplay(Node* leaf)
{
    if(leaf != NULL)
    {
        ioDisplay(leaf->left);
        cout << leaf->key << ", ";
        ioDisplay(leaf->right);
    }
}