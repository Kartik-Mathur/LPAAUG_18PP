// Knapsack
#include <iostream>
using namespace std;

int Knapsack(int *wts,int *price,int n,int capacity){
	if(capacity==0||n==0){
		return 0;
	}

	int inc=0,exc=0;
	if(wts[n-1]<=capacity){
		inc=price[n-1]+Knapsack(wts,price,n-1,capacity-wts[n-1]);
	}
	exc=0+Knapsack(wts,price,n-1,capacity);

	return max(inc,exc);
}

int BottomUp(int *wts,int *price,int N,int capacity){
	int dp[100][100]={0};
	for(int n=0;n<=N;n++){
		for(int w=0;w<=capacity;w++){
			int inc=0,exc=0;
			if(w==0||n==0){
				dp[n][w]=0;
			}
			else{
				if(wts[n-1]<=w){
					inc=price[n-1]+dp[n-1][w-wts[n-1]];
				}
				exc=0+dp[n-1][w];

				dp[n][w]=max(inc,exc);
			}
		}
	}
	for(int n=0;n<=N;n++){
		for(int w=0;w<=capacity;w++){
			cout<<dp[n][w]<<" ";
		}cout<<endl;
	}

	return dp[N][capacity];
}

int main(){

	int price[]={5,10,10,3};
	int wts[]={2,3,2,1};

	int capacity=4;
	int n=sizeof(price)/sizeof(int);
	cout<<BottomUp(wts,price,n,capacity)<<endl;
	cout<<Knapsack(wts,price,n,capacity)<<endl;


	return 0;
}