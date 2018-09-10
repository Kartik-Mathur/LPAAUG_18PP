// ArraysTofun
#include <iostream>
using namespace std;

void print(int a[],int n){
	for(int i=0;i<n;i++){
		a[i]=20;
		// cout<<a[i]<<" ";
	}
	return;
}


int main(){
	int a[100];
	int n=5;

	for(int i=0;i<n;i++){
		a[i]=i;
	}
	print(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}	


	return 0;
} 