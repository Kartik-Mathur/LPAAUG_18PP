#include <iostream>
using namespace std;

void func(int *x){
	*x=*x+1;
	cout<<*x<<endl;
}


int main(){

	int a=10;
	func(&a);
	cout<<a<<endl;

	return 0;
}