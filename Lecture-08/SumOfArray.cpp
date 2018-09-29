// SumOfArray
#include <iostream>
using namespace std;

int SumOfArray(int *a,int n){
	if(n==0){
		return 0;
	}

	int ans=a[0]+SumOfArray(a+1,n-1);
	return ans;
}

int sum1(int *a,int n){
	if(n==0){
		return 0;
	}

	int ans=a[n-1]+sum1(a,n-1);
	return ans;
}

int sum2(int *a,int n,int i){
	if(i==n){
		return 0;
	}

	int ans=a[i]+sum2(a,n,i+1);
	return ans;
}




int main(){

	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);

	cout<<SumOfArray(a,n)<<endl;
	cout<<sum1(a,n)<<endl;
	cout<<sum2(a,n,0)<<endl;
	return 0;
}