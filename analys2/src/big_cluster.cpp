#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <malloc.h>
#include <time.h>
#include <set>
#include <vector>
#include "../include/Utilit.h"
using namespace std;
struct Edge{
	short first;
	short second;
	short distance;
	bool operator>(const Edge &rth) const
	{
		return distance>rth.distance;
	}
};

//void cluster(Edge * edges, int * vers, int num, int K);
//void SetCategory(int a, int b, int *vers, int num, int &k);
//bool IsSameClass(int a, int b, int *vers);
int HanmingDistance(vector<short> &a, vector<short> &b, const int n_byte);
int main(){
	fstream fp;
	fp.open("./assign2/clustering_big.txt",ios::in);
	if(!fp){
		cout<<"can't open the data file!"<<endl;
		return 0;
	}

	Edge * edges;
//	int * vertexs;
	vector<vector<short> > binData; 
	int num;
	int n_byte;
	string line;
	getline(fp,line);
	istringstream stream(line);
	stream>>num>>n_byte;

	edges=(Edge*)malloc(sizeof(Edge)*(num*(num-1)/2));
	if(edges==NULL){
		cout<<"malloc failed;"<<endl;
		return 0;
	}
//	vertexs=(int*)malloc(sizeof(int)*(num+1));
//	vertexs[0]=0;
	time_t start,finish;
	start=time(NULL);
	while(fp.peek()!=EOF){
		getline(fp,line);
		istringstream stream(line);
		vector<short> temp; 
		for(int j=0; j<n_byte; j++){
			int b;
			stream>>b;
			temp.push_back(b);
		}
		binData.push_back(temp);
	}
	cout<<binData.size()<<endl;
	for(int j=0; j<n_byte; j++){
		cout<<binData[200000-1][j]<<endl;
	}
	finish=time(NULL);
	cout<<"read file "<<difftime(finish,start)<<" s"<<endl;
	int k=0;
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++ ){
			int dist =HanmingDistance(binData[i],binData[j],n_byte);
			Edge edge;
			edge.first=i+1;
			edge.second=j+1;
			edge.distance=dist;
			edges[k++]=edge;
		}
		if(i%1000==0)
			cout<<i<<endl;
	}
	start=time(NULL);
	cout<<"HanmingDistance "<<difftime(finish,start)<<" s"<<endl;
	cout<<k<<endl;
//	cluster(edges, vertexs, num, 4);
}

int HanmingDistance(vector<short> &a, vector<short> &b, const int n_byte){
	int count=0;	
	for(int j=0; j<n_byte; j++){
		if( (a[j]^b[j]) == 1)
			count++;
	}
	return count;
}
