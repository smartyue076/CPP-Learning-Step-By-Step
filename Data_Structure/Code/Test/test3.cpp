int paritition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void quick_sort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = paritition(A, low, high);
        quick_sort(A, low, pivot - 1);
        quick_sort(A, pivot + 1, high);
    }
}