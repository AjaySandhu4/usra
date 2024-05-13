#ifndef JUMPLISTRAND_H
#define JUMPLISTRAND_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "JumpListNode.h"

template<class T>
class JumpListRand {
    public:
        JumpListRand();
        ~JumpListRand();

        JumpListNode<T>* buildJumpList(JumpListNode<T>*, int);
        JumpListNode<T>* search(T) const;
        void insert(JumpListRand<T>*, JumpListNode<T>*);
        void setJumpOnInsert(JumpListNode<T>*, JumpListNode<T>*, int);
        void remove(JumpListRand<T>*, JumpListNode<T>*);

        int size() const;

    private:
        JumpListNode<T> *head;
        JumpListNode<T> *tail;
        int n;

        int index(JumpListNode<T>*) const;
        int randomInteger(int, int) const;
};

#endif // JUMPLISTRAND_H