#include "IntFiniteQueue.h"
#include <iostream>
using namespace std;
#include <cassert>

// user determines the capacity of queue
IntFiniteQueue::IntFiniteQueue(int c) {
  capacity = c;
  first = 0;
  last = capacity - 1; 
  size = 0;
  pArray = new int[capacity];
}


//copy constructor
IntFiniteQueue::IntFiniteQueue(const IntFiniteQueue& q) {
  capacity = q.capacity;
  first = q.first;
  last = q.last; 
  size = q.size;
  pArray = new int[capacity];
  for(int i = 0; i < capacity; i++) 
	pArray[i] = q.pArray[i];
	
}


// destructor: free all the memory allocated for this queue
IntFiniteQueue::~IntFiniteQueue() {
  delete [] pArray;
}

// is queue empty?
bool IntFiniteQueue::isEmpty() {
  return size == 0;
}

// is queue full?
bool IntFiniteQueue::isFull() {
  return size == capacity;
}

// append an item at the rear
void IntFiniteQueue::enqueue(int item) {
  if (isFull())
		cout << "cannot call enqueue(), the queue is full." << endl;

  //at least one empty slot
  ++last; //increase index for the new element
  if (last == capacity) last = 0; // wrap around. It is called circular queue
  pArray[last] = item;
  ++size; // one item added
}

// serve an item from the front
void IntFiniteQueue::dequeue() {
  if (isEmpty())
	  cout << "cannot call dequeue(), the queue is empty." << endl;
  ++first;
  if (first == capacity) first = 0; // wrap around

  --size; // one item removed. Don't have to delete the item
}

// read data at the front of the queue
int IntFiniteQueue::front() {
	if (isEmpty())
		cout << "cannot call front(), the queue is empty." << endl;

  return pArray[first];
}

// read data at the rear of the queue
int IntFiniteQueue::back() {
  if(isEmpty()) 
	cout << "cannot call back(), the queue is empty." << endl;

  return pArray[last];
}

void IntFiniteQueue::displayQueue() {
	for (int i = 0; i < size; i++) { // 
		printf("|%4d", pArray[i]);
	}
	printf("|\n\n");
}