#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d):data(d),next(NULL){

	}
};


// class LinkedList{
// Here we wrote our functions...
// };

node* createLL(){
	node* head=NULL;
	int d;
	cin>>d;

	while(d!=-1){ // d==-1 will stop insertion in linked list
		node* n=new node(d);
		n->next=head;
		head=n;
		cin>>d; // Input
	}

	return head;
}

void print(node* h){  // call be value
	// To print the Linked List

	while(h!=NULL){
		cout<<h->data<<"-->";
		h=h->next;
	}
	cout<<endl;
}

int size(node* head){
	int count=0;

	while(head!=NULL){
		count++;
		head=head->next;
	}	
	return count; // Length of linked list 
}



void BubbleSort(node* &head){
	int n=size(head);

	for(int i=0;i<n-1;i++){
		node* current=head;
		node* prev=NULL;
		node* n;

		while(current!=NULL && current->next!=NULL){
			if(current->data > current->next->data){ // swap hota hai
				if(prev==NULL){ // prev==NULL
					n=current->next;
					current->next=n->next;
					n->next=current;
					head=prev=n;
				}
				else{ //prev!=NULL
					n=current->next;
					prev->next=current->next;
					current->next=n->next;
					n->next=current;
					prev=n;
				}
			}
			else{ // agar swap nahi hota
				n=current->next;
				prev=current;
				current=n;
			}
		}
	}
}


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

node* mid(node* head){
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

node* mergeSort(node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	// Divide
	node* m=mid(head);
	node* a=head;
	node* b=m->next;
	m->next=NULL;

	// Sort
	a=mergeSort(a);
	b=mergeSort(b);

	// Merge
	node* newHead=merge(a,b);
	return newHead;
}

int main(){
	node* head=createLL();
	print(head);
	head=mergeSort(head);
	print(head);

	return 0;
}