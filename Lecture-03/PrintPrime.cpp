// PrintPrime
#include <iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	int i;
	int j;
	cout<<"2";

	for(i=3;i<=n;i++){

		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}
		}
		if(i==j){
			cout<<", "<<i;
		}

	}
	cout<<endl;











	return 0;
}