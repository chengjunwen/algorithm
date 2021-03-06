#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
#include "../cs106blib/CS106/strutils.h"

using namespace std;
#define N 875714
//vector<int> vtime;
stack<int> finishtime;
//int t=0;
vector<int> visit1,visit2;
int count=0;
vector<int> sum;

void finishTime(map<int,vector<int> > &rgraph);
void DFS1(map<int,vector<int> > &rgraph,int i);
void DFS2(map<int,vector<int> >&graph,int i,int &allset);
void countscc(map<int,vector<int> >&graph);
int main(){
	ifstream f;
	f.open("./SCC.txt");		//read the file
	if(!f){
		cout<<"can't open the file !"<<endl;
		return 0;
	}
	map<int,vector<int> >graph,rgraph;	//storage the information of the graph
	string line;
	int tail,head;
	map<int,vector<int> >::iterator it;
	while(!f.eof()){
		getline(f,line);
		istringstream stream(line);	//read the signal data
		stream>>tail;
		stream>>head;
		it=graph.find(tail);
		vector<int> tmp1,tmp2;
		if(it!=graph.end()){		//if find then add to the find one
			tmp1=it->second;
			tmp1.push_back(head);
			graph[tail]=tmp1;
		}
		else{				//if not find ,then add to the graph
			tmp1.push_back(head);
			graph[tail]=tmp1;			
		}
		it=rgraph.find(head); 		//build the reverse graph
		if(it!=rgraph.end()){
			tmp2=it->second;
			tmp2.push_back(tail);
			rgraph[head]=tmp2;
		}
		else{
			tmp2.push_back(tail);
			rgraph[head]=tmp2;
		}
	}
	f.close();
//	vtime[0]=0;
	for(int i=0;i<N+1;i++){
		visit1.push_back(0);
		visit2.push_back(0);
	}
	finishTime(rgraph);
	countscc(graph);
	for(int i=0;i<5;i++){
		int index,max=0,j;
		for(j=0;j<sum.size();j++){
			if(sum[j]>max){
				index=j;
				max=sum[j];
			}
		}
		cout<<max<<endl;
		if(!sum.empty())
			sum.erase(sum.begin()+index);
	}
//	it=rgraph.find(7);
//	vector<int> test;
//	test=it->second;
//	for(int i=0;i<test.size();i++){
//		cout<<test[i]<<" ";
//	}
//	cout<<endl;
}


void finishTime(map<int,vector<int> > &rgraph){
	for(int i=N;i>0;i--){
		if(visit1[i]==0){
			DFS1(rgraph,i);
		}
	}
}

void DFS1(map<int,vector<int> > &rgraph,int i){
	visit1[i]=1;
	map<int,vector<int> >::iterator it;
	vector<int> tmp;
	it=rgraph.find(i);
	if(it==rgraph.end()){
	//	cout<<"ERROR1"<<endl;
	//	cout<<i<<endl;
	}
	else{
		tmp=it->second;
		for(int k=0;k<tmp.size();k++){
			int j=tmp[k];
			if(visit1[j]==0)	DFS1(rgraph,j);
		}
	}
//	t++;
//	vtime[i]=t;
	finishtime.push(i);
}
void countscc(map<int,vector<int> >&graph){
	for(int i=N;i>0;i--){
		int j=finishtime.top();
		finishtime.pop();
		int allset=0;
		if(visit2[j]==0){
			DFS2(graph,j,allset);
			sum.push_back(allset);			
			count++;
		}
		
		
	}
}
void DFS2(map<int,vector<int> >&graph,int i,int &allset){
	visit2[i]=1;
	map<int,vector<int> >::iterator it;
	vector<int> tmp;
	it=graph.find(i);
	if(it==graph.end()){
	//	cout<<"ERROR2"<<endl;
	//	cout<<i<<endl;
	}
	else{
		tmp=it->second;
		for(int k=0;k<tmp.size();k++){
			int j=tmp[k];
			if(visit2[j]==0)	DFS2(graph,j,allset);
		}
	}
	allset++;
}

