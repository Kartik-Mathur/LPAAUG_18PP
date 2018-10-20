#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d):data(d),left(NULL),right(NULL){

	}
};


node* createTree(){
	// node* root=NULL;

	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	else{
		node* root=new node(d);
		root->left=createTree();
		root->right=createTree();
		return root;
	}
}

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

int CountNodes(node* root){
	if(root==NULL){
		return 0;
	}

	return 1+CountNodes(root->left)+CountNodes(root->right);
}

int Height(node* root){
	if(root==NULL){
		return 0;
	}

	int left=Height(root->left);
	int right=Height(root->right);
	return 1+(max(left,right));
}

int main(){

	node* root=createTree();
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	LevelOrder(root);
	cout<<endl;
	cout<<CountNodes(root)<<endl;
	cout<<Height(root)<<endl;

	return 0;
}