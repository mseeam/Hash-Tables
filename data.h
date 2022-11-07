/********************************************************************************
 * File  :   data.h                                                             *
 * Author: Mohammad Seeam                                                       *
 * Assignment 7: Hash Tables                                                    *
 * contains structs                                                             *
 * This header structure for all cpp and h files.                               *
 * This file, data.h                                                            *
 *******************************************************************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node{
    Data data;
    Node* next;
    Node* prev;
};

#endif /* DATA_H */