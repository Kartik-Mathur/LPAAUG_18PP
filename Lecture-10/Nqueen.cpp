// Nqueen
#include <iostream>
using namespace std;

bool canPlaceQueenHere(int board[][100],int n,int i,int j){
	for(int k=0;k<n;k++){
		if(board[i][k] || board[k][j]){
			return false;
		}
	}

	int r=i,c=j;
	while(r>=0 && c>=0){
		if(board[r][c]){
			return false;
		}
		r--;
		c--;
	}

	r=i;c=j;
	while(r>=0 && c<=n-1){
		if(board[r][c]){
			return false;
		}
		r--;
		c++;
	}
	return true;
}


bool Nqueen(int board[][100],int n,int i,int j){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	for(int j=0;j<n;j++){
		if(canPlaceQueenHere(board,n,i,j)){
			board[i][j]=1;
			bool KyaBakiBaatBani=Nqueen(board,n,i+1,j);
			if(KyaBakiBaatBani){
				return true;
			}
			board[i][j]=0;
		}
	}
	return false;

}



int main(){

	int n;
	int board[100][100]={0};
	cin>>n;
	Nqueen(board,n,0,0);

	cout<<endl;
	return 0;
}