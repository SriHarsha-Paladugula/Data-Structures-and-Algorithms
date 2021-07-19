#include <iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void merge(int A[], int low, int mid, int high)
{
    int i,j,k;
    int B[100];
    i = low, j=mid+1; k=low;
    while(i <= mid && j<= high)
    {
        if(A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];    
    }
    for(;i <=mid; i++)
        B[k++] = A[i];
    for(;j <=high; j++)
        B[k++] = A[j];    

    for(int i=low; i<=high; i++)
        A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
    int p,i,low,mid,high;
    for(p=2; p<=n; p=p*2)
    {
        for(i=0; i+p-1 < n; i=i+p)
        {
            low = i;
            high = i+p-1;
            mid = (low + high)/2;
            merge(A, low, mid, high);
        }
    }
    if(p/2 < n)
        merge(A,0,p/2-1,n-1);
}

void RMergeSort(int A[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        RMergeSort(A, low, mid);
        RMergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}
int main()
{
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, " \tA");
    IMergeSort(A, n);
    Print(A, n, "ISorted A");
    RMergeSort(A, 0, n-1);
    Print(A, n, "RSorted A");
 
    return 0;
}