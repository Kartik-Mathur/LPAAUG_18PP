// isSorted
#include <iostream>
using namespace std;

bool isSorted(int *a,int n){
	// base case
	if(n==1){
		return true;
	}

	// recursive case
	bool kyaChotaSortedHai=isSorted(a+1,n-1);
	if(kyaChotaSortedHai && a[0]<a[1]){
		return true;
	}
	else{
		return false;
	}

}



int main(){

	int a[]={1,2,3,4,5,6,7,8,0};
	int n=sizeof(a)/sizeof(int);
	if(isSorted(a,n)){
		cout<<"Sorted"<<endl;
	}
	else{
		cout<<"Not Sorted"<<endl;
	}

	return 0;
}