// BinarySearchTree
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d):data(d),left(NULL),right(NULL){

	}
};


void preorder(node* root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root){
	if(root==NULL){
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node* root){
	if(root==NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void LevelOrder(node* root){

	queue <node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}

			if(temp->right){
				q.push(temp->right);
			}
		}
	}

}

node* InsertInBST(node* root,int data){
	if(root==NULL){
		node* n=new node(data);
		return n;
	}

	if(root->data>=data){
		root->left=InsertInBST(root->left,data);
	}
	else{
		root->right=InsertInBST(root->right,data);
	}

	return root;
}


node* createTree(){
	node* root=NULL;
	int data;
	cin>>data;
	while(data!=-1){ 
		root=InsertInBST(root,data);
		cin>>data;
	}

	return root;
}

node* search(node* root,int key){
	if(root==NULL){
		return NULL;
	}

	if(root->data==key){
		return root;
	}
	else if(root->data>key){
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}

}

node* ArrayToTree(int *a,int s,int e){
	// base case
	if(s>e){
		return NULL;
	}

	// recursive case
	int mid=(s+e)/2;
	int data=a[mid];
	node* root=new node(data);
	root->left=ArrayToTree(a,s,mid-1);
	root->right=ArrayToTree(a,mid+1,e);

	return root;
}

class linkedlist{
public:
	node* head;
	node* tail;
};

linkedlist TreeToLL(node* root){
	linkedlist l;
	if(root==NULL){
		l.head=l.tail=NULL;
		return l;
	}

	if(root->right==NULL && root->left!=NULL){
		linkedlist left=TreeToLL(root->left);
		left.tail->right=root;
		l.head=left.head;
		l.tail=root;
	}
	else if(root->left==NULL && root->right!=NULL){
		linkedlist right=TreeToLL(root->right);
		root->right=right.head;
		l.head=root;
		l.tail=right.tail;
	}
	else if(root->left==NULL && root->right==NULL){
		l.head=l.tail=root;
	}
	else{
		linkedlist left=TreeToLL(root->left);
		linkedlist right=TreeToLL(root->right);
		left.tail->right=root;
		root->right=right.head;
		l.head=left.head;
		l.tail=right.tail;
	}
	return l;
}

void printLL(linkedlist l){
	node* temp=l.head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp=temp->right;
	}
	cout<<endl;
}


int main(){
	int a[]={1,4,6,8,10,15,20,22};
	int n=sizeof(a)/sizeof(int);
	node* root=ArrayToTree(a,0,n-1);
	LevelOrder(root);
	linkedlist l=TreeToLL(root);
	printLL(l);




	return 0;
}