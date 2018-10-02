// Permutations
#include <iostream>
using namespace std;

void Permutations(char *in,int i,int j){
	if(in[i]=='\0'){
		cout<<in<<endl;
		return;
	}

	for(j=i;in[j]!='\0';j++){
		swap(in[i],in[j]); 
		Permutations(in,i+1,j+1);
		swap(in[i],in[j]); 
	}


}


int main(){
	char a[10]="abc";
	Permutations(a,0,0);
	return 0;
}