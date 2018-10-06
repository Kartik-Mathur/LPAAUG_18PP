// ElephantWays
#include <iostream>
using namespace std;

int ElephantWays(int n,int m){
	if(n==0 && m==0){
		return 1;
	}

	int ans=0;
	for(int k=1;k<=n;k++){
		ans+=ElephantWays(n-k,m);
	}

	for(int k=1;k<=m;k++){
		ans+=ElephantWays(n,m-k);
	}
	return ans;
}


int main(){

	int n,m;
	cin>>n>>m;
	cout<<ElephantWays(n,m)<<endl;

	return 0;
}