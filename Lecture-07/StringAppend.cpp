// StringAppend
#include <iostream>
using namespace std;

int length(char *d){
	int i;
	for(i=0;d[i]!='\0';i++){

	}
	return i;

}

void StringAppend(char *a,char *b){
	int i,j;
	i=length(a);

	for(j=0;b[j]!='\0';j++){
		a[i]=b[j];
		i++;
	}
	a[i]='\0';

}



int main(){
	char a[]="Hello";
	char b[]="World!";

	StringAppend(a,b);

	cout<<a<<endl;

	return 0;
}