#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "StackClass.h"

valueStack::valueStack(){
    inUse = 0;   //no in Use
    size = 2;    //original size is two
    vArr = new int[size];  //allocate the value array
}


bool valueStack::valIsEmpty(){
    if (inUse == 0) {
        return true;
    }
    else{
        return false;
    } 
}

void valueStack::valPush(int input){
    // Check if the use space is more than the size, then add more size for array
    if (inUse >= size){
        int *tmp;   //create temp array has two more size
        tmp = new int[size + 2];

        for (int i = 0; i < size; i++){  //copy the value to the temp array
            tmp[i] = vArr[i];
        }

        delete [] vArr;  //clean the value array
        
        vArr = tmp;  //pass the value in the temp to the value array
        size = size + 2; //add two more size
    }

    vArr[inUse] = input; //pass the userInput to the value Array
    inUse = inUse + 1;  //add one to in Use number
}

void valueStack::valPop(){
    if (inUse == 0){    //if the stack is empty, then return
        cout << "The stack is empty, no more value can be poped out" << endl;
        return;
    }
    else{   //if not empty, reduce the the top of inUse, which minus one
        inUse = inUse - 1;
    }
}

int valueStack::valGetTop(){
    if (inUse == 0){    //if the stack is empty, then return -999
        return -999;
    }
    else{
        return vArr[inUse-1];   //otherwise, return the top value;
    }
}

void valueStack::reset(){
    delete [] vArr;
    inUse = 0;
    size = 2;
    vArr = new int[size];
}

