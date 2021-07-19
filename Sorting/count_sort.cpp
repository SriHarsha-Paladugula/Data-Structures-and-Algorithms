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

int findMax(int A[], int n)
{
    int max = INT32_MIN;
    for(int i=0; i<n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}
void CountSort(int A[], int n)
{
    int i, j, max;
    max = findMax(A, n);
    int *count = new int[max];
    for(i=0; i<max+1; i++)
        count[i] = 0;
    for(i=0; i<n; i++)
        count[A[i]]++;
    
    i=0, j=0;
    while (i < max+1)
    {
        if(count[i] > 0)
        {
            A[j++] = i;
            count[i]--;
        }
        else
            i++;
    }
}

int main()
{
     int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\tA");
    CountSort(A, n);
    Print(A, n, " Sorted A");
    return 0;
}