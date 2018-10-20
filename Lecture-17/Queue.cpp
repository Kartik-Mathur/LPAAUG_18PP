#include <iostream>
using namespace std;

class queue{
	int f;
	int r;
	int cs;
	int ts;
	int *arr;
public:
	queue(){
		f=0;
		ts=7;
		cs=0;
		arr=new int[ts];
		r=ts-1;
	}

	queue(int s){
		f=0;
		ts=s;
		cs=0;
		arr=new int[ts];
		r=ts-1;		
	}

	void push(int data){
		if(!full()){
			r=(r+1)%ts;
			arr[r]=data;
			cs++;
		}
	}

	void pop(){
		if(!empty()){
			f=(f+1)%ts;
			cs--;
		}
	}

	int front(){
		return arr[f];
	}

	int size(){
		return cs;
	}

	bool empty(){
		return cs==0?true:false;
	}

	bool full(){
		return cs==ts;
	}

	~queue(){
		delete []arr;
	}
};


int main(){
	queue q;

	for(int i=0;i<17;i++){
		q.push(i);
	}

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}

	return 0;
}