// callbyvalue
#include <iostream>
using namespace std;

void myswap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
	cout<<"In Myswap a: "<<a<<" b: "<<b<<endl; // 20 10
	return;
}


int main(){
	int a=10,b=20;

	myswap(a,b);
	cout<<"In main a: "<<a<<" b: "<<b<<endl;// 10 20



	return 0;
}