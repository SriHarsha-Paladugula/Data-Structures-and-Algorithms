#include<iostream>

using namespace std;
template<class T>
class Array
{
    private:
        T *A;
        int size;
        int length;
    public:
        Array()
        {
            size = 10;
            A = new T[size];
            length = 0;
        }
        Array(int sz)
        {
            size = sz;
            A = new T[size];
            length = 0;
        }
        ~Array()
        {
            delete []A;
        }
        void setSize(int sz);
        void getSize();
        void getLength();
        void display();
        void append(T element);
        void add(int index, T element);
        T del(int index);
        int LinearSearch (T element);
        int BinarySearch (T element);
};

template<class T>
void Array<T>::setSize(int sz)
{
    if (length==0)
        size=sz;
    else
        cout<<"To set the Size of the Array, array should be empty"<<endl;    
}

template<class T>
void Array<T>::getSize()
{
    cout<<"To  Size of the Array is : "<< size << endl;    
}

template<class T>
void Array<T>::getLength()
{
    cout<<"To  length of the Array is : "<< length << endl;    
}

template<class T>
void Array<T>::display()
{
    cout<<"Elements in array are :";
    for(int i=0; i<length; i++)
        cout<<A[i]<<" ";
    cout <<"\n Length of the array is :"<< length << endl;    
}

template<class T>
void Array<T>::append(T element)
{
    if(length < size)
    {
        A[length] = element;
        length += 1;
    }
}

template<class T>
void Array<T>:: add(int index, T element)
{
    if(index >=0 && index <= length)
    {
        for(int i=length; i>index; i--)
            A[i] = A[i-1];
        A[index] = element;
        length += 1;
    }
}

template<class T>
T Array<T>::del(int index)
{
    int x= A[index];
    if(index >=0 && index < length)
    {
        for(int i=index; i< length-1; i++)
            A[i] = A[i+1];
        length--;    
    }
    return x;
}

template<class T>
int Array<T>::LinearSearch (T element)
{
    for(int i=0; i< length; i++)
        if (A[i] == element)
            return i;
    return -1;        
}

template<class T>
int Array<T>::BinarySearch (T element)
{
    int low=0, high=length, mid; 
    while ( low <= high)
    {
        mid = (high + low)/2;
        if(A[mid] == element)
            return mid;
        else if (element > A[mid])
            low = mid+1;
        else
            high = mid-1;               
    }
    return -1;
}

int main()
{
    Array<float> arr1;
    int n, sz;
    float x;
    cout << "Enter size of the array" << endl;
    cin >> sz;

    arr1.setSize(sz);

    arr1.getSize();

    cout<<"Enter no. of numbers you need to add to the array"<< endl;;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cout <<"please enter " << i+1 << " number you wish to add to your array" << endl;
        cin >> x;
        arr1.append(x);
    }

    arr1.getLength();
    arr1.display();

    arr1.append(7);
    arr1.display();

    //Index value input should start from zero i.e for example you want to add at 6th pos in array index should be 5
    arr1.add(5, 6);
    arr1.display();

    //Index value input should start from zero i.e for example you want to delete at 6th pos in array index should be 5
    cout << "deleted element is : " << arr1.del(3) << endl;
    arr1.display();

    cout << "The index of the search key in linear search is : " << arr1.LinearSearch(5.9) <<endl;
    
    //Note that for binary search to work array must be in sorted order
    cout << "The index of the search key in binary search is : " << arr1.BinarySearch(6) <<endl;

    return 0;
};

