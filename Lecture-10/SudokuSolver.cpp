// SudokuSOlver
#include <iostream>
#include <cmath>
using namespace std;


bool isSafeToPutHere(int mat[][9],int n,int i,int j,int number){
	for(int k=0;k<n;k++){
		if(mat[i][k]==number || mat[k][j]==number){
			return false;
		}
	}

	n=sqrt(n);
	int starti=(i/n)*n;
	int startj=(j/n)*n;

	for(int k=starti;k<starti+n;k++){
		for(int l=startj;l<startj+n;l++){
			if(mat[k][l]==number){
				return false;
			}
		}
	}
	return true;

}



bool sudokuSolver(int mat[][9],int n,int i,int j){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	if(j==n){
		return sudokuSolver(mat,n,i+1,0);
	}

	if(mat[i][j]!=0){
		return sudokuSolver(mat,n,i,j+1);
	}


	for(int number=1;number<=n;number++){
		if(isSafeToPutHere(mat,n,i,j,number)){
			mat[i][j]=number;
			bool KyaBakiRakhPaye=sudokuSolver(mat,n,i,j+1);
			if(KyaBakiRakhPaye){
				return true;
			}
			mat[i][j]=0;
		}
	}
	return false;
}



int main(){
	int mat[9][9] =
		{{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};

		sudokuSolver(mat,9,0,0);
		cout<<endl;

	return 0;
}