/********************************************************************************
 * File  :   linkedlist.h                                                       *
 * Author: Mohammad Seeam                                                       *
 * Assignment 7: Hash Tables                                                    *
 * Create a fully functional doubly linked list class                           *
 * This header structure for all cpp and h files.                               *
 * This file, linkedlist.h includes only data.h                                 *
 *******************************************************************************/

#include "data.h"

class LinkedList {

public:

    LinkedList();    //constractor
    ~LinkedList();   //destractor

    //Declaring all the function
    bool addNode(int, string*);
    bool deleteNode(int); 
    bool getNode(int, Data*);
    bool clearList();
    bool exists(int); 
    int getCount();
    void printList(bool=false);

private:

    Node* head;

};

