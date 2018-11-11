#include <iostream>
#include <set>
#include <list>
#include <unordered_map>
#include <map>
#include <climits>
using namespace std;

template <typename T>
class Graph{
	map<T,list<pair<T,int> > > h;
public:
	void addEdge(T u,T v,int d,bool bidir=true){
		h[u].push_back(make_pair(v,d));
		if(bidir){
			h[v].push_back(make_pair(u,d));
		}
	}

	void print(){
		for(auto node:h){
			cout<<node.first<<"-->";
			for(auto children:node.second){
				cout<<"("<<children.first<<","<<children.second<<")";
			}
			cout<<endl;
		}
	}

	void dijkstras(T src){
		map<T,int> dist;

		for(auto node:h){
			dist[node.first]=INT_MAX;
		}

		set<pair<int,T> > s;

		dist[src]=0;
		s.insert(make_pair(0,src));

		while(!s.empty()){
			auto p=*(s.begin());

			s.erase(s.begin());

			T parent=p.second;
			int parentDist=p.first;

			// Iterate over the children
			for(auto children:h[parent]){
				if(dist[children.first]>parentDist+children.second){
					auto f=s.find(make_pair(dist[children.first],children.first));
					if(f!=s.end()){
						s.erase(f);
					}

					dist[children.first]=parentDist+children.second;
					s.insert(make_pair(dist[children.first],children.first));
				}
			}
		}

		for(auto i:dist){
			cout<<"Distance of "<<i.first<<" from "<<src;
			cout<<" is "<<i.second<<endl;
		}

	}

};

int main(){

	Graph<string> g;

	g.addEdge("Amritsar","Agra",1);
	g.addEdge("Amritsar","Jaipur",4);
	g.addEdge("Delhi","Jaipur",2);
	g.addEdge("Delhi","Agra",1);
	g.addEdge("Bhopal","Agra",2);
	g.addEdge("Bhopal","Mumbai",3);
	g.addEdge("Jaipur","Mumbai",8);

	g.dijkstras("Amritsar");



	return 0;
}