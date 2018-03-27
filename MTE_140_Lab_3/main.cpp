#include <iostream>
#include <string>
using namespace std;

#include "Lab3Tests.hpp"
//#include "PriorityQueue.hpp" //TODO: get rid of this line 	;LASDKDJ
//#include "BinarySearchTree.hpp" //TODO: get rid of this as well

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main(int argc, char *argv[])
{
    PriorityQueueTest pqueue_test;
    BinarySearchTreeTest btree_test;
    bool pqueue_test1_passed = pqueue_test.test1();
    bool pqueue_test2_passed = pqueue_test.test2();
    bool pqueue_test3_passed = pqueue_test.test3();

    bool btree_test1_passed = btree_test.test1();
    bool btree_test2_passed = btree_test.test2();
    bool btree_test3_passed = btree_test.test3();

    cout << "---Priority Queue Tests---" << endl;
    cout << "Test1: " << get_status_str(pqueue_test1_passed) << endl;
    cout << "Test2: " << get_status_str(pqueue_test2_passed) << endl;
    cout << "Test3: " << get_status_str(pqueue_test3_passed) << endl;
    cout << endl;
    cout << "---Binary Search Tree Tests---" << endl;
    cout << "Test1: " << get_status_str(btree_test1_passed) << endl;
    cout << "Test2: " << get_status_str(btree_test2_passed) << endl;
    cout << "Test3: " << get_status_str(btree_test3_passed) << endl;
//
//	PriorityQueue pqueue_sub(16);
//	pqueue_sub.enqueue(3);
//	pqueue_sub.print();
//	BinarySearchTree btree_sub;
//	btree_sub.insert(12);
//	btree_sub.insert(5);
//	btree_sub.insert(13);
//	btree_sub.insert(14);
//	btree_sub.insert(3);
//	btree_sub.insert(6);
//	btree_sub.insert(2);
//	btree_sub.insert(4);
//	btree_sub.insert(7);
//	btree_sub.insert(8);
//	if(!btree_sub.insert(8))
//	{
//		cout << "insert failed" << endl;
//	}
//	btree_sub.remove(12); //TODO: check more check when the remove has two children that are both leafs
//	//and check removing ones with a lot of children
//	//and check removing root_
//	btree_sub.remove(3);
//	btree_sub.print();
//	int value = 12;
//	if (btree_sub.exists(value))
//		cout << value << " already exists" << endl;
//	else
//		cout << value << " doesn't exist" << endl;
//	btree_sub.print();
//	cout << btree_sub.max() << " is max" << endl;
//	cout << btree_sub.min() << " is min" << endl;
//	cout << btree_sub.depth() << " is the max depth" << endl;
//	cout << btree_sub.getNodeDepth(btree_sub.root_) << " is the depth from root" << endl;
//

//	for (int i = 1; i < argc; i++)
//	{
//		btree_sub.insert((int)argv[i]);
//	} // doesn't work as the argv[i] is not a simple character but a weird pointer thing
    system("pause");
}
