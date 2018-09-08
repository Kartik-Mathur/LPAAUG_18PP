// SelectionSort
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

		int smallest=i;
		for(int j=i+1;j<n;j++){
			if(a[smallest]>a[j]){
				smallest=j;
			}
		}
		if(smallest!=i){
			swap(a[smallest],a[i]);
		}
	}


	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}