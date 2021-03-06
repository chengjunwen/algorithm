#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../include/Utilit.h"
using namespace std;
typedef struct job{
	int wei;
	int len;
	job(){}
	job(int weight,int length){
		wei = weight;
		len = length;
	}
	job(const job &rth){
		wei = rth.wei;
		len = rth.len;
	}
	bool operator>(const job &rth){

		if((wei-len)-(rth.wei-rth.len)>0)
			return true;
		else if((wei-len)-(rth.wei-rth.len)==0){
			if(wei-rth.wei>0)
				return true;
			else return false;
		}
		else return false;
	}
};
int main(){
	ifstream fp;
	int num_jobs;
	job * jobs;
	long int cost=0;

	long int current_length=0;

	fp.open("./assign1/jobs.txt",ios::in);
	if(!fp){
		cout<<"can't open data file !"<<endl;
	}
	string line;
	getline(fp,line);
	istringstream stream1(line);
	stream1>>num_jobs;
	jobs=(job*)malloc(sizeof(job)*num_jobs);
	for(int i=0;i<num_jobs;i++){
		getline(fp,line);
		istringstream stream(line);
		job work;
//		int weight,length;
//		stream>>weight;
//		stream>>length;
//		job work(weight,length);	
		stream>>work.wei;
		stream>>work.len;
		jobs[i]=work;
	}
	fp.close();
	HeapSort(jobs, num_jobs);
	for(int i=num_jobs-1;i>=0;i--){
		current_length += jobs[i].len;
		cost += current_length * jobs[i].wei; 
//		cout<<jobs[i].wei<<endl;
	}
	cout<<"cost : "<<cost<<endl;
}
