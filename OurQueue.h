#ifndef OURQUEUE_H
#define OURQUEUE_H
#include "Treap.h"
#include <iostream>

class OurQueue
{
private:
    int firstEl;
    int lastEl;
    int sizeOfArray = 10;
    TreapNode* *arr;
public:
    OurQueue();
    void clear() {firstEl = lastEl = -1;}
    bool isEmpty();
    void push(TreapNode* data);

    TreapNode* pop(){
        ++firstEl;
        return arr[firstEl];
    }

    TreapNode* first(){return arr[firstEl];}
    ~OurQueue();
};

#endif // OURQUEUE_H
