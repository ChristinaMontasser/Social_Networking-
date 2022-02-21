#include "Treap.h"
#include "User.h"
#include "OurQueue.h"
int Treap::count = 0;
Treap::Treap()
{
    root = nullptr;
}

TreapNode* Treap::insertion(User *obj, TreapNode *node)
{
    if(node == nullptr)
    {
        TreapNode *temp = new TreapNode();
        temp->ptr = obj;
        temp->nodePair.first = obj->getUsername();
        temp->nodePair.second = rand()  % 1000;
        temp->left = temp->right = nullptr;
        return temp;
    }
    if(node->nodePair.first.compare(obj->getUsername()) == -1)
    {
        node->right = insertion(obj,node->right);
        if(node->right->nodePair.second < node->nodePair.second && node->right != nullptr)
        {
            node = rotateLeft(node);
        }
    }
    else
    {
        node->left= insertion(obj,node->left);
        if(node->left->nodePair.second < node->nodePair.second && node->left != nullptr)
        {
            node = rotateRight(node);
        }
    }
    return node;
}

void Treap::insertion(User *obj)
{
    root = insertion(obj, root);
}

TreapNode* Treap::searchForNode(string data)
{
    TreapNode* temp = root;
    while(temp != 0)
    {
        if(temp->nodePair.first.compare(data) == 0)
        {
            return temp;
        }
        else if(temp->nodePair.first.compare(data) == -1)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}

TreapNode* Treap::rotateLeft(TreapNode *node)
{
    TreapNode *temp = node;
    node = temp->right;
    temp->right = node->left;
    node->left = temp;
    return node;
}
TreapNode* Treap::rotateRight(TreapNode *node)
{
    TreapNode *temp = node;
    node = temp->left;
    temp->left = node->right;
    node->right = temp;
    return node;
}

void Treap::inOrder(TreapNode *node)
{
    if (node == nullptr) return;
    inOrder(node->left);
    cout<<node->nodePair.first<<",";
    cout<<node->ptr->getName()<<endl;
    inOrder(node->right);
}
void Treap::inOrder()
{
    inOrder(root);
    cout<<endl;
}

void Treap::storeBst(TreapNode  *node, string *arr)
{
    if(node == nullptr)
        return;

    storeBst(node->left,arr);


    arr[c]=node->nodePair.first;
    c++;
    storeBst(node->right,arr);
}
void Treap::storeBst(string *arr)
{
    storeBst(root,arr);
    c = 0 ;
}


TreapNode *Treap::getRoot() const
{
    return root;
}

void Treap::setRoot(TreapNode *root)
{
    Treap::root = root;
}

TreapNode *Treap::deleteNode(string username, TreapNode *node)
{
    if(searchForNode(username) == 0)
    {
        return 0;
    }


    if(node == nullptr)
    {
        return node;
    }

    if(username.compare(node->nodePair.first) == 1)
    {
        node->right = deleteNode(username, node->right);
    }
    else if(username.compare(node->nodePair.first) == -1)
    {
        node->left = deleteNode(username, node->left);
    }
    else if(node->left == nullptr || node->right == nullptr)
    {
        TreapNode* temp = (node->left == nullptr ? node->right : node->left);
        delete(node);
        node = temp;
    }
    else
    {
        if(node->left->nodePair.second > node->right->nodePair.second)
        {
            node = rotateRight(node);
            node->right = deleteNode(username, node->right);
        }
        else
        {
            node = rotateLeft(node);
            node->left = deleteNode(username, node->left);
        }
    }
    return node;
}

bool Treap::deleteNode(string username)
{
    root = deleteNode(username, root);
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

Treap::~Treap()
{
    if(root == NULL)
    {
        return;
    }
    TreapNode *temp = root;
    OurQueue obj;
    obj.push(temp);
    while(!obj.isEmpty())
    {
        TreapNode* currentNode = obj.first();
        if(currentNode->left != NULL)
        {
            obj.push(currentNode->left);
        }
        if(currentNode->right != NULL)
        {
            obj.push(currentNode->right);
        }
        delete currentNode;
        obj.pop();
    }
}




