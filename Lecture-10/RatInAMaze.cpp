// RatInAMaze
#include <iostream>
using namespace std;

bool RatInAMaze(char maze[][5],int sol[][10],int i,int j,int n,int m){
	if(i==n-1 && j==m-1){
		sol[i][j]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	sol[i][j]=1;
	// check kya right mei move kr skte hai
	if(j+1<m && maze[i][j+1]!='X'){
		bool KyaRightSeRastaMilla=RatInAMaze(maze,sol,i,j+1,n,m);
		if(KyaRightSeRastaMilla){
			return true;
		}
	}

	// check downwards
	if(i+1<n && maze[i+1][j]!='X'){
		bool KyaNeecheSeBaatBani=RatInAMaze(maze,sol,i+1,j,n,m);
		if(KyaNeecheSeBaatBani){
			return true;
		}
	}

	sol[i][j]=0;
	return false;

}


int main(){
	char maze[][5]={
		"OOOO",
		"OOXX",
		"OOOO",
		"XXOO"
	};

	int sol[10][10]={0};
	RatInAMaze(maze,sol,0,0,4,4);

	return 0;
}