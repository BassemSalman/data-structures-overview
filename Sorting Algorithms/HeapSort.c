#include "C:\HeaderFiles\DS.h"

void HeapSort(int A[], int N)
{
    Heap h = CreateHeap(N, 1); // 1 is maxheap yaane
    int old_size = h->count;
    int i, temp;
    BuildHeap(&h, A, N); // since it is a heap, percolating down will set max in root
    // create heap from array
    for (i = N - 1; i >= 0; i--)
    {
        // h->array[0] is max yaane lroot
        temp = h->array[0]; 
        h->array[0] = h->array[h->count - 1];   // root <- last leaf 
        h->array[h->count - 1] = temp;          // root -> last leaf 
        // swap max with the last leaf and percolate it down --> maxnew max will be set

        h->count--; // nayem la ekhr element
        PercolateDown(&h, 0); 
    }
    h->count = old_size;
    for (i = 0; i < h->count; i++)
        A[i] = h->array[i];
} // O(nlogn) check anime