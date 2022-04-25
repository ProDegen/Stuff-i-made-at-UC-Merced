#include "BTree.h"
#include <iostream>
using namespace std;

BTree::BTree(){
    root = NULL;
    //just creates an empty root
}
BTree::~BTree(){
    destroy_tree();
    //just uses our destroy tree function
}
Node *BTree::BTree_root(){
    return root;
    //shows root, if empty seg fault happens i believe
}
void BTree::destroy_tree(Node *leaf){
    if(leaf != NULL){
        //checks if leaf exists and then procceds to destroy its children and then itself
        destroy_tree(leaf -> left);
        destroy_tree(leaf -> right);
        delete leaf;
    }
}
void BTree::insert(int key, Node *leaf){
    //checks if key is smaller than leaf and then checks if its left leaf is empty, if it is
    //then it inserts it there
    if(key < leaf -> key_value){
        if(leaf -> left != NULL){
            insert(key, leaf -> left);
        }
    //if not then it creates a new node below it with its own left and right nodes
    else{
        leaf -> left = new Node;
        leaf -> left -> key_value = key;
        leaf -> left -> left = NULL;
        leaf -> left -> right = NULL;
        }
    }
    //repeat if its bigger instead of small
    else if(key >= leaf -> key_value){
        if(leaf -> right != NULL){
            insert(key, leaf -> right);
        }
    
    else{
        leaf -> right = new Node;
        leaf -> right -> key_value = key;
        leaf -> right -> left = NULL;
        leaf -> right -> right = NULL;
        }
    }
}
Node *BTree::search(int key, Node *leaf){
    //checks if theyre equal
    if(leaf != NULL){
        if(key == leaf -> key_value){
            return leaf;
        }
    //if not then we see if its bigger or larger and continue the search as if the node we just checked is 
    //the root
        if(key < leaf -> key_value){
            return search(key,leaf -> left);
        }
        else{
            return search(key,leaf -> right);
        }
    }

    //incase it doesnt exist in the tree then:
    else{
        return NULL;
    }
}
void BTree::insert(int key){
    //this just runs our other program unless its the root then we make the first node
    if(root != NULL){
        insert(key,root);
    }
    else{
        root = new Node;
        root -> key_value = key;
        root -> left = NULL;
        root -> right = NULL;
    }
}
Node *BTree::search(int key){
    //searches the tree from the root
    return search(key,root);
}
void BTree::destroy_tree(){
    //dletes the tree from the root
    destroy_tree(root);
}