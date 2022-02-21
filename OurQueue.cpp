#include "OurQueue.h"
#include "Treap.h"

OurQueue::OurQueue()
{
    firstEl = lastEl = -1;
    arr =  new TreapNode*[sizeOfArray];
}

bool OurQueue::isEmpty()
{
    if(firstEl == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void OurQueue::push(TreapNode* data) //push
{
    if(firstEl == -1)
    {
        arr[0] = data;
        firstEl++;
        lastEl++;
    }
    else if(lastEl == sizeOfArray)
    {
        TreapNode* *resized = new TreapNode*[sizeOfArray*2];
        sizeOfArray = sizeOfArray*2;
        for(int i = 0; i < sizeOfArray; i++)
        {
            resized[i] = arr[i];
        }
        delete [] arr;
        arr = resized;
        ++lastEl;
        arr[lastEl] = data;
    }
    else
    {
        ++lastEl;
        arr[lastEl] = data;
    }
}

OurQueue::~OurQueue()
{
    for(int i = 0; i < sizeOfArray;i++)
    {
        delete arr[i];
    }
    delete [] arr;
}
