// Stack_Using_Queue
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class stack{
	queue <T> q1;
	queue <T> q2;
public:

	void push(T data){
		if(!q1.empty() && q2.empty()){
			q1.push(data);
		}
		else if(q1.empty() && !q2.empty()){
			q2.push(data);
		}
		else{
			q2.push(data);
		}
	}

	void pop(){
		if(!q1.empty() && q2.empty()){
			while(q1.size()>1){
				int d=q1.front();
				q2.push(d);
				q1.pop();
			}
			q1.pop();
		}
		else if(q1.empty() && !q2.empty()){
			while(q2.size()>1){
				int d=q2.front();
				q1.push(d);
				q2.pop();
			}
			q2.pop();			
		}
	}

	T top(){
		if(!q1.empty() && q2.empty()){
			while(q1.size()>1){
				int d=q1.front();
				q2.push(d);
				q1.pop();
			}
			T data=q1.front();
			q1.pop();
			q2.push(data);
			return data;
		}
		else if(q1.empty() && !q2.empty()){
			while(q2.size()>1){
				int d=q2.front();
				q1.push(d);
				q2.pop();
			}
			T data=q2.front();
			q2.pop();		
			q1.push(data);
			return data;	
		}
	}

	bool empty(){
		return (q1.empty() && q2.empty());
	}
};


int main(){
	stack<int> s;

	for(int i=0;i<10;i++){
		s.push(i);
	}

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}


	return 0;
}