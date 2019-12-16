#ifndef LIST_H
#define LIST_H
#include "Planet.h"

class Node{
public:
	Planet *planet;
	Node* next;
	Node* prev;

	Node(Planet*);
	~Node();
};

class List{
public:
	Node* head;
	Node* tail;
  	List();
	~List();
	void insert(unsigned int, Planet*);
	void insertHead(Planet*);
	void insertTail(Planet*);
	Planet* read(unsigned int);
	bool remove(unsigned int);
	unsigned int size();
};
#endif
