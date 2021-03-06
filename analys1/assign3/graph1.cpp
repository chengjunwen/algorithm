#include <iostream>
#include <fstream>
//#include <vector>
#include <sstream>
#include <set>
#include <map>
#include "../../cs106blib/CS106/random.h"
#include "../../cs106blib/CS106/vector.h"
//#include "../cs106blib/CS106/map.h"
using namespace std;

#define N 200
int count=0;
int minCut(map<int,Vector<int> > &graph);
int main(){
	fstream file;
	int crossingEdges=N,i=0;
	map<int,Vector<int> > graph1;
	
	Randomize();
	file.open("./kargerMinCut.txt");
//	file.open("./test.txt");
	if(!file){
//		cout<<"cant open the file"<<endl;
		return 0;
	}
	for(int i=1;i<N+1;i++){
		string line;
		int first,data;
		Vector<int> temp,temp1;
		getline(file,line);
		istringstream stream(line);
		stream>>first;
		while(stream>>data){
			temp.add(data);
		}
		graph1[i]=temp;
		
	}
	
	for(int i=0;i<N*N*9;i++){
		map<int,Vector<int> > graph=graph1;
		int temp=minCut(graph);
		if(temp<crossingEdges)
			crossingEdges=temp;
	}
	cout<<"the min cut has "<<crossingEdges<<" crossing  edges"<<endl;
	cout<<count<<endl;
}

int minCut(map<int,Vector<int> > &graph){
	map<int,Vector<int> >::iterator it1=graph.begin(),it2;	//iterator pointed to node1 and node2 
	Vector<int> edges1,edges2;		//storage edges linked to node1 and node2
//	cout<<graph.size()<<"graph size "<<endl;
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
		edges1=it1->second;

//		cout<<ver1<<"vex1 "<<edges1.size()<<"before vex1 size"<<endl;

		edgeIndex=RandomInteger(0,edges1.size()); //random to dicede the node2 linked to node1
		ver2=edges1[edgeIndex];
		it2=graph.find(ver2);
		if(it2==graph.end()){
			cout<<"ERROR2"<<endl;
			return 0;
		}

		edges2=it2->second;
//		cout<<ver2<<"vex2 "<<edges2.size()<<"vex2 size"<<endl;

		for(int i=0;i<edges1.size();i++){	//delete the selfLoop
			if(edges1[i]==ver2){	
				edges1.removeAt(i);
				i--;
//				cout<<"delete "<<ver2<<endl;
			}
		}
//		cout<<edges1.size()<<"in vex1 size"<<endl;
		for(int i=0;i<edges2.size();i++){   //add else to the edges of node1 and modify others
//			cout<<edges2[i]<<endl;
			if(edges2[i]!=ver1){
				map<int,Vector<int> >::iterator itTemp;
				int temp=edges2[i];

				edges1.add(temp);   //add to node1

				Vector<int> edgesTemp;
//				cout<<temp<<endl;

				itTemp=graph.find(temp);
				if(itTemp==graph.end()) {
					cout<<"Error"<<endl;
					return 0;
				}
				else{
					edgesTemp=itTemp->second;
					for(int j=0;j<edgesTemp.size();j++){
						if(edgesTemp[j]==ver2)	{
//							cout<<"change"<<ver2<<" to "<<ver1<<endl;	
							edgesTemp.removeAt(j);
							edgesTemp.insertAt(j,ver1);
						}
					}
					graph[temp]=edgesTemp;
				}//else
				
			}//if
		}//for
//		cout<<edges1.size()<<"afternoon vex1 size"<<endl;
//		for(int i=0;i<edges1.size();i++){
//			if(edges1[i]==ver1){
//				cout<<"DELETE "<<ver1<<endl;	
//				edges1.removeAt(i);
//				i--;
//			}
//			else cout<<edges1[i]<<endl;
//		}
		graph[ver1]=edges1;
//		cout<<edges1.size()<<"after vex1 size"<<endl;
		graph.erase(it2);
		count++;
		return minCut(graph);
	} 
}
