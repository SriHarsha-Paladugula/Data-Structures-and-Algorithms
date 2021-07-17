#include<iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++)
    {
        cout << vec[i] << flush;
        if (i < n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    do
    {
       do{i++;} while (A[i] <= pivot);
       do{j--;} while (A[j] > pivot);
        if(i < j)
            swap(A[i], A[j]);
    } while (i < j);
    swap(A[low], A[j]);
    return j;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = partition(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j+1, high);
    }
}

int main()
{
    cout << "Using INT_MAX or Infinity" << endl;
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n-1, "\tA");
 
    QuickSort(A, 0, n-1);
    Print(A, n-1, " Sorted A");
    cout << endl;

    return 0;
}