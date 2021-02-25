#ifndef TINTFINITEQUEUE_H
#define TINTFINITEQUEUE_H

#include <iostream>
using namespace std;
#include <cassert>


template <typename T>
class TIntFiniteQueue {
  private:
    T *pArray; // pointer to array of data
    int first; // index for 'front'
    int last;  // index for 'back', the last element in the queue
    int size; // number of data currently stored in the queue
    int capacity; // maximum capacity of the queue
  public:
  //  class QueueEmptyException{ }; // empty inner class for exception handling
  //  class QueueFullException{ }; // empty inner class for exception handling

    TIntFiniteQueue<T>(int capacity);
    TIntFiniteQueue(const T&);
    ~TIntFiniteQueue();

    void enqueue(T *data); // insert data into the back 
    void dequeue();   // get the data from the front 
    T front(); // read data at the front of the queue
    T back();  // read data at the rear of the queue
    bool isEmpty();
    bool isFull();

	void displayQueue();
};



// user determines the capacity of queue
template <typename T>
TIntFiniteQueue<T>::TIntFiniteQueue(int c) {
  capacity = c;
  first = 0;
  last = capacity - 1; 
  size = 0;
  pArray = new T*[capacity];
}


//copy constructor
template <typename T>
TIntFiniteQueue<T>::TIntFiniteQueue(const T& q) {
  capacity = q.capacity;
  first = q.first;
  last = q.last; 
  size = q.size;
  pArray = new T[capacity];
  for(int i = 0; i < capacity; i++) 
	pArray[i] = q.pArray[i];
	
}


// destructor: free all the memory allocated for this queue
template <typename T>
TIntFiniteQueue<T>::~TIntFiniteQueue() {
  delete [] pArray;
}

// is queue empty?
template <typename T>
bool TIntFiniteQueue<T>::isEmpty() {
  return size == 0;
}

// is queue full?
template <typename T>
bool TIntFiniteQueue<T>::isFull() {
  return size == capacity;
}

// append an item at the rear
template <typename T>
void TIntFiniteQueue<T>::enqueue(T *item) {
  if (isFull())
		cout << "cannot call enqueue(), the queue is full." << endl;

  //at least one empty slot
  ++last; //increase index for the new element
  if (last == capacity) last = 0; // wrap around. It is called circular queue
  pArray[last] = item;
  ++size; // one item added
}

// serve an item from the front
template <typename T>
void TIntFiniteQueue<T>::dequeue() {
  if (isEmpty())
	  cout << "cannot call dequeue(), the queue is empty." << endl;
  ++first;
  if (first == capacity) first = 0; // wrap around

  --size; // one item removed. Don't have to delete the item
}

// read data at the front of the queue
template <typename T>
T TIntFiniteQueue<T>::front() {
	if (isEmpty())
		cout << "cannot call front(), the queue is empty." << endl;

  return &pArray[first];
}

// read data at the rear of the queue
template <typename T>
T TIntFiniteQueue<T>::back() {
  if(isEmpty()) 
	cout << "cannot call back(), the queue is empty." << endl;

  return pArray[last];
}

template <typename T>
void TIntFiniteQueue<T>::displayQueue() {
	for (int i = 0; i < size; i++) { // 
		printf("|%4d", pArray[i]);
	}
	printf("|\n\n");
}

#endif
