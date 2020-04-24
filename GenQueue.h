#include <iostream>
#include "GenDoublyLinkedList.h"

using namespace std;

template <class T>
class GenQueue
{
public:
  GenQueue(); // default constructor
  ~GenQueue();

  //core functions
  void insert(T d); //enqueque
  T remove(); //dequeque

  //aux functions
  T peek();
  bool isFull();
  bool isEmpty();
  int getSize();

  //vars
  int front; //aka head
  int rear; //aka tail
  int mSzie;
  int numElements;

   GenDoublyLinkedList<T> *myQueue;
};

template <class T>
GenQueue<T>::GenQueue()
{
  //defualt constructor
  myQueue = new GenDoublyLinkedList<T>();
  front = 0;
  rear = -1;
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue()
  {
    delete myQueue;
  }

template <class T>
void GenQueue<T>::insert(T d)
  {
    myQueue->insertBack(d);
    //add error checking
    myQueue[++rear] = d;
    ++numElements;
  }

  template <class T>
  T GenQueue<T>::remove()
  {
    //error checking
    ++front;
    --numElements;
    return myQueue->removeFront();
  }

  template <class T>
  T GenQueue<T>::peek()
  {
    return myQueue->front;
  }

  template <class T>
  bool GenQueue<T>::isEmpty()
  {
    return (numElements == 0);
  }

  template <class T>
  int GenQueue<T>::getSize()
  {
    return numElements;
  }
