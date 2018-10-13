// TimeComplexity
#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(int *a,int n){

	for(int i=0;i<=n-2;i++){
		for(int j=0;j<=n-2-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}


void merge(int*a ,int *x,int *y,int s,int e){
	int mid=(s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;

	while(i<=mid && j<=e){
		if(x[i]<y[j]){
			a[k++]=x[i++];
			// k++;
			// i++;
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
	// base case
	if(s>=e){
		return;
	}
	// Divide
	int x[10000],y[10000];
	int mid=(s+e)/2;
	for(int i=s;i<=mid;i++){
		x[i]=a[i];
	}
	for(int j=mid+1;j<=e;j++){
		y[j]=a[j];
	}

	// Sort
	MergeSort(x,s,mid);
	MergeSort(y,mid+1,e);

	// merge
	merge(a,x,y,s,e);
}

int main(){
	int a[10000];
	int n;
	cin>>n;

	for(int i=n-1;i>=0;i--){
		a[n-i-1]=i;
	}

	clock_t t;

	t=clock();
	MergeSort(a,0,n-1);
	t=clock()-t;
	cout<<"MergeSort took "<<t<<" millisecond "<<endl;

	for(int i=n-1;i>=0;i--){
		a[n-i-1]=i;
	}
	t=clock();
	BubbleSort(a,n);
	t=clock()-t;
	cout<<"BubbleSort took "<<t<<" millisecond "<<endl;

	return 0;
}