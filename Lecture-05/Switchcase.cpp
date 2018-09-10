// Switchcase
#include <iostream>
using namespace std;

int main(){
	char ch;

	cin>>ch;
	int i=0;
	switch(ch){
		case 'n':
		case 'N': cout<<"North"<<endl;
					break;
		case 'e':
		case 'E': cout<<"East"<<endl;
					break;
		case 'S': cout<<"South"<<endl;
					i++;
					break;
		default : cout<<"invalid"<<endl;			
	}














	return 0;
}