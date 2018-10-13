#include <iostream>
using namespace std;

void InsertionSort(int* a,int n){

	int i,j;
	for(i=1;i<n;i++){
		int card=a[i];
		for(j=i-1;j>=0 && card<a[j];j--){
			a[j+1]=a[j];
		}
		a[j+1]=card;
	}
}

void print(int* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


int main(){

	int a[]={5,4,3,2,1,0};
	int n=sizeof(a)/sizeof(int);
	print(a,n);
	InsertionSort(a,n);
	print(a,n);

	return 0;
}