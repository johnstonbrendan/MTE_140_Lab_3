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
	Node* queue[size_];
	int p_index = 0, i_index = 1;
	queue[0] = root_;
	for (; p_index < size_; p_index++)
	{
		if (queue[p_index]->left != nullptr)
		{
			queue[i_index] = queue[p_index]->left;
			i_index++;
		}
		if (queue[p_index]->right != nullptr)
		{
			queue[i_index] = queue[p_index]->right;
			i_index++;
		}
		delete queue[p_index];
		queue[p_index] = nullptr;
	}
//	better destructor :/
//	for (DataType i = min(); i <= max(); i++)
//	{
//		remove(i);
//	}
}

bool BinarySearchTree::insert(DataType val)
{
	Node* newNode = new Node(val);
	if(size_ == 0)
	{
		root_ = newNode;
		size_++;
		return true;
	}
	if(exists(val))
	{
		return false;
	}
	Node* compareNode = root_;
	bool found = false;
	while (!found)
	{
		if(newNode->val > compareNode->val)
		{
			if(compareNode->right == nullptr)
			{
				compareNode->right = newNode;
				found = true;
			}
			compareNode = compareNode->right;
		}
		else
		{
			if (compareNode->left == nullptr)
			{
				compareNode->left = newNode;
				found = true;
			}
			compareNode = compareNode->left;
		}
	}
	compareNode = nullptr;
	size_++;
	return true;
}


bool BinarySearchTree::remove(DataType val)
{
	if(!exists(val))
	{
		return false;
	}
	if (size_ == 1)
	{
		delete root_;
		root_ = nullptr;
		size_--;
		return true;
	}
	Node* removeNode = root_;
	Node* parent = root_; //CHANGED THIS LINE LATER
	bool found = false, go_right = false;// make go right 1 if you want to go right
	while (!found)
	{
		if (val == removeNode->val)
		{
			found = true;
		}
		else if(val > removeNode->val)
		{
			parent = removeNode;
			go_right = true;
			removeNode = removeNode->right;
		}
		else
		{
			go_right = false;
			parent = removeNode;
			removeNode = removeNode->left;
		}
	}
//	cout << "value to remove is: " << removeNode->val << endl;
	if (removeNode->left == nullptr && removeNode->right == nullptr)
	{
		if (go_right)
		{
			parent->right = nullptr;
		}
		else
		{
			parent->left = nullptr;
		}
//			cout << "it is a leaf" << endl;
	}
	else if (removeNode->left != nullptr && removeNode->right == nullptr)
	{
		if (removeNode == root_)
		{
			go_right = false;
			root_ = root_->left;
		}
		else if (go_right)
		{
			parent->right = removeNode->left;
		}
		else
		{
			parent->left = removeNode->left;
		}
	}
	else if (removeNode->right != nullptr && removeNode->left == nullptr)
	{
		if (removeNode == root_)
		{
			go_right = true;
			root_ = root_->right;
		}
		else if (go_right)
		{
			parent->right = removeNode->right;
		}
		else
		{
			parent->left = removeNode->right;
		}
	}
	else //this case is when node is not a parent to a leaf or is not a leaf itself
	{//replace with predecessor
		Node* predecessor = removeNode->left;
		Node* s_parent = removeNode;
//			cout << removeNode->val;
//			system("pause");
		while (predecessor->right != nullptr)
		{
			s_parent = predecessor;
			predecessor = predecessor->right;
		}
//			cout << "remove the value: " <<removeNode->val << " and replace with: " << predecessor->val << endl;
//			system("pause");
		if (removeNode == root_)
		{
			root_ = predecessor;
		}
		else if (go_right)
		{
			parent->right = predecessor;
		}
		else
		{
			parent->left = predecessor;
		}
		//below check is important incase that there are only two children
		//and both are leafs, thus the left one should be choosen not the right
		if ((s_parent != root_) && (removeNode->left->right != nullptr))
		{
			s_parent->right = predecessor->left;
			predecessor->left = removeNode->left;
//			removeNode->left = predecessor->left;
		}
		else if(removeNode->left->right == nullptr)
		{
			predecessor->left = removeNode->left->left;
		}
		predecessor->right = removeNode->right;
//		else
//		{
////			parent->right = nullptr;
//			s_parent->right = predecessor->left;
//		}
		s_parent = nullptr;
		predecessor = nullptr;
	}
//	if (removeNode != root_)
		delete removeNode;
	removeNode = nullptr;
	parent = nullptr;
	size_--;
	return true;
}

