#include "myClasses.h"

//The MyLinkList Class Functions
//constructor
MyLinkList::MyLinkList() {
    head = NULL;
}

//deconstructor
MyLinkList::~MyLinkList() {
    if (head == NULL) {
        return;
    }

    Node *temp1 = head;
    Node *temp2;

    while (temp1 != NULL) {
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }

    head = NULL;
}

//Add elements
void MyLinkList::pushBack (int x) {
    Node *temp1 = new Node;
    temp1->data = x;
    temp1->next = NULL;

    if(head == NULL) {
        head = temp1;
        return;
    }

    Node *temp2 = head;
    while (temp2->next != NULL) {
        temp2= temp2->next;
    }

    temp2->next = temp1;
}

//Delete elements
void MyLinkList::deleteNode(int x) {
    if (head == NULL) {
        cout << "Not connected, Can't be Deleted" << endl;
        return;
    }

    Node *temp1 = head;

    if (temp1->data == x) {
        head = temp1->next;
        delete temp1;
        return;
    }

    Node *temp2 = head;
    Node *pnext;

    while (temp2 != NULL && temp2->data != x) {
        pnext = temp2;
        temp2 = temp2->next;
    }

    if (temp2 == NULL) {
        cout << "Not connected, Can't be Deleted" << endl;
        return;
    }
    else {
        pnext->next = temp2->next;
        delete temp2;
    }
}

//print the whole list of airports
void MyLinkList::printList() {
    if (head == NULL) {
        cout << "NO available airports" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//delete the whole list of airports
void MyLinkList::deleteList() {
    if (head == NULL) {
        return;
    }

    Node *temp1 = head;
    Node *temp2;

    while (temp1 != NULL) {
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }

    head = NULL;
}

//Check if have the element
bool MyLinkList::whetherHave(int x) {
    if (head == NULL) {
        return false;
    }

    Node *temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

//get the head of the list
Node *MyLinkList::getHead() {
    if (head == NULL) {
        return NULL;
    }

    return head;
}

//The Airport Class Functions
// constructor
Airport::Airport() {
    visisted = false;
}

//deconstructor
Airport::~Airport() {
    list.deleteList();
}

//add the edge
void Airport::addEdge (int x) {
    list.pushBack( x);
}

//delete the edge
void Airport::deleteEdge(int x) {
    list.deleteNode( x);
}

//print out all the number of airports
void Airport::printAll() {
    list.printList();
}

// delete all aiarports in the list
void Airport::deleteAll() {
    list.deleteList();
}

//mark the airport as visited
void Airport::markVisisted() {
    this->visisted = true;
}

//mark the airport as not visited
void Airport::markUnVisisted() {
    this->visisted = false;
}

//// get the visit status
bool Airport::getStatus() {
    return this->visisted;
}

//check if the edge in or not
bool Airport::checkEdge ( int x) {
    return list.whetherHave(x);
}

//Get the head
Node *Airport::getAHead() {
    return list.getHead();
}
