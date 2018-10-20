// ReverseQueue
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void ReverseQueue(queue<int> &q){
	// base case
	if(q.empty()){
		return;
	}

	// recursive case
	int temp=q.front();
	q.pop();
	ReverseQueue(q);
	q.push(temp);
}


int main(){
	queue<int> q;

	for(int i=0;i<11;i++){
		q.push(i);
	}
	ReverseQueue(q);
	// stack <int> s;

	// while(!q.empty()){
	// 	int top=q.front();
	// 	s.push(top);
	// 	q.pop();
	// }

	// while(!s.empty()){
	// 	int top=s.top();
	// 	q.push(top);
	// 	s.pop();
	// }

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}	


	return 0;
}