#include <iostream>
using namespace std;

int main(){

	int x=10;
	// cout<<(&x)<<endl;

	int a[]={1,2,3,4};
	// cout<<a<<endl;
	// cout<<&a<<endl;
	// cout<<&a[0]<<endl;
	// cout<<&a[1]<<endl;

	char ch='A';
	cout<<(int*)&ch<<endl;



	cout<<endl;
	return 0;
}