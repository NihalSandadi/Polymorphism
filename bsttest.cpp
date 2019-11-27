/**
 * Testing BST - Binary Search Tree functions
 *
 * This file has series of tests for BST
 * Each test is independent and uses assert statements
 * Test functions are of the form
 *
 *      test_netidXX()
 *
 * where netid is UW netid and XX is the test number starting from 01
 *
 * Test functions can only use the public functions from BST
 * testBSTAll() is called from main in main.cpp
 * testBSTAll calls all other functions
 * @author Multiple
 * @date ongoing
 */

#include "BST.cpp"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Trying to avoid global variables,
 * by creating a singleton class with our visitor functions
 * stringstream SS contains the output from visitor
 */
class TreeVisitor {
public:
  // never create an instance of TreeVisitor object
  // we'll just use the static functions
  TreeVisitor() = delete;

  // insert output to SS rather than cout, so we can test it
  static stringstream SS;

  static string getSS() {
    return SS.str();
  }

  static void resetSS() {
    SS.str(string());
  }
  // instead of cout, insert item into a string stream
  static void visitor(const string &Item) {
    SS << Item;
  }

  // instead of cout, insert item into a string stream
  static void visitor(const int &Item) {
    SS << Item;
  }
};

// initialize the static variable
//  warning: initialization of 'SS' with static storage duration
//  may throw an exception that cannot be caught [cert-err58-cpp]
//  Not sure how to do it without making code harder to read
//  NOLINTNEXTLINE
stringstream TreeVisitor::SS;

/**
 * Test functions by Yusuf Pisan
 */

 //Testing ==
void testPisan01() {
  cout << "Starting testPisan01" << endl;
  cout << "* Testing == and !=" << endl;
  BST<string> B1;
  BST<string> B2;
  BST<string> B3;
  // == and != for empty trees
  assert(B1 == B2 && (!(B1 != B2)));
  B1.add("c");
  B2.add("c");
  B3.add("b");
  // == and !- for 1-Node trees B1, B2, B3
  assert(B1 == B2 && (!(B1 != B2)));
  assert(B1 != B3 && (!(B1 == B3)));
  cout << "Ending testPisan01" << endl;
}

// Testing == in detail
void testPisan02() {
  cout << "Starting testPisan02" << endl;
  cout << "* Testing == and != with more detail" << endl;
  BST<string> B1;
  BST<string> B2;
  BST<string> B3;
  for (auto &S : vector<string>{"c", "a", "f", "g", "x"})
    B1.add(S);

  for (auto &S : vector<string>{"c", "f", "a", "g", "x"})
    B2.add(S);

  B3.add("b");

  // == for 5-Node trees B1, B2
  assert(B1 == B2 && (!(B1 != B2)));

  BST<string> B4(B3);
  // copy constructor for 1-Node trees B3, B4
  assert(B3 == B4 && (!(B3 != B4)));

  BST<string> B5(B1);
  // copy constructor for 5-Node trees B1, B5
  assert(B1 == B5 && (!(B5 != B1)));

  BST<string> B7("b");
  // 1-param constructor for 1-Node trees B3, B7
  assert(B3 == B7 && (!(B3 != B7)));

  cout << "Ending testPisan02" << endl;
}

// Testing traversal
void testPisan03() {
  cout << "Starting testPisan03" << endl;
  cout << "* Testing traversal" << endl;
  BST<string> B1;
  BST<string> B2;
  BST<string> B3;
  for (auto &S : vector<string>{"c", "a", "f", "g", "x"})
    B1.add(S);

  for (auto &S : vector<string>{"c", "f", "a", "g", "x"})
    B2.add(S);

  B3.add("b");

  TreeVisitor::resetSS();
  B1.inOrderTraverse(TreeVisitor::visitor);
  string Result = "acfgx";
  assert(TreeVisitor::getSS() == Result);

  TreeVisitor::resetSS();
  B1.preOrderTraverse(TreeVisitor::visitor);
  Result = "cafgx";
  assert(TreeVisitor::getSS() == Result);

  TreeVisitor::resetSS();
  B1.postOrderTraverse(TreeVisitor::visitor);
  Result = "axgfc";
  assert(TreeVisitor::getSS() == Result);

  B1.remove("a");
  cout << "Visual check B1:" << endl;
  cout << B1 << endl;
  cout << "After Rebalancing the tree" << endl;
  B1.rebalance();
  cout << B1 << endl;
  cout << "Ending testPisan03" << endl;
}

