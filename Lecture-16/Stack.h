#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"
using namespace std;

template <typename T>
class stack{
	node<T>* head;
	int cs;
public:

	stack(){
		head=NULL;
		cs=0;
	}

	void push(T data){
		node<T>* n=new node<T>(data);
		n->next=head;
		head=n;
		cs++;
	}

	void pop(){
		if(head==NULL){
			return;
		}
		node<T>* temp=head;
		head=head->next;
		delete temp;
		cs--;
	}

	T top(){
		return head->data;
	}

	int size(){
		return cs;
	}

	bool empty(){
		return cs==0;
	}

};

#endif









