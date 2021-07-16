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

void selection_sort(int A[], int n)
{
    int j,k;
    for(int i=0; i<n-1; i++)
    {
        j=k=i;
        while(j<n-1)
        {
            if(A[j+1] < A[j])
                k=j+1;

            j++;    
        }
        swap(A[i], A[k]);
    }
}

int main()
{
    int A[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    Print(A, sizeof(A)/sizeof(A[0]), "       A");
 
    selection_sort(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]), "Sorted A");
    return 0;
}