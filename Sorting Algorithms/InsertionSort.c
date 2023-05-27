//efficient comparison sort
//simple, adaptive(if input is presorder, insertion takes O(n+d) where d=nb of inversions)
//in-place: requires cst ammount of memory space additional
//Online: insertion sort can svort the list as it receivees it
// after k iterations, first k+1 entries are sorted

void InsertionSort(int* A, int n)
{
    int i,j,v;
    // initially sorted part contains first element
    for(i=1;i<=n-1;i++)
    {
        v=A[i]; //element directly baaed el hajez ben sorted w nonsorted
        j=i;    //so that i dont edit i while changing the place of the element (to use in while)
        while(A[j-1]>v && j>0) // shift elements forward as long as i'm less than the elements 
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=v; // after shifting, set element to v
    }
} // O(n squared)
