#include <iostream>
using namespace std;

int *check(){
	int x=10;
	int *randompointer;

	randompointer=&x;
	return randompointer;
}


void printarray(int *a,int n){

	for(int i=0;i<n;i++){
		cout<<*(a+i)<<" ";
	}
	cout<<endl;
}

void reverseArray(int *a,int n){
	int i=0;
	cout<<sizeof(a)<<endl;
	int j=n-1;
	while(i<j){
		swap(*(a+i),*(a+j));
		i++;
		j--;
	}

}

int main(){

	int a[]={1,2,3,4,5};
	cout<<sizeof(a)<<endl;
	reverseArray(a,5);
	for(int i=0;i<5;i++){
		cout<<*(a+i)<<" ";
	}
	cout<<endl;
	return 0;
}