#include<iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(Array arr)
{
    cout<<"Elements in array are :";
    for(int i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
};

int main()
{
    struct Array arr;
    int n;
    cout << "Enter size of the array" << endl;
    cin >> arr.size;
    
    arr.A = new int[arr.size];
    arr.length = 0;
    
    cout<< "arr.size is : " << arr.size << endl;

    cout<<"Enter no. of numbers you need to add to the array"<< endl;;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cout <<"please enter " << i+1 << " number you wish to add to your array" << endl;
        cin >> arr.A[i];
    }

    arr.length = n;
    
    display(arr);

    delete[] arr.A;

    return 0;
};

