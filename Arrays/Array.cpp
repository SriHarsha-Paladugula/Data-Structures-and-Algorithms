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

    cout <<"\n Length of the array is :"<< arr.length << endl;    
};

void append(Array *arr, int element)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = element;
        arr->length += 1;
    }
    
};

void add(Array *arr, int index, int element)
{
    if(index >=0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        
        arr->A[index] = element;
        arr->length += 1;
    }
};

int del(Array *arr, int index)
{
    int x= arr->A[index];

    if(index >=0 && index < arr->length)
    {
        for(int i=index; i< arr->length-1; i++)
            arr->A[i] = arr->A[i+1];

        arr->length--;    
    }
    return x;
};

int LinearSearch (Array arr, int key)
{
    for(int i=0; i< arr.length; i++)
        if (arr.A[i] == key)
            return i;

    return -1;        
};

int BinarySearch (Array arr, int key)
{
    int low=0, high=arr.length, mid; 
    while ( low < high)
    {
        mid = (high + low)/2;

        if(arr.A[mid] == key)
            return mid;
        else if (key > arr.A[mid])
            low = mid+1;
        else
            high = mid-1;               
    }
    return -1;
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

    append(&arr, 7);
    display(arr);

    //Index value input should start from zero i.e for example you want to add at 6th pos in array index should be 5
    add(&arr, 5, 6);
    display(arr);

    //Index value input should start from zero i.e for example you want to delete at 6th pos in array index should be 5
    cout << "deleted element is : " << del(&arr, 3) << endl;
    display(arr);

    cout << "The index of the search key in linear search is : " << LinearSearch(arr, 5) <<endl;
    
    //Note that for binary search to work array must be in sorted order
    cout << "The index of the search key in binary search is : " << BinarySearch (arr,  8) <<endl;

    delete[] arr.A;

    return 0;
};

