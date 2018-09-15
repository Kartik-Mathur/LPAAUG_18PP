#include <iostream>
using namespace std;

void func(int *x){
	*x=*x+1;
	cout<<*x<<endl;
}


int main(){

	int x=10;
	func(&x);
	cout<<x<<endl;

	return 0;
}