// ReadNumAndStr
#include <iostream>
using namespace std;

int main(){
	int n;
	char a[100];

	cin>>n;
	// cin.get();
	cin.ignore();
	cin.getline(a,100);
	cout<<n<<endl;
	cout<<a<<endl;



	return 0;
}