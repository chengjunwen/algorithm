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
	int pivot=low,p,i,j,temp;
//	Randomize();
//	pivot=RandomInteger(low,high+1);
	p=arr[pivot];
	i=low+1;
	for(j=low+1;j<=high;j++){
		if(arr[j]<p){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
		}
	}
	i--;
	temp=arr[i];
	arr[i]=arr[low];
	arr[low]=temp;
	count=count+high-low;
	return i;
}
