/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: Oct. 2022
 */
 
#include "BST.h"
#include "WordPair.h"
   
// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

   // Default constructor
   BST::BST() { 

   }            

   // Copy constructor
   BST::BST(BST & aBST) {
	  // to do
     BSTNode * root = aBST.root;
   }

   // Destructor 
   BST::~BST() {
      root = nullptr;
      elementCount = 0;
   }                
   
   
/* Getters and setters */

   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Time efficiency: O(1)   
   unsigned int BST::getElementCount() const {     

     return this->elementCount;
   }
   

/* BST Operations */

   // Description: Inserts an element into the binary search tree.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the binary search tree.
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the binary search tree.
   // Time efficiency: O(log2 n)   
   void BST::insert(WordPair & newElement) {
     
      // Binary search tree is empty, so add the new element as the root
      if (elementCount == 0) {
         root = new BSTNode(newElement);
         elementCount++;
      }
      else {
         if ( !insertR(newElement, root) ) {
           //cout << "BST:insert( )" << *newElement << " already in BST!" << endl; // For testing purposes
           throw ElementAlreadyExistsException("Element already exists in the data collection.");
         }
      }
      return;
   }

   // Description: Recursive insertion into a binary search tree.
   //              Returns true when "anElement" has been successfully inserted into the 
   //              binary search tree. Otherwise, returns false.
   bool BST::insertR(WordPair & anElement, BSTNode * current) { 
    
      if(anElement < current->element){
         if(current->left == nullptr){
            BSTNode*  temp = new BSTNode();
            current->left = temp;
            temp->element = anElement;
            return true;
         }
         else{
            insertR(anElement, current->left);
         }
      }
      else if(anElement > current->element){
         if(current->right == nullptr){
            BSTNode*  temp = new BSTNode();
            current->right = temp;
            temp->element = anElement;
            return true;
         }
         else{
            insertR(anElement, current->right);
         }
      }
      return false;
   }


   
   // Description: Retrieves "targetElement" from the binary search tree.
   //           This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
   //         thrown from the retrieveR(...)
   //         if "targetElement" is not in the binary search tree.
   // Time efficiency: O(log2 n)
   WordPair& BST::retrieve(WordPair & targetElement) const {
      
     if (elementCount == 0)  
        throw EmptyDataCollectionException("Binary search tree is empty.");
	
     WordPair& translated = retrieveR(targetElement, root);
     return translated;
   }

   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "ElementDoesNotExistException" 
   //         if "targetElement" is not found in the binary search tree.
   WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const {

   // to do
      if(targetElement == current->element){
         WordPair* aPair = new WordPair();
          aPair =  current->element;
      }
      
      else if(targetElement < current->element){
         if(current->hasLeft()){
            retrieveR(targetElement,current->left);
         }
      }

      else if(targetElement > current->element){
         if(current->hasRight()){
            retrieveR(targetElement,current->right);
         }
      }
      else{
         throw ElementDoesNotExistException("Element is not found.");
      }
      return aPair;
   } 
         
   
   // Description: Traverses the binary search tree in order.
   //           This is a wrapper method which calls the recursive traverseInOrderR( ).
   //           The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Time efficiency: O(n)     
   void BST::traverseInOrder(void visit(WordPair &)) const {
     
     if (elementCount == 0)  
       throw EmptyDataCollectionException("Binary search tree is empty.");

     traverseInOrderR(visit, root);
     
     return;
   }

   // Description: Recursive in order traversal of a binary search tree.   
   void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 

      // to do 
      if(root != nullptr){
         traverseInOrderR(visit,root->left);
         traverseInOrderR(visit,root->right);
      }
   }
