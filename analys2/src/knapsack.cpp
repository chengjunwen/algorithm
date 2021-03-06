#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "../include/Utilit.h"
using namespace std;
struct Item{
	int value;
	int weight;
};
int optimalSolutionToKnapsack(vector<Item> &vec,int capacity);
int optimalSolutionToKnapsack2(vector<Item> &vec,int capacity);
int main(){
	ifstream fp;
	fp.open("./assign3/knapsack1.txt",ios::in);
	if(!fp){
		cout<<"can't open data file !"<<endl;
	}
	int numAll,capacity;
	vector<Item> items;
	string line;
	getline(fp,line);
	istringstream stream(line);
	stream>>capacity>>numAll;
	for(int i=0;i<numAll;i++){
		getline(fp,line);
		istringstream stream(line);
		Item item;
		stream>>item.value>>item.weight;
		items.push_back(item);
	}
	fp.close();
	cout<<items.size()<<" "<<items[0].value<<" "<<items[0].weight<<endl;
//	int W=optimalSolutionToKnapsack(items,capacity);
	int W=optimalSolutionToKnapsack2(items,capacity);
	cout<<W<<endl;
}
int optimalSolutionToKnapsack(vector<Item> &vec,int capacity){
	
	int nums=(int)vec.size();
	int **A=new int*[nums+1];
	for(int i=0;i<nums+1;i++){
		A[i]=new int[capacity+1];
	}
	for(int j=0;j<capacity+1;j++){
		A[0][j]=0;		
	}
	for(int i=1;i<nums+1;i++){
		for(int j=0;j<capacity+1;j++){
			int wei=vec[i].weight;
			int val=vec[i].value;
			if(j<wei){
				A[i][j]=A[i-1][j];
			}
			else{
				if(A[i-1][j]>(A[i-1][j-wei]+val))
					A[i][j]=A[i-1][j];
				else 
					A[i][j]=A[i-1][j-wei]+val;
			}
		}
	}
	return A[nums][capacity];
}


int optimalSolutionToKnapsack2(vector<Item> &vec,int capacity){
	
	int nums=(int)vec.size();
	int *A=new int[capacity+1];
	for(int j=0;j<capacity+1;j++){
		A[j]=0;		
	}
	for(int i=1;i<nums+1;i++){
		for(int j=capacity;j>=0;j--){
			int wei=vec[i].weight;
			int val=vec[i].value;
			if(j>wei){
				if(A[j]>(A[j-wei]+val))
					A[j]=A[j];
				else 
					A[j]=A[j-wei]+val;
			}
	//		cout<<j<<endl;
		}
		cout<<i<<endl;
	}
	return A[capacity];
}
