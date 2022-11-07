/********************************************************************************
 * File  :   main.cpp                                                           *
 * Author: Mohammad Seeam                                                       *
 * Assignment 7: Hash Tables                                                    *
 * This header structure for all cpp and h files.                               *
 * This file, main.cpp includes only main.h                                     *
 *******************************************************************************/

#include "main.h"

int main() {

    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    


    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    // create Hashtable object here
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    Hashtable hash;
    
    // show it is empty by calling getCount and printTable
    std::cout << "hash.getCount() before insert: " << hash.getCount() << std::endl << std::endl;
    std::cout << "printing table: " <<  std::endl << std::endl;
    hash.printTable();  std::cout<<std::endl;

    // try and put ALL the test data into the table and show what happens
    std::cout << "inserting new data...";
    for (int i = 0; i < testdatasize; i++) {
        hash.insertEntry(ids[i], &strs[i]);
    }std::cout << "data inserted..." << std::endl;

    std::cout << std::endl << "printing table after insert: " << std::endl <<std::endl;
    
    hash.printTable();

    std::cout << std::endl << "hash.getCount() after insert: " << hash.getCount() << std::endl <<std::endl;

    int random=testdatasize/2;
    std::cout << "deleting "<<random <<" of the elements from the hashtable...";
    for (int i = 0; i < testdatasize/2; i++) {
        hash.removeEntry(ids[i]);
    }
    std::cout << random<< " elements of the hashtab deleted." << std::endl;

    std::cout << std::endl << "printing table after delete "<<random << std::endl <<std::endl;
    
    hash.printTable();

    std::cout << std::endl << "hash.getCount() after delete: " << hash.getCount() << std::endl <<std::endl;

    cout << "Using getData() to find data..." << endl;
    for (int i = 0; i < testdatasize; i++){
        if(hash.getData(ids[i])!=""){
            std::cout<<"After searching id "<<ids[i]<<", we get data :"<< hash.getData(ids[i]) << std::endl;
        }else {
            std::cout<<"After searching id "<<ids[i]<<", we get data : EMPTY"<< std::endl;
        }
    }
    
    return 0;
}
