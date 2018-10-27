// InbuiltHeap
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class Person{
public:
	char name[20];
	int age;
	int money;

	Person(char *name,int age,int money){
		strcpy(this->name,name);
		this->age=age;  
		this->money=money;
	}

	void print(){
		cout<<name<<endl;
		cout<<age<<endl;
		cout<<money<<endl<<endl;
	}

};

class MeraComparator{
public:
	bool operator()(Person a,Person b){
		// cout<<"Compairing "<<a<<" and "<<b<<endl;
		return a.age<b.age;
	}
};

int main(){
	priority_queue<Person,vector<Person>,MeraComparator> h;
	priority_queue<int,vector<int>,greater<int> > q;

	Person p1("XYZ",20,200);
	Person p2("ABC",10,20);
	Person p3("JKL",25,210);

	h.push(p1);
	h.push(p2);
	h.push(p3);

	while(!h.empty()){
		Person p=h.top();
		p.print();
		h.pop();
	}

	return 0;
}