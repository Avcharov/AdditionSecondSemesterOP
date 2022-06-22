#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Tree {
	struct Node {
		string word;
		int counter = 1;
		Node* leftBranch;
		Node* rightBranch;
	};

	Node* root;

	void addElementRecursion(Node*&, string, int);
	void printTreeRecursion(Node*, int);
	void printTreeInOredrRecursion(Node*);
public:
	Tree();
	~Tree();
	void addElement(string, int);
	void printTree();
};