#include <iostream>

using namespace std;

template<typename T>
class LowerTriangularMatrix
{
    private:
        int n;
        T *data_array;
    public:
        LowerTriangularMatrix(int n)
        {
            this->n = n;
            data_array = new T[n*(n+1)/2];
        }
        void set_row_major(int i, int j, T data);
        T get_row_major(int i, int j);
        void display_row_major();
        /*void set_col_major(int i, int j, T data);
        T get_col_major(int i, int j);
        void display_col_major();*/
        ~ LowerTriangularMatrix()
        {
            delete []data_array;
        }
};


template<class T>
void LowerTriangularMatrix<T>::set_row_major(int i, int j, T data)
{
    if(i >= j)
        data_array[i*(i-1)/2 + (j-1)] = data;
}

template<class T>
T LowerTriangularMatrix<T>::get_row_major(int i, int j)
{
    if(i >= j)
        return  data_array[i*(i-1)/2 + (j-1)];
    else
        return 0;    
}

template<class T>
void LowerTriangularMatrix<T>::display_row_major()
{
   for(int i=1; i<=n; i++)
   {
       for(int j=1; j<=n; j++)
       {
            if(i>=j)
                cout<< data_array[i*(i-1)/2 + (j-1)]<<" ";
            else
                cout<<"0 ";
       }
       cout<<endl;
   }
}

/*
template<class T>
void LowerTriangularMatrix<T>::set_col_major(int i, int j, T data)
{
    if(i >= j)
        data_array[n*(j-1)+(j-2)*(j-1)/2+ (i-j)] = data;
}

template<class T>
T LowerTriangularMatrix<T>::get_col_major(int i, int j)
{
    if(i >= j)
        return data_array[n*(j-1)+(j-2)*(j-1)/2+ (i-j)];
    else
        return 0;    
}

template<class T>
void LowerTriangularMatrix<T>::display_col_major()
{
   for(int i=1; i<=n; i++)
   {
       for(int j=1; j<=n; j++)
       {
            if(i>=j)
                cout<< data_array[n*(j-1)+(j-2)*(j-1)/2+ (i-j)]<<" ";
            else
                cout<<"0 ";
       }
       cout<<endl;
   }
}
*/

int main()
{
    int size_of_matrix, data;
    cout <<"Please enter the size of the lower triangular matrix you wish to generate" << endl;
    cin >> size_of_matrix;
    LowerTriangularMatrix<int> d(size_of_matrix);
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