#include <iostream>
#include "JumpListRand.h"
#include "JumpListNode.h"

using namespace std;

void randomJumpListTest(){
    cout << "Testing the random Jumplist" << endl;

    JumpListRand<int>* l = new JumpListRand<int>();

    JumpListNode<int> *u = new JumpListNode<int>();

    JumpListNode<int> *v = u;

    for (int i = 1; i < 4; ++i){
        v->value = new int(i);
        v->next = new JumpListNode<int>();
        v = v->next;
    }

    for (int i = 5; i < 7; ++i){
        v->value = new int(i);
        v->next = new JumpListNode<int>();
        v = v->next;
    }

    v->value = new int(7);

    // v = u;

    // for (int i = 0; i < 7; ++i){
    //     cout << *(v->value) << endl;
    //     v = v->next;
    // }

    l->head->next = u;
    l->head->value = new int(-1);
    l->listSize = 6;

    l->buildJumpList(l->head, 7);

    // l->insert(u);
    // l->head->next = u;

    // for (int i = 1; i < 8; ++i){
    //     l->insert(new int(i));
    // }

    // for (int i = 0; i < 10; ++i){
    //     cout << l->randomInteger(2,5) << endl;
    // }
    l->print();

    l->insert(new int(4));

    l->print();

    l->insert(new int(8));

    l->print();
    
    l->insert(new int(0));

    l->print();

    delete l;

    cout << "Finished testing the random Jumplist" << endl;
}

int main() {
    randomJumpListTest();

    return 0;
}