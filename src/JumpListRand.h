#ifndef JUMPLISTRAND_H
#define JUMPLISTRAND_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "JumpListNode.h"

using namespace std;

template<class T>
class JumpListRand {
    // friend ostream& operator<<(ostream&, const JumpListRand<T>&);
    public:
        JumpListRand();
        ~JumpListRand();

        JumpListNode<T>* buildJumpList(JumpListNode<T>*, int);
        JumpListNode<T>* search(T*) const;
        void insert(T*);
        void insert(JumpListNode<T>*);
        void setJumpOnInsert(JumpListNode<T>*, JumpListNode<T>*, int);
        void remove(JumpListRand<T>*, JumpListNode<T>*);

        int size() const;
        void print() const;

    private:
        JumpListNode<T> *head;

        int index(JumpListNode<T>*) const;
        int index(JumpListNode<T>*, JumpListNode<T>*) const;
        int randomInteger(int, int) const;
        
        JumpListNode<T>* pred(JumpListNode<T>*) const;
};

#endif // JUMPLISTRAND_H