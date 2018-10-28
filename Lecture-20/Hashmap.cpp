#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string k,T val){
		key=k;
		value=val;
		next=NULL;
	}

	~node(){
		if(next!=NULL){
			delete next;
			next=NULL;
		}
	}

};

template <typename T>
class hashmap{
	node<T>** Bucket;
	int cs;
	int ts;

	int hashFn(string key){
		int ans=0;
		int p=1;

		for(int i=0;i<key.size();i++){
			ans += key[i]*p;
			p *= 17;
			p %= ts;
			ans %= ts;
		}

		return ans;
	}

	void rehash(){
		node<T>** oldBucket=Bucket;
		int oldts=ts;

		cs=0;
		ts=2*ts;
		Bucket=new node<T>*[ts];

		for(int i=0;i<ts;i++){
			Bucket[i]=NULL;
		}		

		for(int i=0;i<oldts;i++){
			node<T>* temp=oldBucket[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			if(oldBucket[i]!=NULL){
				delete oldBucket[i];
			}
		}
		delete []oldBucket;
	}

public:

	hashmap(int ms=7){
		cs=0;
		ts=ms;
		Bucket=new node<T>*[ts];

		for(int i=0;i<ts;i++){
			Bucket[i]=NULL;
		}
	}

	void insert(string key,T value){
		int i=hashFn(key);

		node<T>* n=new node<T>(key,value);
		
		n->next=Bucket[i];
		Bucket[i]=n;
		cs++;


		float load_factor=cs/(1.0*ts);
		if(load_factor>0.7){
			rehash();
		}
	}

	T* search(string key){
		int i=hashFn(key);
		node<T>* temp=Bucket[i];

		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp=temp->next;
		}
		return NULL;
	}

	T& operator[](string key){
		T* temp=search(key);
		if(temp==NULL){
			T garbage;
			insert(key,garbage);
			temp=search(key);
			return *temp;
		}
		else{
			return *temp;
		}
	}

	void erase(string key){
		int i=hashFn(key);
		node<T>*temp=Bucket[i];
		// HomeWork
	}

	void print(){

		for(int i=0;i<ts;i++){
			cout<<"Bucket "<<i<<"-->";
			node<T>* temp=Bucket[i];
			while(temp!=NULL){
				cout<<temp->key<<", ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

};

int main(){

	hashmap<int> h;

	h.insert("Mango",100);
	h.insert("Apple",200);
	h["Pineapple"]=50;
	h["Papaya"]=30;

	h.print();



	return 0;
}