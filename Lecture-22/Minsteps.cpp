#include <iostream>
using namespace std;

int ways(int i,int j){
	// base case
	if(i==0 && j==0){
		return 1;
	}
	if(i<0 || j<0){
		return 0;
	}	
	// Recursive case

	int ans=ways(i-1,j)+ways(i,j-1);
	return ans;
}

int topDown(int i,int j,int dp[][100]){
	if(i==0 && j==0){
		dp[i][j]=1;
		return dp[i][j];
	}

	if(i<0 || j<0){
		return 0;
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	int ans=topDown(i-1,j,dp)+topDown(i,j-1,dp);
	dp[i][j]=ans;
	return dp[i][j];
}

int bottomUp(int i,int j){
	int dp[100][100]={0};

	for(int k=0;k<=i;k++){
		dp[k][0]=1;
	}
	for(int k=0;k<=j;k++){
		dp[0][k]=1;
	}

	for(int k=1;k<=i;k++){
		for(int l=1;l<=j;l++){
			dp[k][l]=dp[k-1][l]+dp[k][l-1];
		}
	}
	return dp[i][j];

}

int main(){
	int dp[100][100];

	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}

	int m,n;
	cin>>m>>n;
	cout<<topDown(m,n,dp)<<endl;
	cout<<bottomUp(m,n)<<endl;
	cout<<ways(m,n)<<endl;


	return 0;
}