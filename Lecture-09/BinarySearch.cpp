// BinarySearch
#include <iostream>
using namespace std;

int BinarySearch(int *a,int n,int key){
	int s=0;
	int e=n-1;
	int mid;
	while(s<=e){

		mid=(s+e)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}

	}
	return -1;
}

int Binary(int *a,int s,int e,int key){
	if(s>e){
		return -1;
	}

	int mid=(s+e)/2;
	if(a[mid]==key){
		return mid;
	}
	else if(a[mid]>key){
		e=mid-1;
	}
	else{
		s=mid+1;
	}
	return Binary(a,s,e,key);

}



int main(){

	int a[]={1,2,4,5,7,8,9};
	int n=sizeof(a)/sizeof(int);
	int key;
	cin>>key;
	cout<<Binary(a,0,n-1,key);
	cout<<endl;
	return 0;
}