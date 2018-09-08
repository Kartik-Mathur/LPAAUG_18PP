// OddoneOut
#include <iostream>
using namespace std;

int main(){
	int n,no,i;
	i=10;
	int ans=0;
	cout<<"Enter n ";
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>no;
		ans=ans^no;
	}

	cout<<i<<endl;
	cout<<ans;












	cout<<endl;
	return 0;
}