void testJayden04() {
	cout << "Starting testJayden04" << endl;
	cout << "* Testing traversal" << endl;
	BST<string> B1;
	BST<string> B2;
	BST<string> B3;
	for (auto& S : vector<string>{ "c", "a", "f", "g", "x" })
		B1.add(S);

	for (auto& S : vector<string>{ "c", "f", "a", "g", "x" })
		B2.add(S);

	B3.add("b");
	assert(B3.contains("b"));
	assert(!B3.contains("c"));
	assert(B3.getHeight() == 1);
	cout << B2 << endl;
	B2.remove("c");
	cout << B2 << endl;
	B2.remove("f");
	assert(B2.contains("x"));
	assert(B2.getHeight() == 2);
	cout << B2 << endl;

	TreeVisitor::resetSS();
	B1.inOrderTraverse(TreeVisitor::visitor);
	string Result = "acfgx";
	assert(TreeVisitor::getSS() == Result);

	TreeVisitor::resetSS();
	B1.preOrderTraverse(TreeVisitor::visitor);
	Result = "cafgx";
	assert(TreeVisitor::getSS() == Result);

	cout << B3 << endl;
	B3.add("a");
	B3.add("c");
	cout << "Removing B" << endl;
	B3.remove("b");
	cout << B3 << endl;
	cout << B3.numberOfNodes() << endl;
	assert(B3.numberOfNodes() == 2);
	assert(B3.contains("c"));
	assert(B3.getHeight() == 2);

	TreeVisitor::resetSS();
	B3.preOrderTraverse(TreeVisitor::visitor);
	Result = "ca";
	assert(TreeVisitor::getSS() == Result);
	B3.clear();
	assert(B3.isEmpty());
	B2.clear();
	//testing identicle trees
	B3.add("a");
	B3.add("c");
	B2.add("a");
	B2.add("c");
	cout << B3 << endl;
	//assert(IdenticalTrees(B3->Root,B2->Root));
	B3.rebalance();
	cout << "after rebalancing the tree" << endl;
	cout << B3 << endl;
	cout << "Removing c" << endl;
	B3.remove("c");
	cout << "Removed C" << endl;
	cout << B3 << endl;
	B3.add("b");
	B3.add("e");
	B3.add("d");
	cout << B3 << endl;
	assert(!B3.contains("c"));
	cout << "clearing B3" << endl;
	B3.clear();
	cout << B3 << endl;
	B3.add("z");
	B3.add("f");
	B3.remove("z");
	cout << "removing z" << endl;
	assert(!B3.contains("z"));
	cout << B3 << endl;
}

void testJayden05() {
	cout << "testing Remove" << endl;
	BST<string> B1;
	BST<string> B2;
	BST<string> B3;
	for (auto& S : vector<string>{ "c", "a", "f", "g", "x" })
		B1.add(S);
	cout << B1 << endl;
	assert(B1.contains("f"));
	assert(!B1.contains("z"));
	assert(!B1.isEmpty());
	assert(B2.isEmpty());
	assert(B1.numberOfNodes() == 5);
	assert(B2.numberOfNodes() == 0);
	assert(B1.numberOfNodes() != 11);
	B1.rebalance();
	B2.rebalance();
	B2.clear();
	assert(B2.isEmpty());
	assert(B1.getHeight() == 3);
	assert(B2.getHeight() == 0);
	cout << "Removing c" << endl;
	B1.remove("c");
	cout << "C has been removed" << endl;
	cout << B1 << endl;
	cout << "Removing a" << endl;
	B1.remove("a");
	cout << B1 << endl;
	cout << "Removing x" << endl;
	B1.remove("x");
	cout << B1 << endl;
}

/**
 * Test functions by Sample Sample
 */

// Testing samplefunctionality
void testSample01() {
  cout << "Starting testSample01" << endl;
  //assert(true);
  cout << "Ending testSample01" << endl;
}

// Calling all test functions
void testBSTAll() {
  testPisan01();
  testPisan02();
  testPisan03();
  testJayden04();
  testJayden05();
  testSample01();
}