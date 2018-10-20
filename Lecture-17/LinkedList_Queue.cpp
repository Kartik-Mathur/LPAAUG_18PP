// LinkedList_Queue
#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d):data(d),next(NULL){

	}
};

class queue{
	node* head;
	node* tail;
public:
	queue(){
		head=tail=NULL;
	}

	void push(int data){
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

	void pop(){
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

	int size(){
		int count=0;
		node* temp=head;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}

		return count;
	}

	bool empty(){
		return head==NULL;
	}

	int front(){
		return head->data;
	}


};


int main(){
	queue q;

	for(int i=0;i<11;i++){
		q.push(i);
	}

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}	


	return 0;
}