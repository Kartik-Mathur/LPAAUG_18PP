// LargestNumber
#include <iostream>
#include <climits>
using namespace std;

int main(){
	int n,key;
	int a[100];

	cout<<"Enter N : ";
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int l=a[0];

	for(int i=0;i<n;i++){
		if(l<a[i]){
			l=a[i];
		}
	}

	cout<<"LargestNumber is : "<<l<<endl;






	return 0;
}