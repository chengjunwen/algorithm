#include <iostream>
#include <fstream>
#include <sstream>
#include "../../cs106blib/CS106/vector.h"

using namespace std;
void insertNum(int &data,Vector<int> &nums);
void biSearch(int &data,Vector<int> &nums,int low,int high);
int main(){
	ifstream f;
	f.open("./Median.txt");		//read the file
	Vector<int> nums;
	int sum=0;
	if(!f){
		cout<<"can't open the file !"<<endl;
		return 0;
	}
	while(f.peek()!=EOF){
		string line;
		int data,i,index;
		getline(f,line);
		istringstream stream(line);	//read the signal data
		stream>>data;
		insertNum(data,nums);
		index=(nums.size()-1)/2;	
		sum+=nums[index];
	}
	cout<<sum%10000<<endl;
}
void insertNum(int &data,Vector<int> &nums){
	if(nums.isEmpty()){
		nums.add(data);
	}
	else{
		return biSearch(data,nums,0,nums.size()-1);
	}
}
void biSearch(int &data,Vector<int> &nums,int low,int high){
	if(low==high){
//		cout<<"insert"<<data<<endl;
		if(data<=nums[low]) nums.insertAt(low,data);
		else nums.insertAt(low+1,data);
	}
	else{
		int medium=(high-low)/2+low;
		if(data==nums[medium]) nums.insertAt(medium,data);
		else if(data<nums[medium]) biSearch(data,nums,low,medium);
		else biSearch(data,nums,medium+1,high);
	}
}
