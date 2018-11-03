// Minways
#include <iostream>
#include <climits>
using namespace std;

int minways(int n){
	if(n==1){
		return 0;
	}

	int op1,op2,op3;
	op1=op2=op3=INT_MAX;

	op1=1+minways(n-1);
	if(n%2==0){
		op2=1+minways(n/2);
	}
	if(n%3==0){
		op3=minways(n/3)+1;
	}

	return min(op1,min(op2,op3));
}

int topDown(int n,int *dp){
	if(n==1){
		dp[n]=0;
		return dp[n];
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;

	op1=1+topDown(n-1,dp);
	if(n%2==0){
		op2=1+topDown(n/2,dp);
	}	
	if(n%3==0){
		op3=1+topDown(n/3,dp);
	}

	dp[n]=min(op1,min(op2,op3));
	return dp[n];
}

int bottomUp(int n){
	int dp[1000]={0};
	// Initilization
	dp[1]=0;
	int op1,op2,op3;

	for(int i=2;i<=n;i++){
		op1=op2=op3=INT_MAX;
		op1=1+dp[i-1];
		if(i%2==0){
			op2=1+dp[i/2];
		}
		if(i%3==0){
			op3=1+dp[i/3];
		}
		dp[i]=min(op1,min(op2,op3));
	}
	return dp[n];
}




int main(){
	int n;
	cin>>n;
	int dp[1000];
	for(int i=0;i<1000;i++){
		dp[i]=-1;
	}	
	cout<<topDown(n,dp)<<endl;
	cout<<bottomUp(n)<<endl;
	cout<<minways(n)<<endl;

	return 0;
}