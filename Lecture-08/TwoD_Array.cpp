// TwoD_Array
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
	int key;
	cout<<"Enter a key ";
	cin>>key;
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]==key){
				cout<<"Key found at "<<i<<","<<j<<endl;
				break;
			}
		}
		if(j!=c){
			break;
		}
	}

	// cout<<a<<endl;
	// cout<<a+1<<endl;

	char b[][4]={
		{'A','B','C','\0'},
		{'D','E','F','\0'},
		{'G','H','I','\0'}
	};

	// char c[][4]={
	// 	"ABC",
	// 	"DEF",
	// 	"GHI"
	// };

	// cout<<c[0]<<endl;
	// cout<<c[1]<<endl;
	// cout<<c[2]<<endl;






	return 0;
}