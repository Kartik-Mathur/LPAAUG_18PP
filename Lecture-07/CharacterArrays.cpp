// CharacterArrays 
#include <iostream>
using namespace std;

void readLine(char *d,char delimiter='\n'){
	char ch;
	int i=0;
	ch=cin.get();
	while(ch!=delimiter){
		d[i]=ch;
		i++;
		ch=cin.get();
	}
	d[i]='\0';
}

int sum1(int a=0,int b=0,int c=0){
	return(a+b+c);
}

int length(char *d){
	int i;
	for(i=0;d[i]!='\0';i++){

	}
	return i;

}

int main(){

	char a[10]={'A','B','C','D','\0'};
	char b[8]="Welcome";
	char c[]="Hello Coding Blocks";
	char d[100];
	
	// cin>>d;
	// readLine(d);
	// cin.getline(array,sizeofarray,delimiter); 
	// cin.getline(d,100,'$'); 
	// cout<<d;
	cout<<sum1(1,2,3)<<endl;
	cout<<sum1(1,2)<<endl;
	cout<<sum1(1)<<endl;
	cout<<sum1()<<endl;
	readLine(d,'$');
	cout<<d;
	cout<<length(d)<<endl;
	cout<<endl;
	return 0;
}