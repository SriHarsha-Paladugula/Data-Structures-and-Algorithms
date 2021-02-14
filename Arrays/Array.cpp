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
        void Display();
        void Append(T element);
        void Insert(int index, T element);
        T Delete(int index);
        int LinearSearch (T element);
        int BinarySearch (T element);
        T Get(int index);
        void Set(int index, T element);
        T Min();
        T Max();
        T Sum();
        T Avg();
        void Reverse();
        void swap(T *x, T *y);
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
void Array<T>::Display()
{
    cout<<"Elements in array are :";
    for(int i=0; i<length; i++)
        cout<<A[i]<<" ";
    cout << endl;    
}

template<class T>
void Array<T>::Append(T element)
{
    if(length < size)
    {
        A[length] = element;
        length += 1;
    }
}

template<class T>
void Array<T>:: Insert(int index, T element)
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
T Array<T>::Delete(int index)
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

template<class T>
T Array<T>::Get(int index)
{
    if (index>=0 && index < length)
        return A[index];
    cout<<"Invalid Index"<<endl;    
}

template<class T>
void Array<T>::Set(int index, T element)
{
    if (index>=0 && index < length)
        return A[index] = element;
    cout<<"Invalid Index"<<endl;    
}

template<class T>
T Array<T>::Min()
{
    T min = A[0];
    for (int i=1; i<length; i++)
    {
        if (A[i] < A[0])
            min = A[i];
    }
    return min;
}

template<class T>
T Array<T>::Max()
{
    T max = A[0];
    for (int i=1; i<length; i++)
    {
        if (A[i] > A[0])
            max = A[i];
    }
    return max;
}

template<class T>
T Array<T>::Sum()
{
    T sum = 0;
    for (int i=0; i<length; i++)
            sum += A[i];
    return sum;
}

template<class T>
T Array<T>::Avg()
{
   return (float)Sum()/length;
}

template<class T>
void Array<T>::swap(T *x,T *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}

template<class T>
void Array<T>::Reverse()
{
    int i=0;
    int j=length-1;
   while(i<j)
   {
        swap(&A[i], &A[j]);
        i++;
        j--;
   }
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
        arr1.Append(x);
    }

    arr1.getLength();
    arr1.Display();

    arr1.Append(7);
    arr1.Display();

    //Index value input should start from zero i.e for example you want to add at 6th pos in array index should be 5
    arr1.Insert(5, 6);
    arr1.Display();

    //Index value input should start from zero i.e for example you want to delete at 6th pos in array index should be 5
    cout << "deleted element is : " << arr1.Delete(3) << endl;
    arr1.Display();

    cout << "The index of the search key in linear search is : " << arr1.LinearSearch(5.9) <<endl;
    
    //Note that for binary search to work array must be in sorted order
    cout << "The index of the search key in binary search is : " << arr1.BinarySearch(6) <<endl;

    cout << "The Minimum value of Array is : " << arr1.Min() <<endl;
    cout << "The Maximum value of Array is : " << arr1.Max() <<endl;
    cout << "The Sum of all elements  of Array is : " << arr1.Sum() <<endl;
    cout << "The Average of all elements  of Array is : " << arr1.Avg() <<endl;

    //reverse the elemens in the array
    arr1.Reverse();
    cout << "Array after reversing of its elements are: \n" ;
    arr1.Display();

    return 0;
};

