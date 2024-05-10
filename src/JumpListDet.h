#ifndef JUMPLISTDET_H
#define JUMPLISTDET_H

class JumpListDet {
    public:
        // Constructor
        JumpListDet();

        // Destructor
        ~JumpListDet();

        void buildPerfectJumpList(int, int);
        int findPredecessor(int);
        int insert(int);
        int remove(int);
    private:



};

#endif // JUMPLISTDET_H