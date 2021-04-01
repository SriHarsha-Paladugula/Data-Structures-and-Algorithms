#include <iostream>

using namespace std;

template<typename T>
class UpperTriangularMatrix
{
    private:
        int n;
        T* data_array;
    public:
        UpperTriangularMatrix(int n)
        {
            this->n = n;
            data_array = new T[n*(n+1)/2];
        }
        void set_row_major(int i, int j, T data);
        T get_row_major(int i, int j);
        void display_row_major();
        void set_col_major(int i, int j, T data);
        T get_col_major(int i, int j);
        void display_col_major();
        ~ UpperTriangularMatrix()
        {
            delete[] data_array;
        }
};


template<class T>
void UpperTriangularMatrix<T>::set_row_major(int i, int j, T data)
{
    if(j >= i)
        data_array[n*(i-1)-(i-2)*(i-1)/2+ (j-i)] = data;
}

template<class T>
T UpperTriangularMatrix<T>::get_row_major(int i, int j)
{
    if(j >= i)
        return data_array[n*(i-1)-(i-2)*(i-1)/2+ (j-i)];
    else
        return 0;    
}

template<class T>
void UpperTriangularMatrix<T>::display_row_major()
{
   for(int i=1; i<=n; i++)
   {
       for(int j=1; j<=n; j++)
       {
            if(j>=i)
                cout<< data_array[n*(i-1)-(i-2)*(i-1)/2+ (j-i)]<<" ";
            else
                cout<<"0 ";
       }
       cout<<endl;
   }
}

template<class T>
void UpperTriangularMatrix<T>::set_col_major(int i, int j, T data)
{
    if(j >= i)
        data_array[j*(j-1)/2 + (i-1)] = data;
}

template<class T>
T UpperTriangularMatrix<T>::get_col_major(int i, int j)
{
    if(j >= i)
        return  data_array[j*(j-1)/2 + (i-1)];
    else
        return 0;    
}

template<class T>
void UpperTriangularMatrix<T>::display_col_major()
{
    for(int i=1; i<=n; i++)
   {
       for(int j=1; j<=n; j++)
       {
            if(j>=i)
                cout<< data_array[j*(j-1)/2 + (i-1)]<<" ";
            else
                cout<<"0 ";
       }
       cout<<endl;
   }
}


int main()
{
    int size_of_matrix, data;
    cout <<"Please enter the size of the upper triangular matrix you wish to generate" << endl;
    cin >> size_of_matrix;
    UpperTriangularMatrix<int> d(size_of_matrix);
    for(int i=1; i<=size_of_matrix; i++)
    {
        for(int j=1; j<=size_of_matrix; j++)
        {
            cin>>data;
            d.set_row_major(i, j, data);
        }
    }
    cout << "\n";
    d.display_row_major();
    return 0;
}