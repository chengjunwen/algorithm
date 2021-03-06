#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <malloc.h>
#include <set>
#include "../include/Utilit.h"
using namespace std;
struct Edge{
	int first;
	int second;
	int distance;
	bool operator>(const Edge &rth) const
	{
		return distance>rth.distance;
	}
};

void cluster(Edge * edges, int * vers, int num, int K);
void SetCategory(int a, int b, int *vers, int num, int &k);
bool IsSameClass(int a, int b, int *vers);
int main(){
	fstream fp;
	fp.open("./assign2/clustering1.txt",ios::in);
	if(!fp){
		cout<<"can't open the data file!"<<endl;
		return 0;
	}

	Edge * edges;
	int * vertexs; 
	int num;
	string line;
	getline(fp,line);
	istringstream stream(line);
	stream>>num;
	edges=(Edge*)malloc(sizeof(Edge)*(num*(num-1)/2));
	vertexs=(int*)malloc(sizeof(int)*(num+1));
	vertexs[0]=0;
	int i=0;
	while(fp.peek()!=EOF){
		getline(fp,line);
		istringstream stream(line);
		Edge edge;
		stream>>edge.first;
		stream>>edge.second;
		stream>>edge.distance;
		edges[i]=edge;
		if(i==0){
			int id=edge.first;
			vertexs[id]=id;
		}
		if(i<(num-1)){
			int id=edge.second;
			vertexs[id]=id; // 0表示还没有被归类
			
		}
		i++;
	}
/*	cout<<num*(num-1)/2<<endl;
	cout<<edges[num*(num-1)/2-2].first<<edges[num*(num-1)/2-2].second<<edges[num*(num-1)/2-2].distance<<endl;
	cout<<edges[0].first<<edges[0].second<<edges[0].distance<<endl;

	for(int i=0;i<num+1;i++){
		cout<<i<<" "<<vertexs[i]<<endl;
	}
*/
	cluster(edges, vertexs, num, 4);
/*	for(int i=0;i<num+1;i++){
		cout<<i<<" "<<vertexs[i]<<endl;
	}
	for(int i=0; i<num; i++){
		cout<<edges[i].first<<" "<<edges[i].second<<" "<<edges[i].distance<<endl;
	}*/
}
void cluster(Edge * edges, int *vers, int num, int K){
	int k_now=num;
	HeapSort(edges, num*(num-1)/2);
	for(int i=0; i<num*(num-1)/2; i++){
		if(k_now>K){
			SetCategory(edges[i].first, edges[i].second, vers, num, k_now);
		}
		else{
			
			if(!IsSameClass(edges[i].first, edges[i].second, vers)){
				cout<<edges[i].distance<<endl;			
				break;
			}
		}
	}
}

void SetCategory(int a, int b, int *vers, int num, int &k){
	if(vers[a]<vers[b]){
		int target = vers[b];
		for(int i=1;i<num+1;i++){
			if(vers[i]==target){
				vers[i]=vers[a];
			}
		}
		k--;
	}
	else if(vers[a]>vers[b]){
		int target = vers[a];
		for(int i=1;i<num+1;i++){
			if(vers[i]==target){
				vers[i]=vers[b];
			}
		}
		k--;
	}
	else ;
}
bool IsSameClass(int a, int b, int *vers){
	if(vers[a]==vers[b])
		return true;
		else return false;
}
