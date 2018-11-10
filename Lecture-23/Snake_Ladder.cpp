// Snake_Ladder
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <map>
#include <climits>
using namespace std;

template <typename T>
class Graph{
	map <T,list<T> > adjList;
public:

	void addEdge(T u,T v, bool bidir=false){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);	
		}
	}

	int SSSP(T src,T des){
		queue<T> q;
		map<T,T> parent;
		map<T,int> dist;

		for(auto node:adjList){
			dist[node.first]=INT_MAX;
		}	
		
		q.push(src);
		dist[src]=0;
		parent[src]=src;

		while(!q.empty()){
			T node=q.front();
			q.pop();

			for(auto children:adjList[node]){
				if(dist[children]==INT_MAX){
					dist[children]=dist[node]+1;
					q.push(children);
					parent[children]=node;
				}
			}
		}

		T temp=des;

		while(temp!=src){
			cout<<temp<<"<--";
			temp=parent[temp];
		}
		cout<<src<<endl;	

		return dist[des];
	}

};


int main(){
	Graph<int> g;

	int board[50] = {0};
	
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17]=-13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int u=0;u<=36;u++){
		for(int i=1;i<7;i++){
			int v=u+i+board[u+i];
			g.addEdge(u,v);
		}
	}

	cout<<g.SSSP(1,36)<<endl;

	return 0;
}