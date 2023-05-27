//best suited for small arrays, requires no additional space = in-place algo, easy

void minSelection(int* A, int n)
{
    int imin, i,j, temp;
    
    for(i=0;i<n-1;i++) // last element already sorted
    {
        imin=i;
        //i+1 so that i dont compare the element with itself
        for(j=i+1;j<n;j++) // used to swap everytime i find nb lower than min, ma fi de3e
            if(A[imin]>A[j])
                imin=j;

        if(imin != i) // needs swapping after finding current min with current 1st
        {
            temp=A[imin];
            A[imin]=A[i];
            A[i]=A[imin];
        }
    }
}