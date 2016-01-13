#include <iostream>
#include <malloc.h>
#include "../include/Utilit.h"
using namespace std;
/*typedef struct job{
    int wei;
    int len;
    bool operate >(const job &rth){
        return (wei-len)-(rth.wei-rth.len);
    }
};
*/
template <typename T> void HeapSort(T * array, int size){
	BuildMaxHeap(array,size);
	for(int i=size-1; i>=0; i--){
		swap(array[0],array[i]);
		HeapMatain(array, 0, i);
	}
}
template <typename T> void BuildMaxHeap(T * array, int size){
	for(int i=size/2 -1; i>=0; i--){
		HeapMatain(array, i, size);
	}
}
template <typename T> void HeapMatain(T *array,int i, int size){
	int left=2*i+1;
	int right=2*i+2;
	int largest = i;
	if(left<size && array[left]>array[largest])
		largest = left;
	if(right<size && array[right]>array[largest])
		largest = right;
	if(largest != i){
		swap(array[i],array[largest]);
		HeapMatain(array,largest,size);
	}
}

template <typename T> void Swap(T &t1, T &t2){
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}
