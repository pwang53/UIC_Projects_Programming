#include "myClasses.h"

//constructor
MyFileList::MyFileList() {
    head = NULL;
}

//destructr
MyFileList::~MyFileList() {
    if (head == NULL) {
        return;
    }

    fileNode *temp1 = head;
    fileNode *temp2;

    while (temp1 != NULL) {
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }

    head = NULL;
}

//add to list
void MyFileList::addFile(string x) {
    fileNode *temp1 = new fileNode;
    temp1->name = x;
    temp1->next = NULL;

    if(head == NULL) {
        head = temp1;
        return;
    }

    fileNode *temp2 = head;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

//delete elements
void MyFileList::deleteFile(string x) {
    if (head == NULL) {
        cout << "Not connected, Can't be Deleted" << endl;
        return;
    }

    if (head->name.compare(x) == 0) {
        fileNode *temp1 = head;
        head = temp1->next;
        delete temp1;
        return;
    }

    // declare temp and a lagger
    fileNode *temp2 = head;
    fileNode *pnext;

    while (temp2 != NULL && temp2->name.compare(x) != 0) {
        pnext = temp2;
        temp2 = temp2->next;
    }

    // check if found if not then delete
    if (temp2 == NULL) {
        cout << "Not connected, Can't be Deleted" << endl;
        return;
    }
    else {
        pnext->next = temp2->next;
        delete temp2;
    }
}

//check if exist
bool MyFileList::checkExist(string x) {
    if (head == NULL) {
        return false;
    }

    fileNode *temp = head;
    while (temp != NULL) {
        if (temp->name.compare(x) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;  
}
