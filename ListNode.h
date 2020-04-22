#include <iostream>
using namespace std;

//class ListNode.h from class

template <class T>
class ListNode
{
public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode(); //constructor
  ListNode(T d); //overloaded constructor
  ~ListNode();

};
template <class T>
ListNode<T>::ListNode(T d){
//doubleLinkedList.h from class
data = d;
next = NULL;
prev = NULL;
}

//NodeQuiz.h from class
template <class T>
ListNode<T>::~ListNode(){
  if(next == NULL){

    delete next;
    delete prev;
  }
}
