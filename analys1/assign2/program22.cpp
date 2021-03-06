#include <iostream>
#include <fstream>
#include "../cs106blib/CS106/strutils.h"
#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/random.h"

using namespace std;
#define N 10000
unsigned long count=0;
void countComp(Vector<int> &arr,int low,int high);
int partition(Vector<int> &arr,int low,int high);
void swap(int &a,int &b);
int main(){
	ifstream f;
	f.open("./QuickSort.txt");
	if(!f){
		cout<<"can't open the file !"<<endl;
		return 0;
	}
	Vector<int> array;
	int num,i=0;
	string temp;
	while(!f.eof()){
                getline(f,temp);
                if(temp!="") {
                        num =StringToInteger(temp);
				array.add(num);
                }
        }
//	cout<<array[0]<<"   "<<array[1]<<endl;
        f.close();
	countComp(array,0,N-1);
	cout<<count<<endl;
	return 0;       
        

}
void countComp(Vector<int> &arr,int low,int high){
	if(low<high){
		int mark;
		mark=partition(arr,low,high);
        	countComp(arr,low,mark-1);
		countComp(arr,mark+1,high);
		
	}
}
int partition(Vector<int> &arr,int low,int high){
	int pivot=high,p,i,j,temp;
//	Randomize();
//	pivot=RandomInteger(low,high+1);
	p=arr[pivot];
	swap(arr[low],arr[high]);
	i=low+1;
	for(j=low+1;j<=high;j++){
		if(arr[j]<p){
			swap(arr[i],arr[j]);
			i++;
		}
	}
	i--;
	swap(arr[i],arr[low]);
	count=count+high-low;
	return i;
}
void swap(int &a,int &b){
        int temp;
        temp=a;
        a=b;
        b=temp;
}


