// RunningNumbers
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

void print(priority_queue<int,vector<int>,greater<int> > h){
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}	
}


int main(){
	priority_queue<int,vector<int>,greater<int> > h;

	int k=3;
	int n;
	// cin>>k;
	int i=0;
	while(1){
		cin>>n;
		if(n==-1){
			print(h);
		}
		else if(i<k){
			h.push(n);
			i++;
		}
		else{
			if(h.top()<n){
				h.pop();
				h.push(n);
			}
		}
	}


	return 0;
}