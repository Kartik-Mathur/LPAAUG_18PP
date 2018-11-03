// WineProblem
#include <iostream>
using namespace std;

int wine(int *a,int i,int j,int day){
	if(i>j){
		return 0;
	}

	int op1=a[i]*day + wine(a,i+1,j,day+1);
	int op2=a[j]*day + wine(a,i,j-1,day+1);

	return max(op1,op2);
}

int wine1(int *a,int i,int j,int day,int dp[][100]){
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int op1=a[i]*day + wine1(a,i+1,j,day+1,dp);
	int op2=a[j]*day + wine1(a,i,j-1,day+1,dp);
	
	dp[i][j]=max(op1,op2);
	return dp[i][j];
}

int bottomUp(int *wine,int n){
	int dp[100][100]={0};
	int day=n;

	for(int i=0;i<n;i++){
		dp[i][i]=wine[i]*day;
	}
	day--;

	for(int len=2;len<=n;len++){
		int i=0;
		int endi=n-len;
		while(i<=endi){
			int j=i+len-1;
			int op1=wine[i]*day+dp[i+1][j];
			int op2=wine[j]*day+dp[i][j-1];
			dp[i][j]=max(op1,op2);
			i++;
		}
		day--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	return dp[0][n-1];
}


int main(){
	int a[]={2,3,5,1,4};
	int n=sizeof(a)/sizeof(int);

	cout<<bottomUp(a,n)<<endl;
	cout<<wine(a,0,n-1,1)<<endl;


	return 0;
}