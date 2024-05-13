#include "JumpListDet.h"

template<class T>
JumpListDet<T>::JumpListDet() {
    // Constructor
    head = new JumpListNode<T>();
    head.value = NULL;
    head.next = NULL;
    head.jump = NULL;
    head->nextSize = 0;
    head->jumpSize = 0;
}

template<class T>
JumpListDet<T>::~JumpListDet() {
    // Destructor
    JumpListNode<T>* x = head;
    while(x != NULL){
        JumpListNode<T>* y = x->next;
        delete x;
        x = y;
    }
}

template<class T>
JumpListNode<T>& JumpListDet<T>::buildPerfectJumpList(JumpListNode<T>& x, int n) {
    JumpListNode<T>* y = NULL;
    while(n > 1){
        int m = floor(n/2);
        n = n - m - 1;
        x.nextSize = m;
        x.jumpSize = n;
        y = x.next;
        if(m == 0) x.jump = y;
        else x.jump = buildPerfectJumpList(y, m);
        x = x.jump;
    }
}

template<class T>
int JumpListDet<T>::findPredecessor(int x) {
    // Find the predecessor of x in the jump list
    return 0;
}

template<class T>
int JumpListDet<T>::insert(T x) {
    // Insert x into the jump list
    return 0;
}

template<class T>
int JumpListDet<T>::remove(T x) {
    // Remove x from the jump list
    return 0;
}

