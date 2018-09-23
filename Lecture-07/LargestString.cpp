// LargestString
#include <iostream>
using namespace std;

int length(char *d){
	int i;
	for(i=0;d[i]!='\0';i++){

	}
	return i;

}

void copyString(char *a,char *b){
	int i;
	for(i=0;b[i]!='\0';i++){
		a[i]=b[i];
	}

	a[i]='\0';
}



int main(){
	int n,large=0;
	char largest[100];
	char temp[100];

	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cin.getline(temp,100);
		int templen=length(temp);
		// if templen is greater than large
		// then update the largest string 
		if(templen>large){
			large=templen;
			copyString(largest,temp);
		}

	}
	cout<<largest;
	cout<<endl;
	return 0;
}



