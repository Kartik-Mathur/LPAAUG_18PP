// Cost_Min
#include <iostream>
using namespace std;

int mincost(int cost[][10],int i,int j){
	if(i==0 && j==0){
		return cost[i][j];
	}

	if(i==0 && j>0){
		return mincost(cost,i,j-1)+cost[i][j];
	}
	else if(i>0 && j==0){
		return mincost(cost,i-1,j)+cost[i][j];
	}
	else{
		int ans=min(mincost(cost,i-1,j),mincost(cost,i,j-1))+cost[i][j];
		return ans;
	}
}

int mincost1(int cost[][10],int i,int j,int dp[][100]){
	if(i==0 && j==0){
		dp[i][j]=cost[i][j];
		return dp[i][j];
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	if(i==0 && j>0){
		dp[i][j]=mincost1(cost,i,j-1,dp)+cost[i][j];
		return dp[i][j];
	}
	else if(i>0 && j==0){
		dp[i][j]=mincost1(cost,i-1,j,dp)+cost[i][j];
		return dp[i][j];
	}
	else{
		int ans=min(mincost1(cost,i-1,j,dp),mincost1(cost,i,j-1,dp))+cost[i][j];
		dp[i][j]=ans;
		return ans;
	}
}

int bottomUp(int cost[][10],int i,int j){
	int dp[100][100]={0};

	for(int k=0;k<=i;k++){
		for(int l=0;l<=j;l++){
			if(k==0 && l==0){
				dp[k][l]=cost[k][l];
			}
			else if(k==0 && l>0){
				dp[k][l]=cost[k][l]+dp[k][l-1];
			}
			else if(k>0 && l==0){
				dp[k][l]=cost[k][l]+dp[k-1][l];
			}
			else{
				dp[k][l]=min(dp[k-1][l],dp[k][l-1])+cost[k][l];
			}
		}
	}
	return dp[i][j];
}





int main(){
	int cost[][10]={
		{1,4,3,2},
		{5,6,8,10},
		{3,2,1,4}
	};
	int i,j;
	cin>>i>>j;
	cout<<bottomUp(cost,i,j)<<endl;
	cout<<mincost(cost,i,j)<<endl;


	return 0;
}