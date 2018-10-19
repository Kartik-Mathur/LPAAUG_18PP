#include <iostream>
#include "Stack.h"
using namespace std;

class book{
	char name[20];
	int price;
public:
	book(char * n,int p){
		strcpy(name,n);
		price=p;
	}

	void print(){
		cout<<"Name  : "<<name<<endl;
		cout<<"Price : "<<price<<endl<<endl;
	}

	friend ostream& operator<<(ostream&os,book b);
};

ostream& operator<<(ostream&os,book b){
	cout<<b.name<<endl;
	cout<<b.price<<endl<<endl;
	return os;
}


void print(stack<book> s){
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
int main(){
	stack <book>s;
	book b1("C++",100);
	book b2("Java",200);


	s.push(b1);
	s.push(b2);

	print(s);

	return 0;
}