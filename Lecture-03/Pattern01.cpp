// Pattern01
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i,j,val;

	for(i=1;i<=n;i++){
		if(i%2==0){
			val=0;
		}
		else{
			val=1;
		}
		
		for(j=1;j<=i;j++){
			cout<<val;
			val=1-val;
		}
		cout<<endl;
	}


	return 0;
}