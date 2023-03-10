#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// BinaryTree template
template <class T>
class BinaryTree
{
private:
struct TreeNode
{
T value; // The value in the node
TreeNode *left; // Pointer to left child node
TreeNode *right; // Pointer to right child node
};

TreeNode *root; // Pointer to the root node
// Private member functions
void insert(TreeNode *&, TreeNode *&);
void destroySubTree(TreeNode *);
void deleteNode(T, TreeNode *&);
void makeDeletion(TreeNode *&);
void displayInOrder(TreeNode *) const;

public:
// Constructor
BinaryTree()
{ root = nullptr; }

// Destructor
~BinaryTree()
{ destroySubTree(root); }

// Binary tree operations
void insertNode(T);
bool searchNode(T);
void remove(T);

void displayInOrder() const
{ displayInOrder(root); }

void loadInOrderRec(TreeNode *nodeptr, T A[], int &pos);
void loadInOrder(T A[]);
void treeSort(T A[], int size);
};

template <class T>
void BinaryTree<T>::loadInOrderRec(TreeNode *nodeptr, T A[], int &pos) {
    if (nodeptr == NULL) {return;}
    loadInOrderRec(nodeptr->left, A, pos);
    A[pos] = nodeptr->value;
    pos++;
    loadInOrderRec(nodeptr->right, A, pos);
}

template <class T>
void BinaryTree<T>::loadInOrder(T A[]) {
    int cur = 0;
    loadInOrderRec(root, A, cur);
}

template <class T>
void BinaryTree<T>::treeSort(T A[], int size) {
    for (int i = 0; i < size; i++) {
        insertNode(A[i]);
    }
    loadInOrder(A);
}

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
if (nodePtr == nullptr)
nodePtr = newNode; // Insert the node
else if (newNode->value < nodePtr->value)
insert(nodePtr->left, newNode); // Search the left branch
else
insert(nodePtr->right, newNode); // Search the right branch
}

//***********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//***********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
TreeNode *newNode = nullptr; // Pointer to a new node

// Create a new node and store num in it.
newNode = new TreeNode;
newNode->value = item;
newNode->left = newNode->right = nullptr;

// Insert the node.
insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
if (nodePtr)
{
if (nodePtr->left)
destroySubTree(nodePtr->left);
if (nodePtr->right)
destroySubTree(nodePtr->right);
delete nodePtr;
}
}

//***************************************************
// searchNode determines if a value is present in *
// the tree. If so, the function returns true. *
// Otherwise, it returns false. *
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
TreeNode *nodePtr = root;

while (nodePtr)
{
if (nodePtr->value == item)
return true;
else if (item < nodePtr->value)
nodePtr = nodePtr->left;
else
nodePtr = nodePtr->right;
}
return false;
}

//***********************************************
// remove calls deleteNode to delete the *
// node whose value member is the same as num. *
//***********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value *
// member is the same as num. *
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
if (item < nodePtr->value)
deleteNode(item, nodePtr->left);
else if (item > nodePtr->value)
deleteNode(item, nodePtr->right);
else
makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node *
// that is to be deleted. The node is removed and the *
// branches of the tree below the node are reattached. *
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{ 

// Define a temporary pointer to use in reattaching
// the left subtree.
TreeNode *tempNodePtr = nullptr;

if (nodePtr == nullptr)
cout << "Cannot delete empty node.\n";
else if (nodePtr->right == nullptr)
{
tempNodePtr = nodePtr;
nodePtr = nodePtr->left; // Reattach the left child
delete tempNodePtr;
}
else if (nodePtr->left == nullptr)
{
tempNodePtr = nodePtr;
nodePtr = nodePtr->right; // Reattach the right child
delete tempNodePtr;
}
// If the node has two children.
else
{
// Move one node to the right.
tempNodePtr = nodePtr->right;
// Go to the end left node.
while (tempNodePtr->left)
tempNodePtr = tempNodePtr->left;
// Reattach the left subtree.
tempNodePtr->left = nodePtr->left;
tempNodePtr = nodePtr;
// Reattach the right subtree.
nodePtr = nodePtr->right;
delete tempNodePtr;
}
}

//*************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//*************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
if (nodePtr)
{
displayInOrder(nodePtr->left);
cout << nodePtr->value << endl;
displayInOrder(nodePtr->right);
}
}
#endif 