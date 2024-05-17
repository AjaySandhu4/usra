#ifndef JUMP_LIST_NODE_H
#define JUMP_LIST_NODE_H

#include <cstdlib>

template<class T>
class JumpListNode {
    public:
        JumpListNode();
        JumpListNode(T*);
        ~JumpListNode();

        T *value;
        JumpListNode<T> *next;
        JumpListNode<T> *jump;
        int nextSize;
        int jumpSize;
};

#endif // JUMP_LIST_NODE_H