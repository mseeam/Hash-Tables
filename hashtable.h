/********************************************************************************
 * File  :   hashtable.h                                                        *
 * Author: Mohammad Seeam                                                       *
 * Assignment 7: Hash Tables                                                    *
 * Create a fully functional hashtable class                                    *
 * This header structure for all cpp and h files.                               *
 * This file, hashtable.h includes only data.h                                  *
 *******************************************************************************/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include "data.h"
#include "linkedlist.h"

#define HASHTABLESIZE 15

class Hashtable {

public:

    Hashtable();
    ~Hashtable();
    
    bool insertEntry(int, string*); 
    string getData(int); 
    bool removeEntry(int); 
    int getCount(); 
    void printTable();
    
private:
    LinkedList** hashtab;
    int hash(int); 
    int count;

};

#endif /* HASHTABLE_HASHTABLE_H */