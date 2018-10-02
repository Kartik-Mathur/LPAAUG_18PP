// Strings
#include <iostream>
using namespace std;

int main(){
	char a[]="ABC DEF";
	string s[10]={
		"Hello","World","COding","Blocks"
	}; // array of strings
	cout<<s[0][2]<<endl;
	for(int i=0;s[0][i]!='\0';i++){
		cout<<s[0][i];
	}
	cout<<endl;
	string k;
	for(int i=0;i<3;i++){
		// cin>>s[i];
		getline(cin,s[i]);

	}
	for(int i=0;i<3;i++){
		cout<<s[i]<<endl;
	}
	k=s[0];
	cout<<k<<endl;
	// string s("Hello COding Blocks!");
	// string s1(a);
	// cin>>s;
	// getline(cin,s);
	// cout<<s<<endl;
	// cout<<s1<<endl;



	return 0;
}