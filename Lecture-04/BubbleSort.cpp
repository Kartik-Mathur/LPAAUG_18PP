// BubbleSort

#include <iostream>
using namespace std;

int main(){
	int n;
	int a[100];
	cout<<"Enter n ";
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<=n-2;i++){
		for(int j=0;j<=n-2-i;j++){
			if(a[j+1]<a[j]){
				swap(a[j+1],a[j]);
			}
		}

	}


	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}