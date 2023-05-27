int Partition(int A[], int low, int high)
{
    int pivot_item = A[low];
    int left = low + 1;
    int right = high;

    while (left <= right)
    {
        while (A[left] <= pivot_item && left <= right) // compare the left to pivot and increment if it is smaller
            left++;
        while (A[right] > pivot_item && left <= right)
            right--;

        // when loops break but there are elements in array swap the right and left
        if (left < right)
        {
            swap(A, left, right);
            // since akid ha tzbat conditions el loops 3layon
            left++;
            right--;
        }
    }

    // swap index of right with pivot, right<left so its the middle
    A[low] = A[right];
    A[right] = pivot_item;

    return right; // index of pivot
}

void QuickSort(int A[], int low, int high)
{
    int pivot;      // li hiye el q
    if (high > low) // as long as i have elements in array
    {
        pivot = Partition(A, low, high); // splits array
        QuickSort(A, low, pivot - 1);    // abel l nos
        QuickSort(A, pivot + 1, high);   // baaed el nos
    }
}


void sort(int A[], int N)
{
    QuickSort(A, 0, N - 1);
} // O(nlogn) if pivot is at beginning or end

// pivot could stay at the index 0 if all of the elements are > than it
// thus on left sublist wouldnt execute since left>right
