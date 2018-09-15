// Pointers
#include <iostream>
using namespace std;

int main(){
	int x=10;
	int *xptr='\0';

	cout<<*xptr<<endl;

	char ch='D';
	char *xch;
	xch=&ch;

	// cout<<&ch<<endl;
	// cout<<&ch+1<<endl;
	// cout<<(int*)xch<<endl;
	// cout<<(int*)xch+1<<endl;
	// cout<<xch+1<<endl;
	// xptr=&x;

	// cout<<&x<<endl;
	// cout<<&x+1<<endl;
	// cout<<xptr<<endl;
	// cout<<xptr+1<<endl;
	// cout<<&xptr<<endl;

	return 0;
}