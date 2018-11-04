// LCS.cpp
#include <iostream>
using namespace std;

int LCS(char *a,char *b){
	int dp[100][100]={0};

	int m=strlen(a);
	int n=strlen(b);

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else{
				if(a[i-1]==b[j-1]){
					dp[i][j]=1+dp[i-1][j-1];
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
	}
	// for(int i=0;i<=m;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }


	return dp[m][n];

}


int main(){
	char b[]="cbc";
	char a[]="acdbc";

	cout<<LCS(a,b)<<endl;


	return 0;
}