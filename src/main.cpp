#include <iostream>
#include "JumpListRand.h"

using namespace std;

void randomJumpListTest(){
    cout << "Testing the random Jumplist" << endl;

    JumpListRand<int>* l = new JumpListRand<int>();

    for (int i = 1; i < 8; ++i){
        l->insert(new int(i));
    }
    l->print();
    delete l;

    cout << "Finished testing the random Jumplist" << endl;
}

int main() {
    randomJumpListTest();

    return 0;
}