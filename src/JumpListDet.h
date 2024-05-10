#ifndef JUMPLISTDET_H
#define JUMPLISTDET_H

template<class T>
class JumpListDet {
    public:
        // Constructor
        JumpListDet();

        // Destructor
        ~JumpListDet();

        void buildPerfectJumpList(int, int);
        int findPredecessor(int);
        int insert(T);
        int remove(T);
    private:



};

#endif // JUMPLISTDET_H