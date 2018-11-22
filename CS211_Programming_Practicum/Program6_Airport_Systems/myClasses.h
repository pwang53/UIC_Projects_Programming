#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <string>
using namespace std;

// node class for helping store the data into different class
class Node {
    public:
        int data;
        Node *next;
};

//The Class for Link List
class MyLinkList {
    public:

        //constructor
        MyLinkList();

        //deconstructor
        ~MyLinkList();

        //Add elements
        void pushBack(int x);

        //Delete elements
        void deleteNode(int x);

        //print the whole list of airports
        void printList();

        //delete the whole list of airports
        void deleteList();

        //Check if have the element
        bool whetherHave(int x);

        //get the head of the list
        Node* getHead();

    private:
        Node *head;

};

//The class of airport
class Airport {

    public:

        //constructor
        Airport();

        //deconstructor
        ~Airport();

        //add the edge
        void addEdge(int x);

        //delete the edge
        void deleteEdge(int x);

        //print out the number of airports
        void printAll();

        //delete all aiarports in the list
        void deleteAll();

        //mark the airport as visited
        void markVisisted();

        //mark the airport as not visited
        void markUnVisisted();

        //get the visit status
        bool getStatus();

        //see if its edge
        bool checkEdge(int x);

        //get the head
        Node *getAHead();

    private:
        bool visisted;
        MyLinkList list;

};

//MyFileList Class helper
class fileNode {
    public:
        string name;
        fileNode *next;
};

//The class to store the all file put in
class MyFileList {

    public:

        //constructor
        MyFileList();

        //deconstructor
        ~MyFileList();

        //add to list
        void addFile (string x);

        //delete elements
        void deleteFile (string x);

        //check if exist
        bool checkExist( string x);

    private:
        fileNode *head;

};
