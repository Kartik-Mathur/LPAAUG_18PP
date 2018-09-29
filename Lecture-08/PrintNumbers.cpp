// PrintNumbers
#include <iostream>
using namespace std;

void print(int*a ,int n){
	if(n==0){
		return;
	}

	print(a+1,n-1);
	cout<<a[0]<<" ";


}

int main(){

	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);


	print(a,n);
	cout<<endl;

	return 0;
}