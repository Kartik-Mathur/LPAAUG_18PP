#include <iostream>
using namespace std;

int power(int x,int n){
	if(n==0){
		return 1;
	}

	int ans=x*power(x,n-1);
	return ans;
}
char a[][10]={
	"zero","one","two","three","four","five","six","seven","eight","nine"
};
void NumToString(int n){
	if(n==0){
		return;
	}

	NumToString(n/10);
	int last_digit=n%10;
	cout<<a[last_digit]<<" ";

}

int First7(int *a,int n,int i){
	if(i==n){
		return -1;
	}

	if(a[i]==7){
		return i;
	}
 	return First7(a,n,i+1);
}

int last7(int *a,int n,int i){
	if(i==n){
		return -1;
	}

	if(a[i]==7){
		int index=i;
		int KyaAageKoiIndexHai=last7(a,n,i+1);

		if(KyaAageKoiIndexHai>index){
			return KyaAageKoiIndexHai;
		}
		else{
			return index;
		}

	}
	return last7(a,n,i+1);
}


int main(){

	int x;
	int a[]={1,2,8,6,8,7,9,5,8,7};
	int n=sizeof(a)/sizeof(int);
	// cin>>x;

	// NumToString(x);
	// cout<<endl;
	int ans=First7(a,n,0);
	if(ans==-1){
		cout<<"Not Found!"<<endl;
	}
	else{
		cout<<"Element Found at index : "<<ans<<endl;
	}



	return 0;
}