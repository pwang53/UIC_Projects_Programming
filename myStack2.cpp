#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "StackClass.h"

operatorStack::operatorStack(){
    inUse = 0;
    size = 2;
    opArr = new char[size];
}

bool operatorStack::opIsEmpty(){
    if (inUse == 0) {
        return true;
    }
    else{
        return false;
    } 
}

void operatorStack::opPush(char input){
    // Check if the use space is more than the size, then add more size for array
    if (inUse >= size){
        char *tmp;   //create temp array has two more size
        tmp = new char[size + 2];

        for (int i = 0; i < size; i++){  //copy the value to the temp array
            tmp[i] = opArr[i];
        }

        delete [] opArr;  //clean the value array
        
        opArr = tmp;  //pass the value in the temp to the value array
        size = size + 2; //add two more size
    }

    opArr[inUse] = input; //pass the userInput to the value Array
    inUse = inUse + 1;  //add one to in Use number
}

void operatorStack::opPop(){
    if (inUse == 0){    //if the stack is empty, then return
        cout << "The stack is empty, no more value can be poped out" << endl;
        return;
    }
    else{   //if not empty, reduce the the top of inUse, which minus one
        inUse = inUse - 1;
    }
}

char operatorStack::opGetTop(){
     if (inUse == 0){    //if the stack is empty, then return -999
        cout << "Top is empty error cannt get top" << endl;
    }
    else{
        return opArr[inUse-1];   //otherwise, return the top value;
    }
}

void operatorStack::opReset(){
    delete [] opArr;
    inUse = 0;
    size = 2;
    opArr = new char[size];
}