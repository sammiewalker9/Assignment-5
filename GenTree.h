#include <iostream>
#include <fstream>
using namespace std;

template <class T> class TreeNode{
public:

  int key;
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;


TreeNode(){
  left = NULL;
  right = NULL;
}

TreeNode(int k, T d){
  left = NULL;
  right = NULL;
  key = k;
  data = d;
}

virtual ~TreeNode(){
  left = NULL;
  right = NULL;
}

};

// CLASS BST
template <class T> class BST{
private:
  TreeNode<T> *root;

public:
  int size;
 BST(){
  root == NULL; // empty tree
}

virtual ~BST(){
}

void recPrint(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  recPrint(node->left);
  cout << node->data << endl;
  recPrint(node->right);
}

void printTree(){
  recPrint(root);
}

TreeNode<T>* getMax(){
  TreeNode<T> *current = root;

  if(root == NULL){
    return NULL;
  }

  while(current->right != NULL){
    current = current->right; // keep going down the right side of the tree to find highest element
  }
  return current; // return &(current->key) same thing, just gives you the address

}

TreeNode<T>* getMin(){
  TreeNode<T> *current = root;

  if(root == NULL){
    return NULL;
  }

  while(current->left != NULL){
    current = current->left; // keep going down the right side of the tree to find highest element
  }
  return current; // return &(current->key) same thing, just gives you the address

}

void insert(int key, T data){

  TreeNode<T> *newNode = new TreeNode<T>(key, data);

  if (root == NULL){ //empty tree
    root = newNode;
  }
  else //not empty
  {
    TreeNode<T> *current = root; //Always start at root
    TreeNode<T> *parent;

    while(true)
    {
      parent = current;

      if (key < current->key)
      {
        current = current->left;
        if (current == NULL){
          //Found location for newNode
          parent->left = newNode;
          break;
        }
      }
      else{
        current = current->right;
        if (current == NULL){
          parent->right = newNode;
          break;
        }
      }
    }
  }
}

bool search(int value){
  if(root == NULL){
    return false;
  }
  else{
    // if we make it this far then we know the tree is not empty
    // attemp to find the key
    TreeNode<T> *current = root;

    while(current->key != value){
      // keep searching unitl I don't find it
      if(value < current->key){
        current = current->left;
      }
      else{
        current = current->right;
      }
      if(current == NULL){ // value not in Tree
        return false;
      }
    }
  }
  return true;
}

T*find(int value){
  if(root == NULL){
    return NULL;
  }
  if(search(value)){
    TreeNode<T> *current = root;

    while(current->key != value){
      if(value < current->key){
        current = current->left;
      }
      else{
        current = current->right;
      }
      if(current == NULL){
        return NULL;
      }
    }
    return &current->data;

  }
  else{
    return NULL;
  }
}

bool deleteNode(int value){
  if(root == NULL){
    return false; // if empty
  }
  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  bool isLeft = true;

  // lets attempt to find the node to be deleted
  while(current->key != value){
    parent = current;

    if(value < current->key){
      // go left
      isLeft = true;
      current = current->left;
    }
    else{
      // we go right
      isLeft = false;
      current = current->right;
    }

    if(current == NULL) {
      // value doenst exists
      return false;
    }
  }
  // if we made it here we found the node to be deleted
  // check four conditions:  if its a leaf, if it has one child, and if its a right or left child, and then if it has 2 children

  if(current->right == NULL && current->left == NULL){
    // then node is a leaf, no children
    if(current == root){
      root == NULL;
    }
    else if(isLeft){
      parent->left = NULL;

    }
    else{
      parent->right = NULL;

    }
  }
  else if(current->right == NULL){ // node to be deleted has one child and its a left ( no right child)
    if(current == root){
      root = current->left;
    }
    else if(isLeft){
      parent->left = current->left;

    }
    else{
      parent->right = current->left;
    }
  }

  else if(current->left == NULL){ // node to be deleted has one child and its a right ( no left child)
    if(current == root){
      root = current->right;
    }
    else if(isLeft){
      parent->left = current->right;

    }
    else{
      parent->right = current->right;
    }
  }

  else{// the node to be deleted has two children

    TreeNode<T> *successor = getSuccessor(current);
    if (current == root){
      root = successor;
    }
    else if(isLeft){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }
    successor->left = current->left;
  }
  return true;
}

TreeNode<T>* getSuccessor(TreeNode<T> *d){ // d is the node to be deleted
  TreeNode<T> *current = d->right;
  TreeNode<T> *sp = d; // successors parent
  TreeNode<T> *successor = d;

  while(current != NULL) {
    sp = successor;
    successor = current;
    current = current->left;
  }
  // we made it here, that means we found our successor
  if(successor!= d->right){
    sp->left = successor->right;
    successor->right = d->right;


  }
  return successor;

}

T printSingle(int key){
    TreeNode<T> *current = root;
    if (root == NULL){
      cout << "Coudn't find node" << endl;
    }
    else{

      while(current->key != key)
      {
        if (key < current->key)
        {
          current = current->left;
        }
        else{
          current = current->right;
        }
        if (current == NULL){
          cout << "Couldn't find node. Fatal error. Forced to exit" << endl;
          exit(0);
        }
      }
    }
    cout << current -> data;
    exit(EXIT_FAILURE);
}

bool isEmpty() {
  return(size == 0);
}


void recPrintOutStud(TreeNode<T> *node){
  if(node == NULL){
    return;
 }
  ofstream outFile;
  outFile.open("studentTable.txt", ios_base::app);
  recPrintOutStud(node->left);
  outFile << node->data << endl;
  recPrintOutStud(node->right);
}

void printTreeOutStud(){
  recPrintOutStud(root);
  }

void recPrintOutFac(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  ofstream outFile1;
  outFile1.open("facultyTable.txt", ios_base::app);
  recPrintOutFac(node->left);
  outFile1 << node->data << endl;
  recPrintOutFac(node->right);
}

void printTreeOutFac(){
  recPrintOutFac(root);
}
};
