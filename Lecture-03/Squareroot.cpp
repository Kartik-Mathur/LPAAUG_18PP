// Squareroot
#include <iostream>
using namespace std;

int main(){
	int n,precision;
	cin>>n>>precision;

	float inc=1;
	float i=0;

	int current_precision=0;

	while(current_precision<=precision){
		while(i*i<=n){
			i=i+inc;
		}
		i=i-inc;
		inc=inc/10;
		current_precision=current_precision+1;
	}
	cout<<i<<endl;








	return 0;
}