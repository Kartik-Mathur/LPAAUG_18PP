// Prime+
#include <iostream>
using namespace std;

bool isPrime(int n){
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void GeneratePrime(int n){

	for(int i=2;i<=n;i++){
		if(isPrime(i)==true){
			cout<<i<<" "; 
		}
	}
	return;
}

int main(){
	int n;
	cin>>n;
	bool kyaPrimeHai = isPrime(n);
	// kyaPrimeHai?cout<<"Prime":cout<<"Not prime!";
	// isPrime(n)?cout<<"Prime":cout<<"Not prime!";
	// if(isPrime(n)){
	// 	cout<<"Prime";
	// }
	// else{
	// 	cout<<"Not Prime";

	// }
	GeneratePrime(n);

	return 0;
}