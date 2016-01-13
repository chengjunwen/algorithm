#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include "../include/Utilit.h"
using namespace std;

typedef struct cellT{
	int vertex;	//存储 下一节点id
	int weight;	//存储 两节点间的cost
	bool operator>(cellT &rth){
		if(weight < rth.weight)
			return 1;
		else return 0;
	}
};
set<int> allVer;
set<int> visited;
void primMST(map<int, vector<cellT> > &graph, int &cost);
void shortestPath(map<int, vector<cellT> > &graph, int &cost);
int main(){
	ifstream fp;
	fp.open("./assign1/MSTdata.txt",ios::in);
	if(!fp){
		cout<<"can't open data file !"<<endl;
		return 0;
	}
	map<int , vector<cellT> > graph;
	int numVers;
	int numEdges;
	string line;
	getline(fp, line);
	istringstream stream1(line);
	stream1>>numVers>>numEdges;
//	读取数据	
	for(int i=0; i<numEdges; i++){
		int ver1, ver2, wei;
		cellT cellTemp;
		getline(fp ,line);
		istringstream stream2(line);

		stream2>>ver1>>ver2>>wei;
		cellTemp.vertex = ver2;
		cellTemp.weight = wei;
		allVer.insert(ver1);
		allVer.insert(ver2);
		if(graph.find(ver1)==graph.end()){
			vector<cellT> verTemp;
			verTemp.push_back(cellTemp);
			graph.insert(make_pair(ver1, verTemp));  //插入新值
//			allVer.insert(ver1);
		}
		else{
			vector<cellT> verTemp;
			auto it =graph.find(ver1);
			verTemp = it->second;
			verTemp.push_back(cellTemp);
			graph[ver1]=verTemp;	//覆盖原有值
		}
		
		if(graph.find(ver2)==graph.end()){
			vector<cellT> verTemp;
			cellTemp.vertex=ver1;
			verTemp.push_back(cellTemp);
			graph.insert(make_pair(ver2, verTemp));  //插入新值
//			allVer.insert(ver1);
		}
		else{
			vector<cellT> verTemp;
			auto it =graph.find(ver2);
			verTemp = it->second;
			cellTemp.vertex=ver1;
			verTemp.push_back(cellTemp);
			graph[ver2]=verTemp;	//覆盖原有值
		}
	}
	fp.close();
/*	int n=allVer.size();
	cout<<"size:"<<n<<" size2 :"<<visited.size()<<endl;
	for(auto it=allVer.begin(); it!=allVer.end();it++){
		cout<<*it<<endl;
	}
	map<int,vector<cellT> >::iterator it;
	it=graph.find(460);
	vector<cellT> vec=it->second;
	for(int i=0;i<vec.size();i++){
		cellT tmp=vec[i];
		cout<<tmp.vertex<<":"<<tmp.weight<<endl;
	}*/
	int cost = 0;
	primMST(graph, cost);
	cout<<cost<<endl;
}

void primMST(map<int, vector<cellT> > &graph, int &cost){
	visited.insert(1);
	while(visited != allVer){
		shortestPath(graph,cost);
	}
	
}
void shortestPath(map<int, vector<cellT> > &graph, int &cost){
	vector<cellT> candidate;
	for(auto it1=visited.begin(); it1!=visited.end(); it1++){
		int ver1 = *it1;
		auto verTover=graph.find(ver1);
		if(verTover==graph.end()){
//			cout<<"not find "<<ver1<<endl;
			break;
		}
		vector<cellT> vecTemp = verTover->second;
		for(auto it2=vecTemp.begin(); it2!=vecTemp.end(); it2++){
			int ver2 = it2->vertex;
			if(visited.find(ver2)==visited.end()){
				candidate.push_back(*it2);
			}
		}
	}
	int n=candidate.size();
	cellT *xx =(cellT *)malloc(sizeof(cellT)*n);
	for(int i=0; i<n; i++){
		xx[i]=candidate[i];
	}	
	BuildMaxHeap(xx,candidate.size());
	cellT verNext = xx[0];
//	cout<<verNext.vertex<<":"<<verNext.weight<<endl;
	cost +=verNext.weight;
	visited.insert(verNext.vertex);
}

