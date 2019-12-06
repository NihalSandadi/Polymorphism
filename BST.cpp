// ------------------------------------------------ BST.cpp --------------------------------------------------------
// Jayden Stipek CSS 343 B
// Creation: 10/25/19
// Modified: 12/2/19
// -----------------------------------------------------------------------------------------------------------------
// Purpose - Encapsulate Movie data inside A Binary Search Tree
// -----------------------------------------------------------------------------------------------------------------
// Notes:
//		BST class
//		Creates a BST to store values
//		Uses Node which holds the Data
//		Uses templates to store any type of Data
//		binarysearchtree.cpp file is included at the bottom of the .h file
//		binarysearchtree.cpp is part of the template, cannot be compiled separately
// -----------------------------------------------------------------------------------------------------------------
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include "Movie.h"

using namespace std;

template<class T>
class BST {
	//------------------------- operator<< ---------------------------------
	// Calls printInOrder() to print out all of the data in the tree
	// Overloads operator<< to take in BinTrees and prints in order
	friend ostream& operator<<(ostream& output, const BST& rhs) {
		if (rhs.isEmpty())
			output << "Empty!" << endl;
		else { //print in order (Left, Root, Right)
			rhs.inOrderTraverse();
		}
		output << endl;
		return output;
	}
private:

	// Node for BST
	struct Node {
		T Data;
		struct Node* Left = nullptr;
		struct Node* Right = nullptr;
	};
	// refer to data type "struct Node" as Node
	using Node = struct Node;

	// root of the tree
	Node* Root;

public:
	// constructor, empty tree (Good)
	BST() {
		Root = nullptr;
	}

	// constructor, tree with root (Good)
	explicit BST(const T& RootItem) {
		Root = new Node();
		Root->Data = RootItem;
		Root->Left = nullptr;
		Root->Right = nullptr;
	}

	// given an array of length n
	// create a tree to have all items in that array
	// with the minimum height (i.e. rebalance)
	// Assignment specification
	// NOLINTNEXTLINE
	BST(const T Arr[], int N) {
		if (N <= 0) return;

		for (int I = 0; I < N; I++)
		{
			Add(Arr[I]);
		}
	}

	// copy constructor(Good possible leak)
	BST(const BST<T>& Bst) {
		Root = nullptr;
		copyHelper(Bst.Root);

	}
	//helper for copying an entire tree dynamically
	void copyHelper(Node* N)
	{
		if (N != nullptr)
		{
			this->Add(N->Data);
			copyHelper(N->Left);
			copyHelper(N->Right);
		}
	}

	// destructor
	virtual ~BST() {
		this->clear();
		Root = nullptr;
	}

	//Use's the recursive function clearTree
	void destroyRecursive()
	{
		if (this->Root == nullptr) return;
		clearTree(this->Root);
	}

	// true if no nodes in BST
	bool isEmpty() const {
		if (Root == nullptr)
		{
			return true;
		}
		else return false;
	}
	// Grabs the Root of the BST
	Node* getRoot() const
	{
		return Root;
	}

	// Number of nodes in BST using an inorder traversal
	int numberOfNodes() const {
		if (Root == nullptr) return 0;
		int counter = 0;
		int* NumOfNodes = &counter;
		return countingNodesRec(NumOfNodes, Root);
	}
	//recursive statement for traversing a tree
	int countingNodesRec(int* Counter, Node* Root) const {
		if (Root == nullptr) return *Counter;
		countingNodesRec(Counter, Root->Left);
		(*Counter)++;
		countingNodesRec(Counter, Root->Right);
		return *Counter;
	}

// add a new item, return true if successful (Good, but leak)
bool Add(const T& Item) {
	if (Root == nullptr)
	{
		Root = new Node();
		Root->Data = Item;
		return true;
	} else
	{
		if (!contains(Item))
		{
			recurseAdd(Root, Item);
			rebalance();
			return true;
		}
	}
	return false;
}

	//helper function for Add to keep track of the value of the added item
	bool recurseAdd(Node*& N, const T& Item)
	{
		//if you dont have a node, create a node
		if (N == nullptr)
		{
			N = new Node();
			N->Data = Item;
			N->Left = nullptr;
			N->Right = nullptr;
			//cout << "Adding node" << *Item << endl;
			return true;
		} //else if the we are not there yet keep going left
		else if (*Item < *N->Data)
		{
			//cout << "Add checking left" << endl;
			//cout << *Item << endl;
			//cout << *N->Data << endl;
			recurseAdd(N->Left, Item);
		}
		else
		{ //or go right
			//cout << "Add checking right" << endl;
			//cout << *Item << endl;
			//cout << *N->Data << endl;
			recurseAdd(N->Right, Item);
		}
		return false;
	}

	//Given a a non-empty binary tree, Return a node with minimum value
	Node* minValueNode(Node* N)
	{
		Node* Current = N;
		while (Current && Current->Left != nullptr)
			Current = Current->Left;

		return Current;
	}


	// remove item, return true if successful
	bool remove(const T& Item) {
		if (Root == nullptr) return false;

		Root = removeRecursive(Root, Item);
		if (Root == nullptr)
			return false;
		else
			return true;
	}

