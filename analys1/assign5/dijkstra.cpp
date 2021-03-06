#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;
#define N 200
struct cellT{
	int vertex;
	int weight;
};
set<int> visited;
set<int> allvex;
void shortestPath(map<int,vector<cellT> > graph,int s,map<int,int> &path);
void dijkstra(map<int,vector<cellT> > graph,map<int,int> &path);
int findNextVex(map<int,vector<cellT> > graph,map<int,int> path,int &nextVex);
int main(){
	fstream f;
	map<int,vector<cellT> > graph;
	f.open("./dijkstraData.txt");
	if(!f){
		cout<<"can't open the file"<<endl;
		return 0;
	}
	for(int i=1;i<=N;i++){
		string line;
		int a,b,wei;
		char ch;
		cellT tmp;
		vector<cellT> vec;
		getline(f,line);
		istringstream stream(line);
		stream>>a;
		while(stream>>b){
			stream>>ch;
			stream>>wei;
			tmp.vertex=b;
			tmp.weight=wei;
			vec.push_back(tmp);
		}
		graph[a]=vec;
		allvex.insert(a);
	}
	f.close();
/*	map<int,vector<cellT> >::iterator it;
	it=graph.find(200);
	vector<cellT> vec=it->second;
	for(int i=0;i<vec.size();i++){
		cellT tmp=vec[i];
		cout<<tmp.vertex<<":"<<tmp.weight<<endl;
	}*/
	map<int,int> path;                 //storage the length of i node to start
	shortestPath(graph,1,path);
	cout<<path[7]<<endl<<path[37]<<endl<<path[59]<<endl<<path[82]<<endl<<path[99]<<endl;
	cout<<path[115]<<endl<<path[133]<<endl<<path[165]<<endl<<path[188]<<endl<<path[197]<<endl;

}
void shortestPath(map<int,vector<cellT> > graph,int s,map<int,int> &path){
	path[s]=0;
	visited.insert(s);
	while(visited!=allvex){
		dijkstra(graph,path);
	}
}
void dijkstra(map<int,vector<cellT> > graph,map<int,int> &path){
	int nextVex=0;
	int shortpath;
	shortpath=findNextVex(graph,path,nextVex);
	if(nextVex!=0){
		visited.insert(nextVex);
		path[nextVex]=shortpath;
	}
	if(nextVex==0){
		set<int>::iterator it;
		for(it=allvex.begin();it!=allvex.end();it++){
			int index=*it;
			if(visited.find(index)==visited.end())
				path[index]=1000000;
		}
	}
}
int findNextVex(map<int,vector<cellT> > graph,map<int,int> path,int &nextVex){
	map<int,int>::iterator it1;
        map<int,vector<cellT> >::iterator it2;
	int shortpath=1000000;
	for(it1=path.begin();it1!=path.end();it1++){
		int v=it1->first;
		it2=graph.find(v);
		vector<cellT>  tmp=it2->second;
		for(int i=0;i<tmp.size();i++){
			cellT cur=tmp[i];
			int w=cur.vertex;
			if(visited.find(w)==visited.end()){
				int distance=path[v]+cur.weight;
				if(distance<shortpath){
					shortpath=distance;
					nextVex=w;
				}
			}
		}
	}
	return shortpath;
}
