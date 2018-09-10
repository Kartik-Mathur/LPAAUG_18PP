// Switchcase
#include <iostream>
using namespace std;


// type name(parameters1,param2,param3....){

// }

void printHello(int); // FOrward declaration 

int sqr(int n){
	int ans=n*n;

	return ans;

}

int SUM(int a,int b){
	return(a+b);
}

int main(){
	int n;
	cin>>n;
	printHello(n); // Function Invoke
	cout<<sqr(n)<<endl;
	cout<<SUM(5,20);
	return 0;
}

void printHello(int x){
		cout<<"Hello World!"<<x<<endl;
		return;
}