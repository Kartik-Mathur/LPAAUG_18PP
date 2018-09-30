// MultiplyTwoNum
#include <iostream>
using namespace std;

int Multiply(int a,int b){
	if(b==0){
		return 0;
	}

	int ans=a+Multiply(a,b-1);
	return ans;
}



int main(){
	int a,b;
	cin>>a>>b;
	cout<<Multiply(a,b)<<endl;

	return 0;
}
