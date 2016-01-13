#include <iostream>
#include <fstream>
#include <malloc.h>
#include "../cs106blib/CS106/strutils.h"
#include "../cs106blib/CS106/vector.h"

#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/vector.h"
#include "../cs106blib/CS106/vector.h"
using namespace std;
#define N 100000
unsigned long count=0;
void countInver(Vector<int> &arr,int low,int high);
void mergeCount(Vector<int> &arr,int low,int high,int mid);
int main(){
	ifstream f;
	f.open("./IntegerArray.txt");
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
	cout<<array[0]<<"   "<<array[1]<<endl;
        f.close();
	countInver(array,0,N-1);
	cout<<count<<endl;
	return 0;       
        

}
void countInver(Vector<int> &arr,int low,int high){
	int mid =(high-low)/2+low;
	int a,b,c;
	if(low<high){
        	countInver(arr,low,mid);
		countInver(arr,mid+1,high);
		mergeCount(arr,low,high,mid);
	}
}
void mergeCount(Vector<int> &arr,int low,int high,int mid){
	Vector<int> temp;
	int i=low,j=mid+1;
	int size=high-low+1;
//	int *temp=(int *)malloc(sizeof(int)*size);

	while(i<=mid&&j<=high){
		if(arr[i]<=arr[j])
		{
			temp.add(arr[i++]);
		}
		else{
			temp.add(arr[j++]);
			count+=mid-i+1;
		}
	}
	while(i<=mid) temp.add(arr[i++]);
	while(j<=high) temp.add(arr[j++]);
	int n=0;
	for(int k=low;k<high+1;k++){
		arr[k]=temp[n++];
	}
}
