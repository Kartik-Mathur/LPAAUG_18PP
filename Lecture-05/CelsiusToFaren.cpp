// CelsiusToFaren
#include <iostream>
using namespace std;
	
void printTable(int init,int fval,int step){

	int f=init;
	while(f<=fval){
		int c=5*(f-32)/9;
		cout<<f<<" "<<c<<endl;

		f+=step;
	}
	return;

}



int main(){
	int init,fval,step;
	cin>>init>>fval>>step;

	printTable(init,fval,step);

	return 0;
}