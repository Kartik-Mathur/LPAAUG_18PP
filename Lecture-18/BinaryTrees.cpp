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

int Diameter(node* root){
	if(root==NULL){
		return 0;
	}

	int op1=Height(root->left)+Height(root->right);
	int op2=Diameter(root->left);
	int op3=Diameter(root->right);

	return max(op1,max(op2,op3));
}

class Pair{
public:
	int diameter;
	int height;
};

Pair fastDiameter(node* root){
	Pair p;
	if(root==NULL){
		p.height=p.diameter=0;
		return p;
	}

	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);

	p.height=max(left.height,right.height)+1;

	int op1=left.diameter;
	int op2=right.diameter;
	int op3=left.height+right.height;

	p.diameter=max(op1,max(op2,op3));
	return p;
}

void mirror(node* root){
	// base case
	if(root==NULL){
		return;
	}
	// Recursive case
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);

}

node* LevelOrderInput(){
	node* root=NULL;
	int data;
	cout<<"Enter root node : ";
	cin>>data;
	if(data==-1){
		return NULL;
	}
	root=new node(data);

	queue <node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		cout<<"Enter children of "<<temp->data<<" ";
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			temp->left=new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right=new node(c2);
			q.push(temp->right);
		}		
	}
	return root;
}
int indx=0;
node* makeTree(int *in,int *pre,int s,int e){
	// base case
	if(s>e){
		return NULL;
	}

	// recursive case
	int data=pre[indx];
	node* root=new node(data);
	indx++;

	int k=-1;
	for(int j=s;j<=e;j++){
		if(in[j]==data){
			k=j;
			break;
		}
	}

	root->left=makeTree(in,pre,s,k-1);
	root->right=makeTree(in,pre,k+1,e);

	return root;
}


int main(){
	int in[]={14,13,3,8,7,6,4,10,1};
	int pre[]={8,3,14,13,10,6,7,4,1};
	int n=sizeof(in)/sizeof(int);
	node* root=makeTree(in,pre,0,n-1);
	LevelOrder(root);
	cout<<endl;
	// mirror(root);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	LevelOrder(root);
	cout<<endl;
	cout<<CountNodes(root)<<endl;
	cout<<"Height :"<<Height(root)<<endl;
	cout<<"Diameter : "<<Diameter(root)<<endl;
	Pair p=fastDiameter(root);
	cout<<"Fast Diameter "<<p.diameter<<endl;
	cout<<"Height "<<p.height<<endl;

	return 0;
}