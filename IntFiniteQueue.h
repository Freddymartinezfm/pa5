#ifndef INTFINITEQUEUE_H
#define INTFINITEQUEUE_H

class IntFiniteQueue {
  private:
    int* pArray; // pointer to array of data
    int first; // index for 'front'
    int last;  // index for 'back', the last element in the queue
    int size; // number of data currently stored in the queue
    int capacity; // maximum capacity of the queue
  public:
  //  class QueueEmptyException{ }; // empty inner class for exception handling
  //  class QueueFullException{ }; // empty inner class for exception handling

    IntFiniteQueue(int capacity);
    IntFiniteQueue(const IntFiniteQueue&);
    virtual ~IntFiniteQueue();

    void enqueue(int data); // insert data into the back 
    void dequeue();   // get the data from the front 
    int front(); // read data at the front of the queue
    int back();  // read data at the rear of the queue
    bool isEmpty();
    bool isFull();

	void displayQueue();
};

#endif
