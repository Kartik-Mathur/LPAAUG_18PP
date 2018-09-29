// WavePrint
#include <iostream>
using namespace std;

int main(){
	int a[300][300];
	int r,c;
	cout<<"Enter number of rows and cols ";
	cin>>r>>c;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}

	for(int col=0;col<c;col++){
		if(col%2==0){
			for(int row=0;row<r;row++){
				cout<<a[row][col]<<" ";
			}
		}
		else{
			for(int row=r-1;row>=0;row--){
				cout<<a[row][col]<<" ";
			}
		}
	}






	return 0;
}
