// Permutations
#include <iostream>
using namespace std;

int main(){
	char a[]="abbcaz";
	int freq[26]={0};

	for(int i=0;a[i]!='\0';i++){
		int index=a[i]-'a';
		freq[index]++;
	}
	for(int i=0;i<26;i++){
		cout<<freq[i]<<" ";
	}

	cout<<endl;
	return 0;
}