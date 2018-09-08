// Arrays
#include <iostream>
using namespace std;


int main(){

	int a[100]; // initialize every element to zero
	int n;
	cin>>n; // less than 100


	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=0;i--){
		cout<<a[i]<<" ";
	}

	cout<<endl;




	return 0;
}