#ifndef JUMPLISTDET_H
#define JUMPLISTDET_H

#include "JumpListNode.h"

template<class T>
class JumpListDet {
    public:
        // Constructor
        JumpListDet();

        // Destructor
        ~JumpListDet();

        JumpListNode<T>& buildPerfectJumpList(JumpListNode<T>&, int);
        int findPredecessor(int);
        int insert(T);
        int remove(T);
    private:
        JumpListNode<T> *head;



};

#endif // JUMPLISTDET_H