#include "PriorityQueue.hpp"
#include <iostream>
#include <cstdlib>
typedef PriorityQueue::DataType DataType;
using namespace std;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
	if (capacity == 0)
		capacity_ = 2; //default capacity should be 2
	// TODO: need to check what the default is^^
	capacity_ = capacity;
	size_ = 0;
	heap_ = new DataType[capacity_ + 1];
}
PriorityQueue::~PriorityQueue()
{
	delete [] heap_;
	heap_ = nullptr;
}

bool PriorityQueue::enqueue(DataType val)
{
	if (size_ == capacity_)
	{
		return false;
	}
	size_++;
	DataType swap = val;
	heap_[size_] = val;
	heap_[0] = val + 1; // in order to prevent from the zero index from being used
	for (int i = size_; i >= 1;)
	{
		if (heap_[i/2] < heap_[i])
		{
			swap = heap_[i];
			heap_[i] = heap_[i/2];
			heap_[i/2] = swap;
			i /= 2;
			//TODO check if above actually
			//works or should i just do a temp variables
		}
		else
			break;
	}
	return true;
}
bool PriorityQueue::dequeue()
{
	DataType swap = heap_[size_];
	if (size_ == 0)
	{
		return false;
	}
	heap_[1] = heap_[size_];
	size_--;
	bool one_child = false;
	for (int i = 1; 2*i <= size_;)
	{
		if (2*i + 1 > size_)
			one_child = true;
		if ((heap_[i] <= heap_[2*i]) && ((heap_[2*i] > heap_[2*i + 1]) || one_child))
		{
			swap = heap_[2*i];
			heap_[2*i] = heap_[i];
			heap_[i] = swap;
			i = 2*i;
		}
		else if ((!one_child) && heap_[i] <= heap_[2*i+1])
		{
			swap = heap_[2*i + 1];
			heap_[2*i + 1] = heap_[i];
			heap_[i] = swap;
			i = 2*i + 1;
		}
		else
		{
			break;
		}
	}
	return true;
}

DataType PriorityQueue::max() const
{
	if (size_ == 0)
	{
		cout << "Cannot return max as it is empty" << endl;
		return 9999999;
	}
	return heap_[1];
}

bool PriorityQueue::empty()const
{
	return size_== 0;
}
bool PriorityQueue::full() const
{
	return size_ == capacity_;
}
unsigned int PriorityQueue::size() const
{
	return size_;
}
void PriorityQueue::print() const
{
	cout << "Now Printing:" << endl;
	cout << "Size is: " << size_ << endl;
	cout << "Capacity is: " << capacity_ << endl;
	for (int i = 1; i <= size_; i++)
		cout << heap_[i] << endl;
}

