// BubbleSort
#include <iostream>
using namespace std;

void BubbleSort(int *,int ,int ); // forward declaration


int main(){

	int a[]={9,8,7,6,5,4,3,2,1};
	int n=sizeof(a)/sizeof(int);

	BubbleSort(a,n,0);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}

void BubbleSort(int *a,int n,int i){
	if(i==n-1){
		return;
	}

	for(int j=0;j<=n-2;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}

	BubbleSort(a,n,i+1);

}
