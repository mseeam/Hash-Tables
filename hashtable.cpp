/********************************************************************************
 * File  :   hashtable.cpp                                                      *
 * Author: Mohammad Seeam                                                       *
 * Assignment 7: Hash Tables                                                    *
 * Fully functional hashtable methods                                           *
 * This header structure for all cpp and h files.                               *
 * This file, hashtable.cpp includes only hashtable.h                           *
 *******************************************************************************/

#include "hashtable.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

/************************************
* Constructor / Destructor          *
************************************/

Hashtable::Hashtable(){
    hashtab = new LinkedList*[HASHTABLESIZE];
    count=0;
}

Hashtable::~Hashtable(){
    for(int i = 0; i<HASHTABLESIZE; i++){
        if(hashtab[i]!=NULL){
            delete hashtab[i]; //deletes auto calls ~LinkedList destructor
        }
    }

    delete[] hashtab;
    hashtab=nullptr;
    count=0;
}

/************************************
* Private                           *
************************************/

int Hashtable::hash(int id){
    return id%HASHTABLESIZE;
}

/************************************
* Public                            *
************************************/

bool Hashtable::insertEntry(int id, string* data){
    bool success = false;
    if(id<0){
        success= false;
    }else{
        int arrayIndex = hash(id);
        if(hashtab[arrayIndex]==NULL){
            //create new linked list and put there
            LinkedList* list = new LinkedList;
            hashtab[arrayIndex] = list;
        }     
        if(hashtab[arrayIndex]->addNode(id, data)){
            success=true;
            count++;    
        }
    }
    return success;
}

string Hashtable::getData(int id){
    string answer="";
    if(id<0){
        answer="";
    }else{
        int arrayIndex = hash(id);
        Data tmpData;
        bool res;
        if(hashtab[arrayIndex]==NULL){
            res=false;
        }else{
            hashtab[arrayIndex]->getNode(id, &tmpData);
            res=true;
        }
        if(res){
            answer=tmpData.data;
        }
    }
    return answer;
}

bool Hashtable::removeEntry(int id){
    bool success=false;
    int arrayIndex = hash(id);
    if(hashtab[arrayIndex]!=NULL){
        success = hashtab[arrayIndex]->deleteNode(id);
        if(hashtab[arrayIndex]->getCount()==0){
            delete hashtab[arrayIndex];
            hashtab[arrayIndex]=NULL;
        }
    }count--;
    return success;
}      

int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    for(int i = 0; i<HASHTABLESIZE; i++){
        if(hashtab[i]==NULL){
            std::cout << "ENTRY " << i << ": EMPTY" << std::endl;
        }
        else if(hashtab[i]!=NULL){
            std::cout << "ENTRY " << i << ": " ;
            hashtab[i]->printList();
        }
    }
}
