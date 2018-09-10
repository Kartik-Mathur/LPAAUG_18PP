// TertiaryOperator
#include <iostream>
using namespace std;

int main(){
	int a=10;
	// (condition)?(work:true):(work:false);
	(a>0)?cout<<"+ve":cout<<"-ve";

	bool isEven=(a%2==0)?true:false;
	cout<<isEven<<endl;


	return 0;
}