// LinearSearch
#include <iostream>
using namespace std;

int main(){
	int n,key;
	cout<<"Enter N : ";
	cin>>n;

	int a[100];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<"Enter the key : ";
	cin>>key;

	int i;
	for(i=0;i<n;i++){
		if(a[i]==key){
			cout<<"Element found at index "<<i+1<<endl;
			break;
		}
	}
	if(i==n){
		cout<<"Key not found!"<<endl;
	}


	return 0;
}