bool BinarySearchTree::exists(DataType val) const
{
	Node* compareNode = root_;
	Node* parent = nullptr;
	while (compareNode != nullptr)
	{
		if (val == compareNode->val)
		{
			return true;
		}
		else if(val > compareNode->val)
		{
			parent = compareNode;
			compareNode = compareNode->right;
		}
		else
		{
			parent = compareNode;
			compareNode = compareNode->left;
		}
	}
	return false;
}

DataType BinarySearchTree::min() const
{
	Node* min = root_;
	while (min->left != nullptr)
	{
		min = min->left;
	}
	return min->val;
}

DataType BinarySearchTree::max() const
{
	Node* max = root_;
	while (max->right != nullptr)
	{
		max = max->right;
	}
	return max->val;
}

unsigned int BinarySearchTree::size() const
{
	return size_;
}

unsigned int BinarySearchTree::depth() const
{
	//TODO: do something like the print function and keep track of a max depth
	//everytime one of the if statements is satisfied this means it goes a layer deeper
	//keep track of the node that is at the greatest depth and continue to replace
	//keep max depth from left to right and continue to replace since right now it goes
	//level by level this may be easier
	//keep track when you go into a level and then continue comparing
	Node* queue[size_];
	Node* next_depth = root_;
	int p_index = 0, i_index = 1, depth = -1; //so it counts root as depth 0
	bool n_level = false;
	queue[0] = root_;
//	cout << "now printing" << endl;
	for (; p_index < size_; p_index++)
	{
		if (queue[p_index] == next_depth)
		{
			n_level = true;
			depth++;
		}
		if (queue[p_index]->left != nullptr)
		{
			queue[i_index] = queue[p_index]->left;
			i_index++;
			if(n_level)
			{
				next_depth = queue[i_index - 1];
				n_level = false;
			}
//			cout << "inserted " << queue[i_index-1]->val << " at index " << i_index-1 << endl;
		}
		if (queue[p_index]->right != nullptr)
		{
			queue[i_index] = queue[p_index]->right;
			i_index++;
			if(n_level)
			{
				next_depth = queue[i_index - 1];
				n_level = false;
			}
//			cout << "inserted " << queue[i_index-1]->val << " at index " << i_index-1 << endl;
		}
	}
	return depth;
}

void BinarySearchTree::print() const
{//prints level by level
	Node* queue[size_];
	int p_index = 0, i_index = 1;
	queue[0] = root_;
	cout << "now printing" << endl;
	for (; p_index < size_; p_index++)
	{
		cout << queue[p_index]->val << endl;
		if (queue[p_index]->left != nullptr)
		{
			queue[i_index] = queue[p_index]->left;
			i_index++;
//			cout << "inserted " << queue[i_index-1]->val << " at index " << i_index-1 << endl;
		}
		if (queue[p_index]->right != nullptr)
		{
			queue[i_index] = queue[p_index]->right;
			i_index++;
//			cout << "inserted " << queue[i_index-1]->val << " at index " << i_index-1 << endl;
		}
	}
	cout << "size is: " << size_ << endl;
	cout << "end print" << endl;
}

int BinarySearchTree::getNodeDepth(BinarySearchTree::Node* n) const
{
	if (n == nullptr)
	{
		return 0;
	}
	return std::max(getNodeDepth(n->left), getNodeDepth(n->right));
}
