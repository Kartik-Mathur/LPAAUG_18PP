// Recursion
#include <iostream>
using namespace std;

int fact(int n){
	// base case
	if(n==0){
		return 1;
	}

	// recursive case 
	int ans=fact(n-1);

	int fn=n*ans;
	return fn;

}


int fibo(int n){
	// base case
	if(n==0 || n==1){
		return n;
	}

	// recursive case

	int ans=fibo(n-1)+fibo(n-2);
	return ans;

}




int main(){

	int n;
	cin>>n;


	cout<<fact(n)<<endl;
	cout<<fibo(n)<<endl;

	return 0;
}