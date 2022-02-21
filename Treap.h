#ifndef DS_TREAP_H
#define DS_TREAP_H
#include <iostream>
#include "LinkedList.h"
#include "User.h"
#include <iostream>


using namespace std;
class User;

struct TreapNode
{
    pair<string, int> nodePair;
    User *ptr;
    TreapNode* left;
    TreapNode* right;
};

class Treap
{
private:
    TreapNode* root;
    bool flag = false;
    int c =0;
    static int count;
    TreapNode * temp;
public:
    Treap();
    TreapNode *getRoot() const;

    void setRoot(TreapNode *root);
    TreapNode* deleteNode(string username, TreapNode *node);
    TreapNode* insertion(User *obj, TreapNode *node);
    void insertion(User *obj);
    TreapNode* searchForNode(string data);
    TreapNode* rotateLeft(TreapNode *node);
    TreapNode* rotateRight(TreapNode *node);
    bool deleteNode(string username);
    void inOrder(TreapNode *node);
    void inOrder();
    void storeBst(TreapNode  *node,string  arr[]);
    void storeBst(string *arr);

    ~Treap();
};

#endif //DS_TREAP_H
