#include <iostream>
using namespace std;

int Elephant(int i,int j){
	int dp[100][100]={0};

	dp[0][0]=1;
	int val=1;
	for(int k=1;k<=i;k++){
		dp[k][0]=val;
		val *= 2;
	}
	val=1;
	for(int k=1;k<=j;k++){
		dp[0][k]=val;
		val*=2;
	}

	for(int k=1;k<=i;k++){
		for(int l=1;l<=j;l++){
			int ans=0;
			for(int m=0;m<k;m++){
				ans += dp[m][l];
			}
			for(int m=0;m<l;m++){
				ans += dp[k][m];
			}
			dp[k][l]=ans;
		}
	}
	for(int k=0;k<=i;k++){
		for(int l=0;l<=j;l++){
			cout<<dp[k][l]<<" ";
		}cout<<endl;
	}
	return dp[i][j];
}


int main(){
	int i;int j;
	cin>>i>>j;
	cout<<Elephant(i,j)<<endl;
	return 0;
}