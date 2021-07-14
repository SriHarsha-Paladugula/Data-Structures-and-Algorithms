#include <iostream>
#include <vector>
using namespace std;

void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[i];

    while(i >0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    for (int i=0; i<n; i++)
        InsertInplace(A, i);
}
 
template <class T>
void Print(T& vec, int n, char c)
{
    cout << c << ": [" << flush;
    for (int i=0; i<n; i++)
    {
        cout << vec[i] << flush;
        if (i < n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
}

int DeleteHeap(int A[], int n)
{
    int x, i, j, val;
    
    val=A[0]; 
    x=A[n]; 
    A[0]=A[n]; 
    A[n]=val; 

    i = 0;
    j = 2*i+1;

    while(j <= n-1)
    {
        if(j<n-1 && A[j] < A[j+1])
            j = j+1;
        
        if(A[i] < A[j])
        {
            swap(A[i], A[j]);
            i=j;
            j=2*j;
        }
        else
            break;    
    }
    return val;
}

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--)
    {
        int j = 2 * i + 1;  // Left child for current i
        while(j < n-1)
        {
            // Compare left and right children of current i
            if (A[j] < A[j+1])
                j = j+1;
 
            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
                i = j;
                j = 2 * i + 1;
            } 
            else 
                break;
        }
    }
}

int main()
{
    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    Print(b, sizeof(b)/sizeof(b[0]), 'b');
 
    cout << "Inplace Insert" << endl;
    createHeap(b, sizeof(b)/sizeof(b[0]));
    Print(b, sizeof(b)/sizeof(b[0]), 'b');

    int n = sizeof(b)/sizeof(b[0]);
    for(int i=n-1; i>0; i--)
        DeleteHeap(b, i);
    Print(b, sizeof(b)/sizeof(b[0]), 'b');

    cout << "Heapify Insert" << endl;
    Heapify(b, sizeof(b)/sizeof(b[0]));
    Print(b, sizeof(b)/sizeof(b[0]), 'b');
    for(int i=n-1; i>0; i--)
        DeleteHeap(b, i);
    Print(b, sizeof(b)/sizeof(b[0]), 'b');

    return 0;
}