/********************************************************************************
 * File  :   linkedlist.cpp                                                     *
 * Author: Mohammad Seeam                                                       *
 * Assignment 7: Hash Tables                                                    *
 * Create a fully functional doubly linked list class                           *
 * This header structure for all cpp and h files.                               *
 * This file, linkedlist.cpp includes only linkedlist.h                         *
 *******************************************************************************/

#include "linkedlist.h"

#include <string.h>
#include <stdio.h>
#include <iostream>

LinkedList::LinkedList(){
    head=NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

bool LinkedList::addNode(int id, string* info){
    bool add_Node_Success, proceed = true;
    Node *new_node=new Node;
    Data data;
    if(id>0 && *info!=""){
        new_node->prev=NULL;
        new_node->next=NULL;
        data.id=id;
        data.data=*(info);
        new_node->data=data;
    }else{
        proceed=false;
        add_Node_Success=false;
    }Node* current=head;
    while(proceed){
        if(current==NULL){
            head=new_node;
            proceed=false;
            add_Node_Success=true;
        }else if(current!=NULL && id==current->data.id){
            proceed=false;
            add_Node_Success=false;
            delete new_node;
        }else if(current!=NULL && current->prev==NULL && id<current->data.id){
            head->prev=new_node;
            new_node->next=head;
            new_node->prev=NULL;
            head=new_node;
            proceed=false;
            add_Node_Success=true;
        }else if(current!=NULL && current->prev!=NULL && id>current->prev->data.id && id<current->data.id){
            new_node->next=current;
            new_node->prev=current->prev; 
            current->prev->next=new_node;
            current->prev=new_node;
            proceed=false;
            add_Node_Success=true;
        }else if(current!=NULL && current->next==NULL && id>current->data.id){
            new_node->next=current->next=NULL; 
            new_node->prev=current;
            current->next=new_node;
            proceed=false;
            add_Node_Success=true;
        }else{
            current=current->next;
        }
    }return add_Node_Success;
}

bool LinkedList::deleteNode(int int_of_node_to_delete){
    Node* current=head;    
    bool delete_node_success,proceed = true;
    while(proceed){
        if(current==NULL){
            proceed=false;delete_node_success=false;
        }else if(current!= NULL){
            if(current->data.id==int_of_node_to_delete && current->next==NULL && current->prev==NULL){
                head=NULL;
                delete current;
                proceed=false;
                delete_node_success=true;
            }else if(current->data.id==int_of_node_to_delete && current->prev == NULL){
                current->next->prev=current->prev;
                head=current->next;               
                delete current; 
                proceed=false;
                delete_node_success=true;
            }else if(current->data.id==int_of_node_to_delete && current->prev!=NULL && current->next!=NULL){
                current->prev->next=current->next;
                current->next->prev=current->prev;
                delete current; proceed=false;
                delete_node_success=true;
            }else if(current->data.id==int_of_node_to_delete && current->next == NULL){
                current->prev->next=NULL;
                delete current; proceed=false;
                delete_node_success=true;
            }else{
                current=current->next;
            }
        }
    }  
    return delete_node_success;
}

bool LinkedList::getNode(int get_node, Data* passing_data){
    bool get_node_success,proceed=true;
    Node* current=head;
    while(proceed){
        if(current==NULL){
            passing_data->data="";
            passing_data->id=-1;
            proceed=false;
            get_node_success=false;
        }else if(current!=NULL){
            if(current->data.id==get_node){
                passing_data->id=current->data.id;
                passing_data->data=current->data.data;
                proceed=false;
                get_node_success=true;
            }else{
                current=current->next;
            }
        }
    }
    return get_node_success;
}

bool LinkedList::clearList(){
    Node* current = head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    return true;
}

bool LinkedList::exists(int id_if_exists){
    Node* current=head;
    bool exists_success=false;bool proceed=true;
    while(proceed){
        if(current==NULL){
            proceed=false;
        }else if(current!= NULL){
            if(current->data.id==id_if_exists){
                exists_success=true;
                proceed=false;
            }else{
                current=current->next;
            }
        }
    }
    return exists_success;
}

int LinkedList::getCount(){
    int count=0;
    Node *current=head;
    bool proceed=true;
    if(current!=NULL){
        while(current!=NULL){
            count++;
            current=current->next;
        }
    }
    return count;
}

void LinkedList::printList(bool backward){

    Node* current=head;
    Node* lastNonNullNode;
    while (current != NULL) {
        if(!backward){std::cout  << current->data.id << " and "<<current->data.data<<std::endl;}
        lastNonNullNode=current;
        current = current->next;
    }
    
    if(backward){
        current = lastNonNullNode;
        while (current != NULL) {
            std::cout  << current->data.id << " and "<<current->data.data<<std::endl;
            current = current->prev;
        }
    }
}

