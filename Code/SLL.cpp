#include "SLL.hpp"
#include <iostream>
#include <string>
using namespace std;


LL::LL()
{
    head = NULL;    //sets head and tail to NULL
    tail = NULL;
}

void LL::insert(int data)
{
    Node* temp = new Node;  
    temp->key = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;        //if this is the first element
        tail = temp;
    }
    else
    {
        tail->next = temp;  //adds to the tail of the linked list
        tail = tail->next;
    }
    

}

Node* LL::search(int data)
{
    Node* temp = head;
    bool found = false;

    while(temp != NULL)     //traverses and searches for key
    {
        if(temp->key == data)   
        {
            found = true;
            return temp;
        }
        temp = temp->next;
    }
    if(found == false)  //if key is never found
    {
        return NULL;
    }
}

void LL::display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->key << ", ";
        temp = temp->next;
    }
}