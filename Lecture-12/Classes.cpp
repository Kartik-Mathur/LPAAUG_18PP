// OOPS
#include <iostream>
using namespace std;

// --------- BLUE PRINT ----------------
class car{
private:
	int seats;
public:
	// const int tyres; // To be initialized where ever object is created
	char *name;
	int price;
	int model_no;
	static int count;
	car(){
		name=NULL;
		cout<<"I am in Constructor"<<endl;
		count++;
	}
	// Parameterized constructor
	car(char *n,int p,int m,int s){
		cout<<"I am in Parameterized Constructor"<<endl;
		name=new char[strlen(n)+1];
		strcpy(name,n);
		price=p;
		model_no=m;
		seats=s;
		count++;
	}

	car(int p,int m,int s):price(p),seats(s),model_no(m){
		count++;

	}

	car(char *n,int p,int m){
		cout<<"In Constructor 2"<<endl;
		name=new char[strlen(n)+1];
		strcpy(name,n);
		price=p;
		model_no=m;
		count++;
	}


	void print(){
		cout<<"Name  : "<<name<<endl;
		cout<<"Price : "<<price<<"$"<<endl;
		cout<<"Model : "<<model_no<<endl;
		cout<<"Seats : "<<seats<<endl<<endl;
	}

	void SetValues(char *n,int p,int m,int s){
		if(name!=NULL){
			delete []name;
		}
		name=new char[strlen(n)+1];
		strcpy(name,n);
		price=p;
		model_no=m;
		seats=s;
	}

	void SetSeats(int s){
		if(s>=2 && s<=12){
			seats=s;
		}
		else{
			seats=4;
		}
	}

	int getSeats(){
		return seats;
	}

	 // Copy Constructor
	car(car &X){
		price=X.price;
		seats=X.seats;
		model_no=X.model_no;
		name=new char[strlen(X.name)+1];
		strcpy(name,X.name);
		count++;
		// name=X.name;
	}

	void SetName(char *n){
		if(name!=NULL){
			delete []name;
		}
		name=new char[strlen(n)+1];
		strcpy(name,n);
	}

	void operator=(car X){
		price=X.price;
		seats=X.seats;
		model_no=X.model_no;
		name=new char [strlen(X.name)+1];
		strcpy(name,X.name);
	}

	void operator+=(car X){
		price+=X.price;
		seats+=X.seats;
		model_no+=X.model_no;
		char * oldName=name;
		int l1=strlen(name);
		int l2=strlen(X.name);

		name=new char[l1+l2+1];
		strcpy(name,oldName);
		for(int i=0;i<=l2;i++){
			name[l1+i]=X.name[i];
		}
		delete []oldName;
	}

	car* operator+(car X){
		car *newCar=new car;
		// newCar=new car
		(*newCar).price=price+X.price;
		(*newCar).seats=seats+X.seats;
		(*newCar).model_no=model_no+X.model_no;

		int l1=strlen(name);
		int l2=strlen(X.name);
		(*newCar).name=new char[l1+l2+1];
		strcpy((*newCar).name,name);

		for(int i=0;i<=l2;i++){
			(*newCar).name[i+l1]=X.name[i];
		}

		return newCar;
	}

	~car(){
		// cout<<"Deleting car "<<name<<endl;
		count--;
	}
};
// -------------------------------------

int car::count=0;


int main(){
	car A;
	A.price=100;
	// A.seats=4;
	A.SetSeats(5);
	A.model_no=500;
	char z[100];
	// cout<<"Enter name for car c : ";
	// cin>>z;
	// strcpy(A.name,"BMW"); 
	A.SetName("BMW");

	car B;
	B.SetValues("Audi",400,100,2);
	// cout<<A.seats<<endl;
	car C("Hyundai",500,900,7);
	// car D=A;
	// car E=D; //Copy Constructor
	//car E(A); // Copy Constructor
	// cout<<A.getSeats()<<endl;
	car D;
	D=A;
	A+=B;
	car* E=A+B;
	car F(100,100,100);
	F.SetName("XYZ");
	// A.name[0]='W';
	A.print();
	B.print();
	C.print();
	D.print();
	(*E).print();
	F.print();
	delete E;
	cout<<A.count<<endl;
	return 0;
}
