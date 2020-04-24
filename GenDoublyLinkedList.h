#include <iostream>
#include "ListNode.h"
using namespace std;

template <class T>
class GenDoublyLinkedList{
private:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;
public:
  GenDoublyLinkedList();
  ~GenDoublyLinkedList();

  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  T deletePos(int pos);
  int find(T d);

  bool isEmpty();
  void printList();
  unsigned int getSize();
};

template <class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){
  if(front == NULL){
    delete front;
    delete back;
  }
}

template <class T>
unsigned int GenDoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool GenDoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

template <class T>
void GenDoublyLinkedList<T>::printList(){
  ListNode<T> *curr = new ListNode<T>();
  curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }

}

template <class T>
void GenDoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(front == NULL){
    front = node;
    back = node;
  }
  else{
    node->next = front;
    node->prev = NULL;
    front->prev = node;
    front = node;
  }
  size++;
}

template <class T>
void GenDoublyLinkedList<T>::insertBack(T d){
  if(back == NULL){
    insertFront(d);
  }
  else{
    ListNode<T> *node = new ListNode<T>(d);
    node->prev = back;
    back->next = node;
    node->next = NULL;
    //


    back = node;
    size++;
  }
}

template <class T>
T GenDoublyLinkedList<T>::removeFront(){
  T t;
  if(size > 0){
    if(size == 1){
      t = front->data;
      ListNode<T> *replace1 = front;
      delete replace1;
      front = NULL;
      back = NULL;

    }
    else{
      t = front->data;
      ListNode<T> *replace = front;
      front = front->next;
      front->prev = NULL;
      delete replace;
    }

    size--;
    return t;
  }
  else{
    cout << "List is empty." << endl;
    exit(0);
  }


}

template <class T>
T GenDoublyLinkedList<T>::removeBack(){
  T t;
  if(size > 0){
    if(size == 1){
      removeFront();
    }
    else{
      t = back->data;
      ListNode<T> *replace1 = back;
      back = back->prev;
      back->next = NULL;
      delete replace1;
    }


    size--;
    return t;
  }
  else{
    cout << "List is empty." << endl;
    exit(0);
  }

}

template <class T>
T GenDoublyLinkedList<T>::deletePos(int pos){
  if(pos >= size){
    cout << "Error: Tried accessing item at position " << pos << " and available positions are 0-" << (size-1) << endl;
    exit(0);
  }
  int index = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;
  while(pos != pos){
    prev = curr;
    curr = curr->next;
    index++;
  }

  if(curr == back){
    back = prev;
    curr->next = NULL;
    curr->prev = NULL;
  }
  
  else{
    prev->next = curr->next;

    curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
  }

  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}

template <class T>
int GenDoublyLinkedList<T>::find(T d){
  int pos = 0;
  ListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data == d){
      return pos;
    }

    pos++;
    curr = curr->next;
  }
  if(curr == NULL){
    pos = -1;
  }
  return pos;
}
