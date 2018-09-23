// Pallindrome
#include <iostream>
using namespace std;

int length(char *d){
	int i;
	for(i=0;d[i]!='\0';i++){

	}
	return i;

}

bool isPallindrome(char*a){
	int i=0;
	int len=length(a);
	int j=len-1;

	while(i<j){
		if(a[i]==a[j]){
			i++;
			j--;
		}
		else{
			return false;
		}
	}

	return true;
}


int main(){

	char a[100];
	cin.getline(a,100);
	if(isPallindrome(a)==true){
		cout<<"Pallindrome";
	}
	else{
		cout<<"Not a Pallindrome";
	}

	cout<<endl;
	return 0;
}