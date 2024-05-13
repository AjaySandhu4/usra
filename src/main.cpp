#include <iostream>
#include "JumpListRand.h"

using namespace std;

void randomJumpListTest(){
    cout << "Testing the random Jumplist" << endl;

    JumpListRand<int>* l = new JumpListRand<int>();

    cout << "Finished testing the random Jumplist" << endl;

    delete l;
}

int main() {
    cout << "Hello, world! Here is a change I am testing out" << endl;

    randomJumpListTest();

    return 0;
}