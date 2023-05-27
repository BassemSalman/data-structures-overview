// iterating current till last through comparison, (current changes if curr<next) stops when no swaps are needed
// if i swapped myself with my next, and i++ happened, A[i] will be the same
void BubbleSort(int* A, int n)
{
    int pass, i, temp, swap=1;
    for(pass = n-1; pass>=0 && swap; pass--) //limits end of array since one pass puts max in end
    { //nb of passes is equal to nb of elements - 1 = index of last element
        for(i=0; i<pass; i++)
        { // compare with next element in current array not the ones in the end
            swap = 0;
            if(A[i]>A[i+1])
            {
                temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
                swap=1;
            }
        }
    }
} // worst: O(n^2), best: O(n) sorted array 

/* 
5 4 3 2 2, pass=4
4 5 3 2 2
4 3 5 2 2
4 3 2 5 2
4 3 2 2 5
pass=3
4 bubbles to end
3 2 2 4 5
3 as well
2 2 3 4 5
2 is compared to 2 and swap=0 so stop

pass=0 then 2 is compared to next so both cases stop
*/