#include <iostream>
#include <malloc.h>

#ifndef _UTILITY_H
#define _UTILITY_H

using namespace std;
/*typedef struct job{
    int wei;
    int len;
    bool operate >(const job &rth){
        return (wei-len)-(rth.wei-rth.len);
    }
};
*/
template <typename T> void HeapSort(T * array, int size);
template <typename T> void BuildMaxHeap(T * array, int size);
template <typename T> void HeapMatain(T *array,int i, int size);

template <typename T> void Swap(T &t1, T &t2);
#endif
