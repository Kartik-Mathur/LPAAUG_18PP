#include <iostream>
using namespace std;

int* createArray(int n){
	int *a=new int[n];
	for(int i=0;i<n;i++){
		a[i]=i;
	}
	return a;
}



int main(){
	int n;
	// int *x=new int;
	// *x=10;
	// cout<<*x<<endl;
	// cin>>n;
	// int *b=createArray(n);
	// for(int i=0;i<n;i++){
	// 	cout<<b[i]<<" ";
	// }
	// delete []b;
	// cout<<endl;
	int r,c;
	int **a;
	cin>>r>>c;
	a=new int*[r];

	for(int i=0;i<r;i++){
		a[i]=new int[c];
	}
	int val=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][j]=val;
			val++;
		}
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}

	for(int i=0;i<r;i++){
		delete []a[i];
	}

	delete []a;

	return 0;
		
}