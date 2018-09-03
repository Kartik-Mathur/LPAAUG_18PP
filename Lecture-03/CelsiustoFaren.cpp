// CelsiustoFaren
#include <iostream>
using namespace std;

int main(){
	int init,fval,step;
	cin>>init>>fval>>step;

	int f=init;
	int c;
	while(f<=fval){

		c=5*(f-32)/9;
		cout<<f<<" "<<c<<endl;


		f=f+step;
	}




	return 0;
}