#ifndef JUMP_LIST_NODE_H
#define JUMP_LIST_NODE_H

template<class T>
class JumpListNode {
    public:
        T *value;
        JumpListNode<T> *next;
        JumpListNode<T> *jump;
        int nextSize;
        int jumpSize;
};

#endif // JUMP_LIST_NODE_H