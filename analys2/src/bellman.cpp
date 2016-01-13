#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

#define INFINITY 65535
int numVers, numEdges;
struct Edge{
	int tail;
	int head;
	bool operator<(const Edge &rth) const{
//		if(head<rth.head)
//			return 1;
//		else return 0;
		return head<rth.head;
	}
};
int Floyd_Warshall(map<Edge, int> &graph, int **d);
//int Johnson(map<Edge, int> &graph, int **d);
int main(){
	ifstream fp;
	fp.open("./data/graph_test.txt", ios::in);
	if(!fp){
		cout<<"can't open file !"<<endl;
		return 0;
	}

	string line;
//	vector<Edge> graph;
	map<Edge, int> graph;
	getline(fp, line);
	istringstream stream(line);
	stream>>numVers>>numEdges;
	while(fp.peek()!=EOF){
		Edge temp;
		int len;
		getline(fp, line);
		istringstream stream(line);
//		cout<<line<<endl;
		stream>>temp.tail>>temp.head>>len;
		graph.insert(make_pair(temp, len));
	}
	fp.close();
	cout<<graph.size()<<endl;
//	cout<<graph[numEdges-1].tail<<" "<<graph[numEdges-1].head<<" "<<graph[numEdges-1].length<<endl;
	int **dist = new int*[numVers+1];
	for(int i=0; i<numVers+1; i++){
		dist[i] = new int[numVers+1];
	}
	int shortestLength = Floyd_Warshall(graph, dist);
	cout<<shortestLength<<endl;
}

int Floyd_Warshall(map<Edge, int> &graph, int **d){
//initial
	for(int i=1; i<numVers+1; i++){
		for(int j=1; j<numVers+1; j++){
			if(i==j) d[i][j] = 0;
			else{
				Edge temp;
				temp.head = j;
				temp.tail = i;
				auto it=graph.find(temp);
				if(it!=graph.end()){
					d[i][j]=it->second;
				}
				else
					d[i][j]=INFINITY;
					
			}
		}
	}

//	int sh=65535;
//compute
	for(int k=1; k<numVers+1; k++){
		for(int i=1; i<numVers+1; i++){
			for(int j=1; j<numVers+1; j++){
				if( (d[i][k]+d[k][j])<d[i][j] )
					d[i][j] = d[i][k]+d[k][j];
			}
		}
	}
	return d[1][numVers];
}
/*int Johnson(map<Edge, int> &graph, int **d)
{

	int * p=new int[numvers+1];
	for(int j=0; j<numvers+1; j++){
		p[j]=0;
	}

//bellman
	for(int i=1; i<numvers+1; i++){
		for(auto it=graph.begin(); it!=graph.end(); it++){
			int t=(it->first).tail;
			int h=(it->first).head;
			int length=it->second;
			if(p[h]>p[t]+length){
				p[h]=p[t]+length;			
			}
		}
	}
// test 负循环
	for(auto it=graph.begin(); it!=graph.end(); it++){
		int t=(it->first).tail;
		int h=(it->first).head;
		int length=it->second;
		if(p[h]>p[t]+length){
			return 65535;
		}
	}
//reweighting
	map<Edge, int> graphT;
	for(auto it=graph.begin(); it!=graph.end(); it++){
		int t=(it->first).tail;
		int h=(it->first).head;
		int length=it->second;
		lenght = length+p[t]-p[h];
		graphT.insert(make_pair(it->first,length))
	}
	
}*/
