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

bool isBST(node* root,int min=INT_MIN,int max=INT_MAX){
	if(root==NULL){
		return true;
	}

	if(root->data>=min && root->data<=max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
		return true;
	}
	else{
		return false;
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

class Pair{
public:
	int height;
	bool balance;
};

Pair Balanced(node* root){
	Pair p;
	if(root==NULL){
		p.height=0;
		p.balance=true;
		return p;
	}

	Pair left=Balanced(root->left);
	Pair right=Balanced(root->right);

	p.height=max(left.height,right.height)+1;

	if(left.balance && right.balance && abs(left.height-right.height)<=1){
		p.balance=true;
	}
	else{
		p.balance=false;
	}
	return p;
}


int main(){
	int a[]={1,4,6,8,10,15,20,22};
	int n=sizeof(a)/sizeof(int);
	node* root=createTree();
	LevelOrder(root);
	// cout<<endl;
	// preorder(root);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl;
	// node* s=search(root,17);
	Pair p=Balanced(root);

	bool ans=isBST(root);
	if(p.balance){
		cout<<"Balanced and Height "<<p.height<<endl;
	}
	else{
		cout<<"Not Balanced and Height "<<p.height<<endl;
		
	}


	return 0;
}