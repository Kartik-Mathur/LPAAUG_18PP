// InbuiltSort
#include <iostream>
using namespace std;

bool compare(int a,int b){
	cout<<"compairing "<<a<< " and "<<b<<endl;
	return a<b;
}


int main(){
	int a[]={5,6,4,3,8,7,6,3,2,1};
	int n=sizeof(a)/sizeof(int);

	sort(a,a+n,compare);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	cout<<endl;
	return 0;
}