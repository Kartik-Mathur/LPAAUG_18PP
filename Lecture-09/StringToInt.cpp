#include <iostream>
using namespace std;

int StringToInt(char *a,int n){
	// base case
		if(n==0){
			return 0;
		}

	// recursive case
		int last_digit=a[n-1]-'0';
		int ans=StringToInt(a,n-1)*10+last_digit;
		return ans;

}


int main(){

	char a[]="1234";
	int x=a[0];

	int ans=StringToInt(a,4);
	cout<<ans<<endl;
	return 0;
}