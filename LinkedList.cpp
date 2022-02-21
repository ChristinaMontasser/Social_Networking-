#include "LinkedList.h"
#include "User.h"

LinkedList::LinkedList()
{
    head = tail = NULL;
}

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::InsertNodeAtHead(User *x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->addressOfNextNode = head;
    head = temp;
    if(tail == NULL)
    {
        tail = head;
    }
}

void LinkedList::InsertNodeAtTail(User *x)
{
    Node* temp = new Node();
    temp->data = x;
    if(tail == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->addressOfNextNode = temp;
        tail = temp;
    }
}

void LinkedList::insertNodeAtPosition(int position, User *data)
{
    int counter = 0;
    Node* temp = head;
    while(true)
    {
        if(position == 1)
        {
            InsertNodeAtHead(data);
            break;
        }
        else if(counter == position - 2)
        {
            if(temp->addressOfNextNode == NULL)
            {
                InsertNodeAtTail(data);
                break;
            }
            Node* newNode = new Node();
            newNode->data = data;
            newNode->addressOfNextNode = temp->addressOfNextNode;
            temp->addressOfNextNode = newNode;
            break;
        }
        else
        {
            temp = temp->addressOfNextNode;
            counter++;
        }
    }

}

void LinkedList::deleteFromHead() // This function will delete one element from the Linked List head
{
    if(head == tail)
    {
        head = tail = 0;
    }
    else
    {
        Node* temp = head;
        head = head->addressOfNextNode;
        temp = 0;
        delete temp; //Is this line correct?!!!!
    }
}

void LinkedList::deleteFromTail()
{
    Node *temp = head;
    if(head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        while(temp->addressOfNextNode != tail)
        {
            temp = temp->addressOfNextNode;
        }
        delete tail;
        tail = temp;
        tail->addressOfNextNode = 0;
    }

}

void LinkedList::deleteFromPosition(int position)
{
    Node *temp = head;
    int counter = 0;
    while(true)
    {
        if(position == 1)
        {
            deleteFromHead();
            break;
        }
        else if(counter == position - 2)
        {
            if(temp->addressOfNextNode == NULL)
            {
                deleteFromTail();
                break;
            }
            else
            {
                Node *reLink= temp->addressOfNextNode;
                temp->addressOfNextNode = reLink->addressOfNextNode;
                delete reLink;
                break;
            }
        }
        else
        {
            temp = temp->addressOfNextNode;
            counter++;
        }
    }
}

User* LinkedList::searchForItemInLinkedList(string username)
{
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data->getUsername() == username)
        {
            return temp->data;
        }
        else
        {
            temp = temp->addressOfNextNode;
        }
    }
    return 0;
}



LinkedList::~LinkedList()
{
    Node *temp = head;
    while(temp != NULL)
    {
        Node *next = temp->addressOfNextNode;
        delete temp;
        temp = next;
    }
    head = 0;
}

void LinkedList::setHead(Node *head) {
    LinkedList::head = head;
}
