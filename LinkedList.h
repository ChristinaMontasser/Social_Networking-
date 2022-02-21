
#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H



#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;
class User;

struct Node
{
    User *data;
    Node *addressOfNextNode;
};

class LinkedList
{
private:
    Node*head, *tail;
public:
    LinkedList();
    Node* getHead();

    void setHead(Node *head);

    void InsertNodeAtHead(User *x);
    void InsertNodeAtTail(User *x);
    void insertNodeAtPosition(int position, User *data);
    void deleteFromHead();
    void deleteFromTail();
    void deleteFromPosition(int position);
    User* searchForItemInLinkedList(string username);
    ~LinkedList();
};



#endif //DS_LINKEDLIST_H
