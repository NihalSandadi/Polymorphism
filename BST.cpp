//Jayden Stipek stipejay@uw.edu
// 15 Jan 2019

// BST class
// Creates a BST to store values
// Uses Node which holds the Data
// Uses templates to store any type of Data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately (wrong)

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

template<class T>
class BST {
	// display BST tree in a human-readable format
	friend ostream& operator<<(ostream& Out, const BST& Bst) {
		Bst.printSideways(Out, Bst.Root);
		Out << endl;
		Bst.printVertical(Out, Bst.Root);
		return Out;
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
	Node* Root{ nullptr };

	// height of a Node, nullptr is 0, Root is 1, static, no access to 'this'
	static int getHeight(const Node* N) {
		if (N == nullptr)
		{
			return 0;
		}
		else
		{
			int LDepth = getHeight(N->Left);
			int RDepth = getHeight(N->Right);

			if (LDepth > RDepth)
			{
				return(LDepth + 1);
			}
			else
			{
				return(RDepth + 1);
			}
		}
	}

	/**
	 * print tree sideways with root on left
				  6
			  2
				  5
		  0
				  4
			  1
				  3
	 */
	static ostream& printSideways(ostream& Out, const Node* Curr, int Level = 0) {
		const static char SP = ' ';
		const static int ReadabilitySpaces = 4;
		if (!Curr)
			return Out;
		printSideways(Out, Curr->Right, ++Level);
		Out << setfill(SP) << setw(Level * ReadabilitySpaces) << SP;
		Out << Curr->Data << endl;
		printSideways(Out, Curr->Left, Level);
		return Out;
	}

	static ostream& centeredPrint(ostream& Out, int Space,
		const string& Str, char FillChar = ' ') {
		auto StrL = static_cast<int>(Str.length());
		int Extra = (Space - StrL) / 2;
		if (Extra > 0) {
			Out << setfill(FillChar) << setw(Extra + StrL) << Str;
			Out << setfill(FillChar) << setw(Space - Extra - StrL) << FillChar;
		}
		else {
			Out << setfill(FillChar) << setw(Space) << Str;
		}
		return Out;
	}

	/**
	 * print tree with the root at top
	 *
		_____0______
	 __1___      __2___
	3     4     5     6
	 *
	**/
	static ostream& printTreeLevel(ostream& Out, queue<const Node*>& Q,
		int Width, int Depth, int MaxDepth) {
		const static char SP = ' ';
		const static char UND = '_';
		int Nodes = 0;
		int MaxN = (int)pow(2, Depth - 1);
		int SpaceForEachItem = Width * (int)pow(2, MaxDepth - 1) / MaxN; // NOINT
		string
			Bigspace = string(static_cast<uint64_t>(SpaceForEachItem / 4), SP);
		while (Nodes++ < MaxN) {
			const Node* Tp = Q.front();
			Node* TpL = nullptr;
			Node* TpR = nullptr;
			Q.pop();
			string Label = "N";
			if (Tp) {
				stringstream Ss;
				Ss << Tp->Data;
				Label = Ss.str();
				TpL = Tp->Left;
				TpR = Tp->Right;
			}
			char Filler = Depth == MaxDepth ? SP : UND;
			if (Depth == MaxDepth) {
				centeredPrint(Out, SpaceForEachItem, Label, Filler);
			}
			else {
				Out << Bigspace;
				centeredPrint(Out, SpaceForEachItem / 2, Label, Filler);
				Out << Bigspace;
				Q.push(TpL);
				Q.push(TpR);
			}
		}
		Out << endl;
		return Out;
	}

	// helper function for displaying tree sideways, works recursively
	static ostream& printVertical(ostream& Out, Node* Curr) {
		const static int WIDTH = 6;  // must be even
		if (!Curr)
			return Out << "[__]";
		// figure out the maximum depth which determines how wide the tree is
		int MaxDepth = getHeight(Curr);
		queue<const Node*> Q;
		Q.push(Curr);
		for (int Depth = 1; Depth <= MaxDepth; ++Depth) {
			printTreeLevel(Out, Q, WIDTH, Depth, MaxDepth);
		}
		return Out;
	}

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
			add(Arr[I]);
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
			this->add(N->Data);
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

	// 0 if empty, 1 if only root, otherwise
	// height of root is max height of subtrees + 1
	int getHeight() const {
		if (Root == nullptr)
			return 0;
		else
		{
			int LDepth = getHeight(Root->Left);
			int RDepth = getHeight(Root->Right);

			if (LDepth > RDepth)
				return(LDepth + 1);
			else return(RDepth + 1);
		}
	}

	Node* getRoot() const
	{
		return Root;
	}

	// Number of nodes in BST using an inorder traversal (not done)
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
	bool add(const T& Item) {
		if (Root == nullptr)
		{
			Root = new Node();
			Root->Data = Item;
			return true;
		}
		else
		{
			recurseAdd(Root, Item);
			return true;
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
			return true;
		} //else if the we are not there yet keep going left
		else if (Item < N->Data)
		{
			recurseAdd(N->Left, Item);
		}
		else
		{ //or go right
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

	void inOrderTraverse(void Visit(const T& Item)) const 
	{
		if (Root == nullptr) return;
		inOrderHelper(Visit, Root);
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

	// inorder traversal: left-root-right
	// takes a function that takes a single parameter of type T
	//void inOrderTraverse(void Visit(const T& Item)) const {
	//	if (Root == nullptr) return;
	//	inOrderHelper(Visit, Root);

	//}
	//helper function for in order traversal
	void inOrderHelper(void Visit(const T& Item), Node* Root) const
	{
		if (Root == nullptr) return;
		inOrderHelper(Visit, Root->Left);
		Visit(Root->Data);
		inOrderHelper(Visit, Root->Right);
	}

	// preorder traversal: root-left-right
	void preOrderTraverse(void Visit(const T& Item)) const {
		if (Root == nullptr) return;
		//calling the helper
		preOrderHelper(Visit, Root);
	}
	//helper function for preorder traversal
	void preOrderHelper(void Visit(const T& Item), Node* Root) const
	{
		if (Root == nullptr) return;
		Visit(Root->Data);
		preOrderHelper(Visit, Root->Left);
		preOrderHelper(Visit, Root->Right);
	}

	// postorder traversal: left-right-root
	void postOrderTraverse(void Visit(const T& Item)) const {
		if (Root == nullptr)
			return;

		// first recur on left subtree pasing in a function
		postOrderHelper(Visit, Root);
	}
	//recusrively goes through the tree in postorder fashion
	void postOrderHelper(void Visit(const T& Item), Node* Root) const
	{
		if (Root == nullptr) return;
		postOrderHelper(Visit, Root->Left);
		postOrderHelper(Visit, Root->Right);
		Visit(Root->Data);
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
		delete(N);
	}

	// trees are equal if they have the same structure
	// AND the same item values at all the nodes
	bool operator==(const BST<T>& Other) const {
		if (this->Root == nullptr && Other.Root == nullptr)
		{
			return true;
		}
		return identicalTrees(this->Root, Other.Root);
	}

	//Helper for ==operator
	/* Given two trees, return true if they are
  structurally identical */
	bool identicalTrees(const Node* a, const Node* b) const
	{
		/*1. both empty */
		if (a == nullptr && b == nullptr)
			return true;

		/* 2. both non-empty -> compare them */
		if (a != nullptr && b != nullptr)
		{
			return
				(a->Data == b->Data &&
					identicalTrees(a->Left, b->Left) &&
					identicalTrees(a->Right, b->Right)
					);
		}
		return false;
	}

	// not == to each other easier to use than recoding == 
	bool operator!=(const BST<T>& Other) const {
		return !(*this == Other);
	}
};

