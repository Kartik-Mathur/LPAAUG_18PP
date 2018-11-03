// LadderProblem
#include <iostream>
using namespace std;

int ways(int n,int k=3){
	// base case
	if(n==0){
		return 1;
	}

	if(n<0){
		return 0;
	}

	int ans=0;
	for(int i=1;i<=k;i++){
		ans += ways(n-i,k);
	}
	return ans;
}

int topDown(int n,int *dp,int k=3){
	if(n==0){
		dp[n]=1;
		return dp[n];
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans += topDown(n-i,dp,k);
	}
	dp[n]=ans;
	return dp[n];
}

int bottomUp(int n,int k=3){
	int dp[1000]={0};

	dp[0]=1;

	for(int i=1;i<=n;i++){
		int ans=0;
		for(int steps=1;steps<=k;steps++){
			if(i-steps>=0){
				ans += dp[i-steps];
			}
		}
		dp[i]=ans;
	}
	return dp[n];
}

int steps(int n,int k=3){
	int dp[1000]={0};
	dp[0]=dp[1]=1;

	for(int i=2;i<=n;i++){
		if(i-1-k>=0){
			dp[i]=2*dp[i-1]-dp[i-1-k];
		}
		else{
			dp[i]=2*dp[i-1];
		}
	}
	return dp[n];
}



int main(){
	int n,k;
	cin>>n;

	int dp[1000];
	for(int i=0;i<1000;i++){
		dp[i]=-1;
	}

	cout<<topDown(n,dp,5)<<endl;
	cout<<bottomUp(n,5)<<endl;
	cout<<steps(n,5)<<endl;
	cout<<ways(n,5)<<endl;


	return 0;
}