// spiralPrint
#include <iostream>
using namespace std;

void spiralPrint(int a[][300],int r,int c){
	int sr=0,er=r-1,sc=0,ec=c-1;

	while(sr<=er && sc<=ec){
		// print starting row
		for(int i=sc;i<=ec;i++){
			cout<<a[sr][i]<<" ";
		}
		sr++;

		// print end column
		for(int j=sr;j<=er;j++){
			cout<<a[j][ec]<<" ";
		}
		ec--;

		if(sr<=er){
			// print end row
			for(int i=ec;i>=sc;i--){
				cout<<a[er][i]<<" ";
			}
			er--;
		}

		if(sc<=ec){
			// print starting column
			for(int j=er;j>=sr;j--){
				cout<<a[j][sc]<<" ";
			}
			sc++;
		}
	}



}



int main(){
	int a[300][300];
	int r,c;
	cout<<"Enter number of rows and cols ";
	cin>>r>>c;
	int val=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][j]=val;
			val++;
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	spiralPrint(a,r,c);

	cout<<endl;
	return 0;
}
