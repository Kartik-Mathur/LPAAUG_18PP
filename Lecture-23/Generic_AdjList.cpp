// Generic_AdjList
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

	void addEdge(T u,T v, bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);	
		}
	}

	void print(){

		for(auto node:adjList){
			cout<<node.first<<"-->";
			for(auto neighbour:node.second){
				cout<<neighbour<<",";
			}cout<<endl;
		}
	}

	void bfs(T src){
		queue<T> q;
		map<T,bool> visited;

		q.push(src);
		visited[src]=true;

		while(!q.empty()){
			T node=q.front();
			cout<<node<<" ";
			q.pop();

			for(auto neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
				}
			}
		}
		cout<<endl;
	}

	int SSSP(T src,T des){
		queue<T> q;
		map<T,int > dist;
		map<T,T> parent;

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
					parent[children]=node;
					dist[children]=dist[node]+1;
					q.push(children);
				}
			}
		}

		for(auto node:adjList){
			cout<<"Dist of "<<node.first<<" from "<<src<<" is "<<dist[node.first]<<endl;
		}

		return dist[des];
	}

	void dfsHelper(T src,unordered_map<T,bool> &visited){
		cout<<src<<" ";
		visited[src]=true;

		for(auto children:adjList[src]){
			if(!visited[children]){
				dfsHelper(children,visited);
			}
		}
	}


	void dfs(T src){
		unordered_map<T,bool> visited;

		dfsHelper(src,visited);
		int component=1;

		for(auto node:adjList){
			if(!visited[node.first]){
				dfsHelper(node.first,visited);
				component++;
			}
		}
		cout<<endl<<"components are : "<<component<<endl;
	}
};

int main(){

	Graph <string> g;


	// g.addEdge(0,1);
	// g.addEdge(0,2);
	// g.addEdge(0,3);
	// g.addEdge(1,2);
	// g.addEdge(2,3);

	g.addEdge("Putin","Trump");
	g.addEdge("Putin","Modi");
	g.addEdge("Putin","Pope");
	g.addEdge("Modi","Trump",true);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Yogi","Prabhu");
	g.addEdge("Prabhu","Modi");
	g.addEdge("XYZ","WWW");

	g.dfs("Modi");
	cout<<endl;




	return 0;
}