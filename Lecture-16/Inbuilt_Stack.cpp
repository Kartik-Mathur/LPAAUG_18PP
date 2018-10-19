// Inbuilt_Stack
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(char *a){
	stack<char> s;

	for(int i=0;a[i]!='\0';i++){
		char ch=a[i];

		switch(ch){
			case '{':
			case '[':
			case '(': s.push(ch);
						break;
			case '}':
					if(!s.empty() && s.top()=='{'){
						s.pop();
					}		
					else{
						return false;
					}
					break;
			case ']':
					if(!s.empty() && s.top()=='['){
						s.pop();
					}		
					else{
						return false;
					}
					break;
			case ')':
					if(!s.empty() && s.top()=='('){
						s.pop();
					}		
					else{
						return false;
					}	
					break;									
		}
	}

	return s.empty();

}

int main(){
	stack <char> s;
	// s.push() // s.pop() // s.top() // s.empty()
	char a[]="{a+(b+c)+[d+e]}";

	if(isBalanced(a)){
		cout<<"Balanced "<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}


	return 0;
}