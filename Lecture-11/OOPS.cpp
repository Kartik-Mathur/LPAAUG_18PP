// OOPS
#include <iostream>
using namespace std;

// --------- BLUE PRINT ----------------
class car{
public:
	char name[20];
	int price;
	int model_no;
	int seats;

	void print(){
		cout<<"Name  : "<<name<<endl;
		cout<<"Price : "<<price<<"$"<<endl;
		cout<<"Model : "<<model_no<<endl;
		cout<<"Seats : "<<seats<<endl<<endl;
	}
};
// -------------------------------------

int main(){
	car A;
	A.price=100;
	A.seats=4;
	A.model_no=500;
	// A.name[0]='B';
	// A.name[1]='M';
	strcpy(A.name,"BMW");

	// cout<<A.price<<endl;
	// cout<<A.model_no<<endl;
	A.print();

	return 0;
}