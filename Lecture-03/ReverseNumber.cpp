// ReverseNumber
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int rev=0;
	for(;n!=0;n=n/10){
		rev=rev*10+(n%10);
	}
	cout<<rev;
	cout<<endl;

	return 0;
}