#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include "../cs106blib/CS106/random.h"
using namespace std;

#define N 200
int count=0;
int minCut(map<int,vector<int> > &graph);
int main(){
	fstream file;
	int crossingEdges=N,i=0;
	map<int,vector<int> > graph;
	
	Randomize();
	file.open("./kargerMinCut.txt");
	if(!file){
		cout<<"cant open the file"<<endl;
		return 0;
	}
	for(int i=1;i<N+1;i++){
		string line;
		int first,data;
		vector<int> temp,temp1;
		getline(file,line);
		istringstream stream(line);
		stream>>first;
		while(stream>>data){
			temp.push_back(data);
		}
		graph[i]=temp;
		
	}
	
	for(int i=0;i<1;i++){
		int temp=minCut(graph);
		if(temp<crossingEdges)
			crossingEdges=temp;
	}
	cout<<"the min cut has "<<crossingEdges<<" crossing  edges"<<endl;
	cout<<count<<endl;
}

int minCut(map<int,vector<int> > &graph){
	map<int,vector<int> >::iterator it1=graph.begin(),it2;	//iterator pointed to node1 and node2 
	vector<int> edges1,edges2;		//storage edges linked to node1 and node2

	if(graph.size()<=2)
	{
		edges1=it1->second;		//
		return edges1.size();
	}
	else{
		int verIndex,edgeIndex,ver1,ver2;	//storage the message of node1/2
		verIndex=RandomInteger(0,graph.size());
		if(verIndex>0){		//random to decide the node1
			for(int i=1;i<=verIndex;i++)	it1++;
		}
		if(it1==graph.end()){
			cout<<"ERROR1"<<endl;
			return 0;
		}
		ver1=it1->first;
//		cout<<ver1<<endl;

		edges1=it1->second;
		edgeIndex=RandomInteger(0,edges1.size()); //random to dicede the node2 linked to node1
		ver2=edges1[edgeIndex];

//		cout<<ver2<<endl;


		it2=graph.find(ver2);
		if(it2==graph.end()){
			cout<<"ERROR2"<<endl;
			return 0;
		}

		edges2=it2->second;
//		for(int i=0;i<edges1.size();i++){	//delete the selfLoop
//			if(edges1[i]==ver2)	
//				edges1.erase(edges1.begin()+i);
//		}
		
		for(int i=0;i<edges2.size();i++){   //add else to the edges of node1 and modify others
//			if(edges2[i]!=ver1){
				map<int,vector<int> >::iterator itTemp;
				int temp=edges2[i];

				edges1.push_back(temp);   //add to node1

				vector<int> edgesTemp;
		//		cout<<temp<<endl;

				itTemp=graph.find(temp);
				if(itTemp==graph.end()) {
					cout<<"Error"<<endl;
					return 0;
				}
				else{
					edgesTemp=itTemp->second;
					for(int j=0;j<edgesTemp.size();j++){
						if(edgesTemp[j]==ver2)	edgesTemp[j]=ver1;
					}
					graph[temp]=edgesTemp;
				}//else
				
//			}//if
		}//for
		for(int i=0;i<edges1.size();i++){
			if(edges1[i]==ver1)	
				edges1.erase(edges1.begin()+i);
		}
		graph[ver1]=edges1;
		graph.erase(it2);
		count++;
		return minCut(graph);
	} 
}
