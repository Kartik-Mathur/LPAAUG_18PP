#include <iostream>
using namespace std;

string s[10]={" "," ","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void PhoneKeypad(char *in,int i,int j,char *out){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	
	// Recursive case
	int digit=in[i]-'0';
	for(int k=0;s[digit][k]!='\0';k++){
		out[j]=s[digit][k];
		PhoneKeypad(in,i+1,j+1,out);
	}

}


int main(){
	char in[100];
	char out[100];
	cin>>in;

	PhoneKeypad(in,0,0,out);


	return 0;
}