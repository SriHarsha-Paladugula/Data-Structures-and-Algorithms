#include <iostream>
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

void BubbleSort(int A[], int n)
{
    int flag;
    for(int i=0; i<n-1; i++)
    {
        flag = 0;
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
                flag =1;
            }
        }
        if(flag == 0)
            break;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, "A");
 
    BubbleSort(A, n);
    Print(A, n, "Sorted A");
 
    return 0;
}