#include <iostream>
#include <unordered_map>
using namespace std;

class node{
public:
	char ch;
	bool isTerimal;
	unordered_map<char,node*> h;

	node(char d){
		ch=d;
		isTerimal=false;
	}
};


class Trie{
	node* root;
public:
	Trie(){
		root=new node('\0');
	}

	void addWord(char *word){
		node* temp=root;
		for(int i=0;word[i]!='\0';i++){
			char ch=word[i];

			if(temp->h.count(ch)==0){
				node * child=new node(ch);
				temp->h[ch]=child;
				temp=child;
			}
			else{
				temp=temp->h[ch];
			}
		}
		temp->isTerimal=true;
	}

	bool search(char *word){

		node* temp=root;
		for(int i=0;word[i]!='\0';i++){
			char ch=word[i];

			if(temp->h.count(ch)){
				temp=temp->h[ch];
			}
			else{
				return false;
			}
		}
		return temp->isTerimal;
	}

};


int main(){

	Trie t;

	t.addWord("no");
	t.addWord("not");
	t.addWord("noway");
	t.addWord("abc");
	t.addWord("ab");
	char f[100];

	while(1){
		cin>>f;

		if(t.search(f)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

	}


	return 0;
}