#include "BinarySearchTree.hpp"
#include <iostream>
#include <cstdlib>
typedef BinarySearchTree::DataType DataType;
using namespace std;




// Implement the functions here.
BinarySearchTree::Node::Node(DataType newval)
{
	val = newval;
	left = nullptr;
	right = nullptr;
}
BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	delete root_;
	root_ = nullptr;
}

bool BinarySearchTree::insert(DataType val)
{
	Node* newNode = new Node(val);
	if(size_ == 0)
	{
		root_ = newNode;
		size++;
		return true;
	}
	if(exists(val))
	{
		return false;
	}
	Node* compareNode = root_;
	size_++;
	int go_right = 0; // make go right 1 if you want to go right
	for (int i = 1; i <= size_; i = 2*i + go_right)//increments everytime to go down left child
		//unless otherwise specified by variable
		//this for loop may not be be needed and just can keep while(true)
	{
		go_right = 0;
		if(newNode->val > compareNode->val)
		{
			go_right = 1;
			if(compareNode->right == nullptr)
			{
				compareNode->right = compareNode;
				break;
			}
			compareNode = compareNode->right;
		}
		else
		{
			if (compareNode->left == nullptr)
			{
				compareNode->left = newNode;
				break;
			}
			compareNode = compareNode->left;
		}
	}
	return true;
}


bool BinarySearchTree::remove(DataType val)
{
	if(!exists(val))
	{
		return false;
	}
	Node* removeNode = root_;
		int go_right = 0; // make go right 1 if you want to go right
		for (int i = 1; i <= size_; i = 2*i + go_right)//increments everytime to go down left child
			//unless otherwise specified by variable
			//this for loop may not be be needed and just can keep while(true)
		{
			go_right = 0;
			if (val == removeNode->val)
			{
				break;
			}
			else if(val > removeNode->val)
			{
				go_right = 1;
				removeNode = removeNode->right;
			}
			else
			{
				removeNode = removeNode->left;
			}
		}
		if (isLeaf(removeNode))
		{
			delete removeNode;
			removeNode = nullptr;
		}
		else if (removeNode->left != nullptr && removeNode->right == nullptr)
		{
			removeNode = removeNode->left;
			delete removeNode;
			removeNode = nullptr;
		}
		else if (removeNode->right != nullptr && removeNode->left == nullptr)
		{
			removeNode = removeNode->right;
			delete removeNode;
			removeNode = nullptr;
		}
		else //this case is when node is not a parent to a leaf or is not a leaf itself
		{
			for (int i = )  //TODO: HERE I AM
		}
		size_--;
		return true;

}

bool BinarySearchTree::exists(DataType val) const
{
	if (size_ == 0)
		return false;

}

bool BinarySearchTree::isLeaf(Node* checkNode) const
{
	if (checkNode->left == nullptr && checkNode->right == nullptr)
		return true;
	return false;
}
