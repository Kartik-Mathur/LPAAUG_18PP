// LargestThree
#include <iostream>
using namespace std;


int main(){
	int a,b,c;
	int l;
	cin>>a>>b>>c;

	if(a>=b && a>=c){
		l=a;
	}
	else if(b>=a && b>=c){
		l=b;
	}
	else{
		l=c;
	}
// Updating this line
    cout<<l<<endl;


	return 0;
}
