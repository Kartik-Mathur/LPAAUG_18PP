#include <iostream>
#include <climits>
using namespace std;

int ways(int *coins,int n,int amount){
	if(amount==0){
		return 0;
	}

	// Recursive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(amount-coins[i]>=0){
			int smallerans=ways(coins,n,amount-coins[i]);
			ans=min(smallerans+1,ans);
		}
	}
	return ans;
}

int BottomUp(int *coins,int n,int amount){
	int dp[1000];
	for(int i=0;i<1000;i++){
		dp[i]=INT_MAX;
	}

	dp[0]=0;

	for(int rupay=1;rupay<=amount;rupay++){

		for(int i=0;i<n;i++){
			if(rupay-coins[i]>=0){
				dp[rupay]=min(dp[rupay],dp[rupay-coins[i]]+1);
			}
		}
	}
	return dp[amount];
}

int main(){
	int coins[]={1,7,10};
	int n=sizeof(coins)/sizeof(int);

	int amount;
	cin>>amount;
	cout<<BottomUp(coins,n,amount)<<endl;
	cout<<ways(coins,n,amount)<<endl;


	return 0;
}