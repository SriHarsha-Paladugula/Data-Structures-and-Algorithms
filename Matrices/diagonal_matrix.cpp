#include <iostream>

using namespace std;

template<typename T>
class DiagonalMatrix
{
    private:
        int n;
        T *data_array;
    public:
        DiagonalMatrix(int n)
        {
            this->n = n;
            data_array = new T[n];
        }
        void set(int i, int j, T data);
        T get(int i, int j);
        void display();
        ~ DiagonalMatrix()
        {
            delete []data_array;
        }
};

template<class T>
void DiagonalMatrix<T>::set(int i, int j, T data)
{
    if(i == j)
        data_array[i-1] = data;
}

template<class T>
T DiagonalMatrix<T>::get(int i, int j)
{
    if(i == j)
        return data_array[i-1];
    else
        return 0;    
}

template<class T>
void DiagonalMatrix<T>::display()
{
   for(int i=0; i< n; i++)
   {
       for(int j=0; j<n; j++)
       {
            if(i==j)
                cout<<data_array[i]<<" ";
            else
                cout<<"0 ";
       }
       cout<<endl;
   }
}

int main()
{
    DiagonalMatrix<int> d(4);
    d.set(1,1,5);
    d.set(2,2,5);
    d.set(3,3,5);
    d.set(4,4,5);
    d.display();
    return 0;
}