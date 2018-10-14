#include <iostream>
using namespace std;
// class =struct
class node{
public:
	int data;
	node* next;
	node(int d):data(d),next(NULL){

	}
};

class LinkedList{
	node* recursiveSearchHelper(node* head,int key){
		// base case
		if(head==NULL){
			return NULL;
		}
		else if(head->data==key){
			return head;
		}

		return recursiveSearchHelper(head->next,key);		
	}	
public:
	node* head;
	node* tail;

	LinkedList(){
		head=tail=NULL;
	}

	void InsertAtFront(int data){
		if(head==NULL){
			node* n=new node(data);
			n->next=head;
			head=tail=n;
		}
		else{
			node* n=new node(data);
			n->next=head;
			head=n;
		}
	}	

	void InsertAtEnd(int data){
		if(head==NULL){
			node* n=new node(data);
			head=tail=n;
		}
		else{
			node* n=new node(data);
			tail->next=n;
			tail=n;
		}
	}

	void InsertAtMid(int data,int pos){
		if(pos==0){
			InsertAtFront(data);
		}
		else if(pos>length()){
			InsertAtEnd(data);
		}
		else{
			int jump=1;
			node* temp=head;
			while(jump<=(pos-1)){
				temp=temp->next;
				jump++;
			}
			node* n=new node(data);
			n->next=temp->next;
			temp->next=n;
		}
	}

	void DeleteAtFront(){
		if(head==NULL){
			return;
		}
		else if(head->next==NULL){
			delete head;
			head=tail=NULL;
		}
		else{
			node* temp=head;
			head=head->next;
			delete temp;
		}
	}

	int length(){
		node* temp=head;
		int count=0;

		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}

	void DeleteAtEnd(){
		if(head==NULL){
			return;
		}
		else if(head->next==NULL){
			delete head;
			head=tail=NULL;
		}
		else{
			node* temp=head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			delete tail;
			temp->next=NULL;
			tail=temp;
		}
	}

	void DeleteAtMid(int pos){
		if(pos==0){
			DeleteAtFront();
		}
		else if(pos>length()){
			DeleteAtEnd();
		}
		else{
			int jump=1;
			node* temp=head;
			while(jump<=pos-1){
				temp=temp->next;
				jump++;
			}

			node* n=temp->next;
			temp->next=n->next;
			delete n;
		}
	}

	void print(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
		cout<<endl;
	}

	node* recursiveSearch(int key){
		return recursiveSearchHelper(head,key);
	}

	node* mid(){
		if(head==NULL){
			return NULL;
		}
		node* slow=head;
		node* fast=head->next;

		while(fast!=NULL){
			fast=fast->next;
			if(fast!=NULL){
				slow=slow->next;
				fast=fast->next;
			}
		}
		return slow;

	}


};


node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	node* c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
	}
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}

int main(){
	LinkedList a;
	LinkedList b;

	a.InsertAtEnd(1);
	a.InsertAtEnd(3);
	a.InsertAtEnd(5);
	a.InsertAtEnd(6);

	b.InsertAtEnd(2);
	b.InsertAtEnd(4);
	b.InsertAtEnd(7);
	b.InsertAtEnd(8);
	node* c=merge(a.head,b.head);
	while(c!=NULL){
		cout<<c->data<<"-->";
		c=c->next;
	}
	cout<<endl;


	return 0;
}