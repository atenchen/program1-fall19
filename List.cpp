#include "List.h"
#define NULL 0

Node::Node(Planet* p){
	this->planet = p;
	next = prev = NULL;
}
Node::~Node(){
	delete planet;
}

List::List(){
	head = tail = NULL;
}
List::~List(){
	while(head != NULL){
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}
void List::insert(unsigned int index, Planet* p){
	if(index == 0 || head == NULL){
		insertHead(p);
		return;
	}

	Node* traverse = head->next;
	for(unsigned int i = 1; traverse != NULL; i++){
		if(i == index){
			Node* newNode = new Node(p);
			newNode->prev = traverse->prev;
			newNode->next = traverse;
			traverse->prev = newNode;
			return;
		}
		else{
			traverse = traverse->next;
		}
	}
	insertTail(p);
}
void List::insertHead(Planet* p){
	if(head == NULL){
		head = new Node(p);
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		return;
	}
	Node* newHead = new Node(p);
	newHead->next = this->head;
	newHead->prev = this->tail;//head->prev should be tail
	this->head->prev = newHead;
	this->head = newHead;
}
void List::insertTail(Planet* p){
	Node* newTail = new Node(p);
	newTail->prev = this->tail;
	newTail->next = NULL;
	this->tail->next = newTail;
	this->tail = newTail;
}

Planet* List::read(unsigned int index){
  if(index == 0){
	  return head->planet;
  }

  Node* traverse = head->next;
  for(unsigned int i = 1; traverse != NULL; i ++){
    if(i == index){
      return traverse->planet;
    }
    else{
      traverse = traverse->next;
    }
  }
  //index is out of bounds
  return NULL;
}

bool List::remove(unsigned int index){
  Node* traverse = head;
  if(index == 0){
    head = head->next;
    head->prev = traverse->prev;
    traverse->next->prev = head;
    delete traverse;
    return true;
  }

  traverse = head->next;
  for(unsigned int i = 1; traverse != NULL; i++){
	if(traverse == tail && i == index){
		tail->prev->next = NULL;
		tail = tail->prev;
		delete traverse;
		return true;
	}
	if(i == index){
      traverse->prev->next = traverse->next;
      traverse->next->prev = traverse->prev;
      delete traverse;
      return true;
    }
    else{
      traverse = traverse->next;
    }

  }
  return false;
}
unsigned int List::size(){
	if(head == NULL)
		return 0;
	Node* traversal = head;
	int size = 0;
	for(;traversal != NULL; size++)
		traversal = traversal->next;
	return size;
}
