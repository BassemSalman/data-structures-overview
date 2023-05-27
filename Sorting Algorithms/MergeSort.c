void Fusion(int T[], int lower, int upper, int middle)
{
    // left array: i=lower -- middle
    // right array:i=middle+1 -- upper
    // newArray is of k elements or upper-lower+1

    int i = lower, j = middle + 1, k = 0, c[upper - lower + 1];

    while (i <= middle && j <= upper)
    {
        if (T[i] < T[j])
            c[k++] = T[i++];
        else
            c[k++] = T[j++];
    }

    // copy remainingss
    while (i <= middle)
        c[k++] = T[i++];
    while (j <= upper)
        c[k++] = T[j++];

    // copy to T
    for (i = lower, j = 0; j < k; j++, i++) // k elements in c
        T[i] = c[j];
}

void MergeSort(int T[], int lower, int upper)
{
    int middle;
    if (lower < upper) // if theres one element only, lower == upper
    {
        middle = (lower + upper) / 2; // 0 1 2
        MergeSort(T, lower, middle);  // mergesort on the two parts
        MergeSort(T, middle + 1, upper);
        Fusion(T, lower, upper, middle); // merge the 2 arrays
    }
}