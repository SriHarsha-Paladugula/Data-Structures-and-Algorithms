#include <iostream>>

using namespace std;

struct Element
{
    int row;
    int col;
    int element;
};

class SparseMatrix
{
    int rows;
    int cols;
    int num_of_elements;
    Element *e;

    public:
        SparseMatrix(int m, int n, int num)
        {
            rows = m;
            cols = n;
            num_of_elements = num;
            e = new Element[num];
        }
        ~SparseMatrix()
        {
            delete[] e;
        }
        SparseMatrix operator+(SparseMatrix &sm);
        friend istream& operator>>(istream &is, SparseMatrix &sm);
        friend ostream& operator<<(ostream &os, SparseMatrix &sm);
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &sm)
{
    int i,j,k; 
    if(rows!=sm.rows || cols!=sm.cols)
        return SparseMatrix(0,0,0);
    SparseMatrix *sum = new SparseMatrix(rows, cols, num_of_elements+sm.num_of_elements);
    i=j=k=0;
    while(i<num_of_elements && j<sm.num_of_elements)
    {
        if(e[i].row < sm.e[j].row)
        {
            sum->e[k++] = e[i++];
        }
        else if(e[i].row > sm.e[j].row)
        {
            sum->e[k++] = sm.e[j++];
        }
        else
        {
            if(e[i].col < sm.e[j].col)
            {
                sum->e[k++] = e[i++];
            }
            else if (e[i].col > sm.e[j].col)
            {
                sum->e[k++] = sm.e[j++];
            }
            else
            {
                sum->e[k] = e[i];
                sum->e[k++].element = sm.e[j++].element + e[i++].element;
            }
        }
    }

    for(;i<num_of_elements;i++)
    {
        sum->e[k++] = e[i];
    }
    for(;j<sm.num_of_elements;j++)
    {
        sum->e[k++] = sm.e[j];
    }
    sum->num_of_elements = k;

    return *sum;
}

istream& operator>>(istream &is, SparseMatrix &sm)
{
    cout<<"Enter Non Zero Elements"<< endl;
    for(int i=0; i<sm.num_of_elements; i++)
    {
        cin >> sm.e[i].row >> sm.e[i].col >> sm.e[i].element;
    }
    return is;
}

ostream& operator<<(ostream &os, SparseMatrix &sm)
{
    int k=0;
    for(int i=0; i<sm.rows; i++)
    {
        for(int j=0; j<sm.cols; j++)
        {
            if(sm.e[k].row == i && sm.e[k].col==j)
                cout<<sm.e[k++].element<<" ";
            else
                cout <<"0 ";    
        }
        cout<<"\n";
    }
    return os;
}

int main()
{
    SparseMatrix sm(5,5,5);
    cin>>sm;
    cout<<sm<<endl;
    SparseMatrix sm2(5,5,5);
    cin>>sm2;
    cout<<sm2<<endl;
    SparseMatrix sum = sm+sm2;
    cout<<sum;
    return 0;
}