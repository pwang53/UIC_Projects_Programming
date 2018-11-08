#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;


class valueStack {
    
    private:
        int inUse;
        int size;
        int *vArr;

    public:
        valueStack();  //Initialize the value array


        bool valIsEmpty();  //check whether the top is empty

        void valPush(int input);  //put the user input on the top of stack

        void valPop();  //pop out

        int valGetTop();  //get the number of top

        void reset();
};

class operatorStack {

    private:
        int inUse;
        int size;
        char *opArr;

    public:
        operatorStack();  //Initialize the operator array

        bool opIsEmpty();  //check whether the top is empty

        void opPush(char input);  //put the user input on the top of stack

        void opPop();  //pop out

        char opGetTop(); //get the top operator

        void opReset();  //reset the operator
};
