
#include <iostream>
using namespace std;

int main(){
	char ch;
	int digit=0;
	int alpha=0;
	int spaces=0;
	int other=0;

	ch=cin.get();

	while(ch!='$'){
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			alpha++;
		}
		else if(ch>='0'&&ch<='9'){
			digit++;
		}
		else if((ch==' ')||(ch=='\n')){
			spaces++;
		}
		else{
			other++;
		}

		ch=cin.get();
	}
	cout<<"Digits"<<digit<<endl;
	cout<<"alpha"<<alpha<<endl;
	cout<<"spaces"<<spaces<<endl;
	cout<<"other"<<other<<endl;








	return 0;
}