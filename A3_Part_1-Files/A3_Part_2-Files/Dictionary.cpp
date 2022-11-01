/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: AL + SD
 * Date of last modification: Oct. 2022
 */

 #include "Dictionary.h"

// constructor

Dictionary::Dictionary(){
    keyValuePairs = new BST();
}

//Destructor

Dictionary::~Dictionary(){
    delete keyValuePairs;
}

unsigned int Dictionary:: getElementCount()const{
    return this->elementCount;
}

void Dictionary::put(WordPair & newElement){
    if(elementCount == 0){
        keyValuePairs = new BST();
        elementCount++;
    }
    else{
        keyValuePairs->insert(newElement);
    }
    return;
}

WordPair & Dictionary::get(WordPair & targetElement) const{
    if(elementCount == 0){
        throw EmptyDataCollectionException("Binary search tree is empty");
    }
    WordPair& translated = keyValuePairs->retrieve(targetElement);
    return translated;
}

void Dictionary::displayContent(void visit(WordPair & ))const{
    if(elementCount == 0){
        throw EmptyDataCollectionException("Binary search tree is empty");
    }
    keyValuePairs->traverseInOrder(visit);

    return;
}