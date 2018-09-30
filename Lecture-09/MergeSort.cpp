// MergeSort
#include <iostream>
using namespace std;
void merge(int *a,int *x,int *y,int s,int e){
	int mid=(s+e)/2;
	int i=s,j=mid+1,k=s;
	while(i<=mid && j<=e){
		if(x[i]<y[j]){
			a[k]=x[i];
			k++;
			i++;
		}
		else{
			a[k++]=y[j++];

		}
	}
	while(i<=mid){
		a[k++]=x[i++];
	}
	while(j<=e){
		a[k++]=y[j++];
	}

}


void MergeSort(int *a,int s,int e){
	if(s>=e){
		return;
	}

	// Divide
	int mid=(s+e)/2;
	int x[100],y[100];
	for(int i=s;i<=mid;i++){
		x[i]=a[i];
	}
	for(int i=mid+1;i<=e;i++){
		y[i]=a[i];
	}

	// Sort
	MergeSort(x,s,mid);
	MergeSort(y,mid+1,e);

	// Merge
	merge(a,x,y,s,e);
}

int main(){
	int a[]={9,8,7,6,5,4,3,2,1};
	int n=sizeof(a)/sizeof(int);

	MergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;

	return 0;
}