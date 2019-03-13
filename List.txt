#include "List.h"

/**
 * constuctor for list
 * creates an empty list with head and tail pointers as null
 **/
template <typename Type>
List<Type>::List() {
    head = NULL;
    tail = NULL;
}

/**
 * constructor for list
 * constructs new deep copy of list
 **/
template <typename Type>
List<Type>::List(const List<Type>& list) {

    List<Type> temp = List();

    while(list.size()!=0) {
        temp.push_back(list->head.data);
        list.pop_front();
    }
    this->head = temp->head;
    this->tail = temp->tail;
}


template <typename Type>
List<Type>::~List() {
    while(this->size()!=0) {
        this.pop_front();
    }
    static_assert(this->head==NULL && this->tail==NULL);
}

template <typename Type>
void List<Type>::push_back(Type element) {
    if (head == NULL) {
        head = new Node<Type>(element);
        tail = head;
        
    } else {
        // Node * localTail = tail;
        Node<Type> * newTail = new Node<Type>(element, NULL, tail);
        tail->next = newTail;
        tail = newTail;
    }
    len++;
}

template <typename Type>
void List<Type>::pop_back() {
    Node<Type> * temp = tail->prev;
    delete tail;
    tail = temp;
    len--;
}

template <typename Type>
void List<Type>::push_front(Type element) { 
    if (tail == NULL) {
        head = new Node<Type>(element);
        tail = head;
    } else {
        // Node * localTail = tail;
        Node<Type> * newHead = new Node<Type>(element, head, NULL);
        head->prev = newHead;
        head = newHead;
    }
    len++;
}

template <typename Type>
void List<Type>::pop_front() {
    Node<Type> * temp = head->next;
    delete head;
    head = temp;
    len--;
}

template <typename Type>
void List<Type>::swap(List<Type>& other) {
    
    this->head = other->head;
    this->tail = other->tail;
}

template <typename Type>
int List<Type>::size() {
    return len;
}

template <typename Type>
List<Type>& List<Type>::operator= (const List<Type>& other) {
    List<Type> temp(other);
    swap(temp);
    return *this;
}

template <typename Type>
iterator<Type> List<Type>::begin() {
    iterator<Type> i(this, this->head);
    return i;
}

template <typename Type>
iterator<Type> List<Type>::end() {
    iterator<Type> i(this, this->tail);
    return i;
}

template <typename Type>
iterator<Type> List<Type>::insert(iterator<Type> position, const Type& value) {

    if( position.current == this->head) { //beginning 
        push_front(value);
        //retrun new iterator at head
        iterator<Type> newIt = iterator<Type>(this, this->head);
        return newIt;
        
    } else if( position.current == this->tail ) { // end
        push_back(value);
        iterator<Type> newIt = iterator<Type>(this, this->tail);
        return newIt;
    } else { 
        Node<Type>* newNode = new Node<Type>(value,position.current->prev, position.current);
        
        position.current->prev = newNode;
        position.current->prev->next = newNode;

        iterator<Type> newIt = iterator<Type>(this, newNode);
        return newIt;
        size++;
    }
}


