#include "JumpListRand.h"

template<class T>
JumpListRand<T>::JumpListRand(): head(NULL), tail(NULL), n(0){

}

template<class T>
JumpListRand<T>::~JumpListRand(){
    JumpListNode<T>* u = head;
    while (u != NULL){
        JumpListNode<T>* next = u->next;
        delete u;
        u = next;
    }
}

template<class T>
JumpListNode<T>* JumpListRand<T>::buildJumpList(JumpListNode<T>* u, int n){
    if (n == 1) return u;

    int k = randomInteger(2, n);
    JumpListNode<T>* p = buildJumpList(u->next, k-1);
    u->jump = p;
    JumpListNode<T>* q = buildJumpList(p, n-k+1);
    return q;
}

template <class T>
JumpListNode<T>* JumpListRand<T>::search(T x) const {
    JumpListNode<T>* u = head;

    while (u->next != NULL){
        if (*(u->jump->value) <= x) u = u->jump;
        else if (*(u->next->value) <= x) u = u->next;
        else return u;
    }

    return u;
}

template <class T>
void JumpListRand<T>::insert(JumpListRand<T>* l, JumpListNode<T>* x){
    JumpListNode<T>* y = search(*(x->value));
    JumpListNode<T>* curNext = y->next;
    x->next = curNext;
    y->next = x;
    n = l->size();
    setJumpOnInsert(l->head, x, n);
}

template <class T>
void JumpListRand<T>::setJumpOnInsert(JumpListNode<T>* u, JumpListNode<T>* x, int n){
    if (u == x) buildJumpList(u, n);

    bool doReset = randomInteger(1, n) == 1;

    if (doReset){
        u->jump = x;
        buildJumpList(u, n - index(x) - 1);
        buildJumpList(u->jump, n - index(x) + 1);
    } else if (u->jump <= x){
        setJumpOnInsert(u->jump, x, n - index(u->jump) + 1);
    } else {
        setJumpOnInsert(u->next, x, n - index(u->jump) - 1);
    }
}

template <class T>
void JumpListRand<T>::remove(JumpListRand<T>* l, JumpListNode<T>* x){
    JumpListNode<T>* y = search(*(x->value) - 1);
    if (y->next == x){
        y->next = x->next;
    } else return;

    JumpListNode<T>* u = l->head;
    int n = l->size();

    while (*(u->value) <= *(x->value)) {
        if (u->jump == x){
            u->jump = NULL;
            buildJumpList(u, n);
            return;
        } else if (*(u->jump->value) < *(x->value)) {
            n = n - index(u->jump);
            u = u->jump;
        } else {
            n = index(u->jump) - index(u);
            u = u->next;
        }
    }
}

template <class T>
int JumpListRand<T>::size() const {
    return n;
}

template <class T>
int JumpListRand<T>::index(JumpListNode<T>* x) const {
    JumpListNode<T>* u = head;
    int i = 0;
    while (u != x){
        x = x->next;
        ++i;
    }
    return i;
}

template<class T>
int JumpListRand<T>::randomInteger(int lower, int upper) const {
    std::srand(std::time(0));
    return std::rand() % (upper - lower + 1) + lower;
}

template class JumpListRand<int>;