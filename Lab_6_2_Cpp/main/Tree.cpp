#include "Tree.h"


Tree::Tree() 
{
	this->root = NULL;
}

Tree::~Tree() 
{
	delete root;
}

void Tree::addElement(string word, int counter) 
{
	addElementRecursion(this->root, word, counter);
}

void Tree::addElementRecursion(Node*& node, string word, int counter) 
{
	if (!node) 
	{
		node = new Node;
		node->leftBranch = NULL;
		node->rightBranch = NULL;
		node->word = word;
		node->counter = counter;
		return;
	}
	
	if (word > node->word) 
	{
		addElementRecursion(node->rightBranch, word, counter);
	}

	if (word < node->word) 
	{
		addElementRecursion(node->leftBranch, word, counter);
	}
	
	if (word == node->word)  
	{
		node->counter++;
	}
}

void Tree::printTree() {
	cout << "\nTree visualization:" << endl;
	printTreeRecursion(root, 0);

	cout << "\nIdentifiers arranged in alphabetical order:" << endl;
	printTreeInOredrRecursion(root);
}

void Tree::printTreeRecursion(Node* branch, int tabs) 
{
	if (!branch) 
	{
		return;
	}
	printTreeRecursion(branch->rightBranch, ++tabs);

	for (int i = 1; i < tabs; i++) 
	{
		cout << "\t";
	}
	cout << branch->word << "[" << branch->counter << "]" << endl;
	printTreeRecursion(branch->leftBranch, tabs);
}

void Tree::printTreeInOredrRecursion(Node* parent) 
{
	if (!parent) 
	{
		return;
	}

	printTreeInOredrRecursion(parent->leftBranch);

	cout << "Identifier: " << parent->word << " (" << parent->counter << " time/s)" << endl;
	
	printTreeInOredrRecursion(parent->rightBranch);
}