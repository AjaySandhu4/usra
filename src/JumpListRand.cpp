#include "JumpListRand.h"

template<class T>
JumpListRand<T>::JumpListRand(): head(new JumpListNode<T>()), listSize(0) {}

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
    // cout << "Building u="<<*(u->value)<<", n="<<n<<endl;
    if (n == 1) return u;

    int k = randomInteger(2, n);
    JumpListNode<T>* p = buildJumpList(u->next, k-1);
    u->jump = p;
    u->nextSize = k - 2;
    // u->jumpSize = n - k + 1;
    JumpListNode<T>* q = buildJumpList(p, n-k+1);
    return q;
}

template <class T>
JumpListNode<T>* JumpListRand<T>::search(T* x) const {
    JumpListNode<T>* u = head;

    while (u->next != NULL){
        if (u->jump != NULL && *(u->jump->value) <= *x) u = u->jump;
        else if (*(u->next->value) <= *x) u = u->next;
        else return u;
    }

    return u;
}

template <class T>
void JumpListRand<T>::insert(T* x){
    insert(new JumpListNode<T>(x));
}

template <class T>
void JumpListRand<T>::insert(JumpListNode<T>* x){
    JumpListNode<T>* u = search(x->value);

    if (u != head && *(u->value) == *(x->value)) return;

    x->next = u->next;
    u->next = x;
    ++listSize;
    setJumpOnInsert(head, x, listSize+1);
}

template <class T>
void JumpListRand<T>::setJumpOnInsert(JumpListNode<T>* u, JumpListNode<T>* x, int n){
    // cout << "Setting Jump on u="<<*(u->value)<<", x="<<*(x->value)<<", n="<<n<<endl;
    if (u == x) {
        buildJumpList(u, n);
        return;
    }

    bool doReset = randomInteger(2, n) == 2;

    if (doReset){
        int i = index(u, x);
        u->jump = x;
        u->nextSize = i - 1;
        buildJumpList(u->next, i);
        buildJumpList(u->jump, n - i);
    } else if (u->jump != NULL && *(u->jump->value) <= *(x->value)){
        setJumpOnInsert(u->jump, x, n - index(u, u->jump));
    } else {
        ++(u->nextSize);
        setJumpOnInsert(u->next, x, u->nextSize);
    }
}

template <class T>
JumpListNode<T>* JumpListRand<T>::insertSearch(T* x) {
    JumpListNode<T>* u = head;

    while (u->next != NULL){
        if (u->jump != NULL && *(u->jump->value) <= *x) {
            ++(u->jumpSize);
            u = u->jump;
        }
        else if (*(u->next->value) <= *x) {
            ++(u->nextSize);
            u = u->next;
        }
        else return u;
    }

    return u;
}

template <class T>
void JumpListRand<T>::remove(JumpListRand<T>* l, JumpListNode<T>* x){
    JumpListNode<T>* y = pred(x);
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
    --listSize;
}

template <class T>
JumpListNode<T>* JumpListRand<T>::pred(JumpListNode<T>* x) const{
    JumpListNode<T>* u = head;

    while (u->next != NULL){
        if (*(u->jump->value) < *(x->value)) u = u->jump;
        else if (*(u->next->value) < *(x->value)) u = u->next;
        else return u;
    }

    return u;
}

// template <class T>
// ostream& operator<<(ostream& output, const JumpListRand<T>& list) {
//     output << "hello this is a jumplist" << endl;
//     return output;
// }

template <class T>
void JumpListRand<T>::print() const {
    JumpListNode<T>* u = head;
    cout << "[";
    string prefix = "";
    while (u != NULL) {
        cout << prefix;
        cout << "(";
        if (u != head) cout << *(u->value);
        cout << " -> ";
        if (u->jump != NULL) cout << *(u->jump->value);
        else cout << "nil";
        cout << "{" << u->nextSize <<","<<u->jumpSize << "}"; 
        cout << ")";
        prefix = ", ";
        u = u->next;
    }
    cout << "]" << endl;
}

template <class T>
int JumpListRand<T>::size() const {
    // int n = 0;
    // JumpListNode<T>* u = head->next;
    // while (u != NULL){
    //     ++n;
    //     u = u->next;
    // }
    // return n;
    // return head->nextSize + head->jumpSize + 1;
    return listSize;
}

template <class T>
int JumpListRand<T>::index(JumpListNode<T>* x) const {
    return index(head, x);
}

template <class T>
int JumpListRand<T>::index(JumpListNode<T>* u, JumpListNode<T>* x) const {
    int i = 0;
    while (u != NULL && u != x){
        u = u->next;
        ++i;
    }
    return i;
}

template<class T>
int JumpListRand<T>::randomInteger(int lower, int upper) const {
    srand(time(0));
    return rand() % (upper - lower + 1) + lower;
}

template class JumpListRand<int>;
// ostream& operator<<(ostream&, const JumpListRand<int>&);