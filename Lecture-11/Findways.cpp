 #include <iostream>
 using namespace std;

int Ways(int i,int j){
	if(i==0 && j==0){
		return 1;
	}
	if(i<0 || j<0){
		return 0;
	}

	return Ways(i-1,j)+Ways(i,j-1);
}

int Nstairs(int n){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}

	return Nstairs(n-1)+Nstairs(n-2)+Nstairs(n-3);
}

int Nstairs1(int n,int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}

	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=Nstairs1(n-i,k);
	}
	return ans;	
}

 int main(){
 	int n;
 	cin>>n;
 	// cout<<Ways(i,j)<<endl;
 	cout<<Nstairs(n)<<endl;
 	cout<<Nstairs1(n,3)<<endl;

 	return 0;
 }