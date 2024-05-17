#include "JumpListNode.h"

template <class T>
JumpListNode<T>::JumpListNode(): JumpListNode(NULL) {}

template <class T>
JumpListNode<T>::JumpListNode(T* x): value(x), next(NULL), jump(NULL), nextSize(0), jumpSize(0){}

template <class T>
JumpListNode<T>::~JumpListNode(){
    delete value;
}

template class JumpListNode<int>;