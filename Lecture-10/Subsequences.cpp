#include <iostream>
using namespace std;

void Subsequences(char *in,char *out,int i,int j){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	// Take a character first
	out[j]=in[i];
	Subsequences(in,out,i+1,j+1);
	
	// Dont take the first character
	Subsequences(in,out,i+1,j);
}


int main(){
	char a[10]="abc";
	char b[100];

	Subsequences(a,b,0,0);
	cout<<endl;

	return 0;
}