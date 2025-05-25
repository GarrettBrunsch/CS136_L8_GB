// Garrett, Brunsch
// Lab #8 Graphs S25

//Please note the contents of this file are from the original file. For example the instances of "NULL" were provided and not written by me. 
//The project only wanted me to modify GraphType and main so that's where my modifications exist but this file is still necessary to run the program

#ifndef QUE_TYPE_H
#define QUE_TYPE_H

class FullQueue
{};  

class EmptyQueue
{};  
 
template <class ItemType>
struct NodeType;

template <class ItemType>
class QueType
{
public: 
    QueType();
    QueType(int max);
    ~QueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
private:
  NodeType<ItemType>* front;
  NodeType<ItemType>* rear;
};

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};


template <class ItemType>
QueType<ItemType>::QueType()
{
  front = NULL;
  rear = NULL;
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty()
{
  NodeType<ItemType>* tempPtr;

  while (front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  rear = NULL;
}

template <class ItemType>
QueType<ItemType>::~QueType()
{
  MakeEmpty();
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(bad_alloc exception)
  {
    return true;
  }
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
  return (front == NULL);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  

{
  if (IsFull())
    throw FullQueue();
  else
  {
    NodeType<ItemType>* newNode;

    newNode = new NodeType<ItemType>;
    newNode->info = newItem;
    newNode->next = NULL;
    if (rear == NULL)
      front = newNode;
    else
      rear->next = newNode;
    rear = newNode;
  }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    NodeType<ItemType>* tempPtr;

    tempPtr = front;
    item = front->info;
    front = front->next;
    if (front == NULL)
      rear = NULL;
    delete tempPtr;
  }
}

#endif // QUE_TYPE_H
