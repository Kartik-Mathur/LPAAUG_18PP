// Vectors
#include <iostream>
// #include <vector>
using namespace std;

class Vector{
	int cs;
	int ts;
	int *arr;
public:
	Vector(){
		cs=0;
		ts=4;
		arr=new int[ts];
	}
	Vector(int s){
		cs=0;
		ts=s;
		arr=new int[ts];
	}

	void push_back(int data){
		if(cs==ts){
			int* oldarr=arr;
			int oldts=ts;

			ts=2*ts;
			arr=new int[ts];

			for(int i=0;i<oldts;i++){
				arr[i]=oldarr[i];
			}
			delete []oldarr;
		}
		arr[cs]=data;
		cs++;
	}

	void pop_back(){
		if(cs>0){
			cs--;
		}
	}

	int size(){
		return cs;
	}

	bool empty(){
		return cs==0?true:false;
	}

	int capacity(){
		return ts;
	}

	int operator[](int i){
		return arr[i];
	}
};

int main(){
	Vector v;

	for(int i=0;i<15;i++){
		v.push_back(i);
	}
	// v.pop_back();
	// v.pop_back();
	// v.pop_back();
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}cout<<endl;

	cout<<v.size()<<endl;
	cout<<v.capacity()<<endl;
	return 0;
}