	//recursive function to keep track of where you are inside the tree
	Node* removeRecursive(Node* N, const T& Item)
	{
		//if it is not inside the tree
		if (N == nullptr) return N;

		if (Item < N->Data)
		{
			N->Left = removeRecursive(N->Left, Item);
		}
		else if (Item > N->Data)
		{
			N->Right = removeRecursive(N->Right, Item);
		}
		else
		{
			//node with one child
			if (N->Left == nullptr)
			{
				Node* temp = N->Right;
				delete(N);
				return temp;
			}
			else if (N->Right == nullptr)
			{
				Node* temp = N->Left;
				delete(N);
				return temp;
			}
			//Nodes with two children Get the Inorder sucessor
			Node* temp = minValueNode(N->Right);
			//copy the inorder sucessor's content thao this node
			N->Data = temp->Data;

			//Delete the inorder sucessor
			N->Right = removeRecursive(N->Right, temp->Data);
		}
		return N;
	}

	// true if item is in BST
	bool contains(const T& Item) const {
		if (Root == nullptr)
		{
			return false;
		}
		return containsRec(Root, Item);
	}
	//recusrive function to traverse tree
	bool containsRec(Node* N, const T& Item) const
	{
		//if you have reached the end then it is not in the tree
		if (N == nullptr)
		{
			return false;
		}
		//if it is the same then return true
		else if (Item == N->Data)
		{
			return true;
		}
		else if (Item < N->Data)
		{
			return containsRec(N->Left, Item);
		}
		else
		{
			return containsRec(N->Right, Item);
		}
	}

	bool Retrieve(T targetData, T& pointer) const {
		if (findRecursive(Root, targetData, pointer))
			return true;
		return false;
	}

	bool findRecursive(Node* current, T target
		, T &ptr) const
	{
		if (current == nullptr)
			return false;

		/*cout << "Target: " << *target << endl;
		cout << "Cur" << *current->Data << endl;*/
		if (*target == *current->Data)
		{
			ptr = current->Data;
			//cout << "returning true" << endl;;
			return true;
		}
		else if (*target < *current->Data)
		{
			//cout << "calling left" << endl;
			return findRecursive(current->Left, target, ptr);//less than
		}
		else {
			//cout << "calling right" << endl;
			return findRecursive(current->Right, target, ptr); //greater than
		}
		return false;
	}
	// inorder traversal: left-root-right
	//prints the tree
	void inOrderTraverse() const {
		inOrderHelper(Root);
	}
	//helper function for in order traversal
	void inOrderHelper(Node* Current) const
	{
		if (Current == nullptr) return;
		inOrderHelper(Current->Left);
		cout << *Current->Data << endl;
		inOrderHelper(Current->Right);
	}

	//------------------------- display ---------------------------------
	// pretty print data in order (overloaded << operator to print in order)
	void display() const {
		if (!isEmpty()) {
			char genre = this->Root->Data->MovieType;
			// Comedy == 'F'
			if (genre == 'F') {
				cout << "Genre "
					<< setw(12) << "Quantity"
					<< setw(20) << "Title"
					<< setw(37) << "Director"
					<< setw(14) << "Year\n";
				cout << *this << endl;
			}
			// Drama == 'D'
			else if (genre == 'D') {
				cout << "Genre "
					<< setw(12) << "Quantity"
					<< setw(20) << "Title"
					<< setw(36) << "Director"
					<< setw(14) << "Year\n";
				cout << *this << endl;
			}
			// Classic == 'C'
			else if (genre == 'C') {
				cout << " Genre"
					<< setw(12) << "Quantity"
					<< setw(20) << "Title"
					<< setw(36) << "Major Actor"
					<< setw(15) << "Year\n";
				cout << *this << endl;
			}
		}
		// bad input
		else
			cout << "Empty Tree!" << endl;
	}
	// create dynamic array, copy all the items to the array
	// and then read the array to re-create this tree from scratch
	// so that resulting tree is balanced
	void rebalance() {
		Root = buildTree(Root);
	}
	/* This function traverse the skewed binary tree and
	 stores its nodes pointers in vector nodes[] */
	void storeBSTNodes(Node* root, vector<Node*>& nodes)
	{
		// Base case
		if (root == nullptr)
			return;

		// Store nodes in Inorder (which is sorted
		// order for BST)
		storeBSTNodes(root->Left, nodes);
		nodes.push_back(root);
		storeBSTNodes(root->Right, nodes);
	}
	// This functions converts an unbalanced BST to (Nothing ATM)
  // a balanced BST
	Node* buildTree(Node* root)
	{
		// Store nodes of given BST in sorted order
		vector<Node*> nodes;
		storeBSTNodes(root, nodes);

		// Constucts BST from nodes[]
		int n = nodes.size();
		return buildTreeUtil(nodes, 0, n - 1);
	}

	/* Recursive function to construct binary tree */
	Node* buildTreeUtil(vector<Node*>& nodes, int start,
		int end)
	{
		// base case
		if (start > end)
			return nullptr;

		/* Get the middle element and make it root */
		int mid = (start + end) / 2;
		Node* root = nodes[mid];

		/* Using index in Inorder traversal, construct
		   left and right subtress */
		root->Left = buildTreeUtil(nodes, start, mid - 1);
		root->Right = buildTreeUtil(nodes, mid + 1, end);

		return root;
	}

	// delete all nodes in tree
	void clear() {
		if (this->Root == nullptr) return;
		clearTree(this->Root);
		Root = nullptr;
	}
	//helper function for clear to
	void clearTree(Node* N)
	{
		if (N == nullptr) return;
		clearTree(N->Left);
		clearTree(N->Right);
		delete N->Data;
		delete(N);
	}
};
