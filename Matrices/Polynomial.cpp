#include <iostream>

using namespace std;

struct Term
{
    int coef;
    int exp;
};

class Polynomial
{
    private:
        int n;
        Term *terms;
        
    public:
        Polynomial(int n);
        ~Polynomial();
        friend istream& operator>>(istream& is, Polynomial &p);
        friend ostream& operator<<(ostream& os, Polynomial &p);
        Polynomial operator+(Polynomial &p2);
};

Polynomial::Polynomial(int n)
{
    this->n = n;
    terms = new Term[n];
}

Polynomial::~Polynomial()
{
    delete []terms;
}
istream& operator>>(istream& is, Polynomial &p)
{
    for(int i=0; i<p.n; i++)
    {
        cout<<"Please input your "<< i+1 << " term" <<endl;
        cin>>p.terms[i].coef>>p.terms[i].exp;
    }
    return is;
}
ostream& operator<<(ostream& os, Polynomial &p)
{
    for(int i=0; i<p.n; i++)
    {
        if (i != p.n-1)
            cout << p.terms[i].coef << "x" << p.terms[i].exp <<" + ";
        else
            cout << p.terms[i].coef << "x" << p.terms[i].exp;     
    }
    cout<<"\n";
}
Polynomial Polynomial::operator+(Polynomial &p2)
{
    Polynomial sum(n+p2.n);
    int i=0,j=0,k=0;
    while(i<n && j<p2.n)
    {
        if(terms[i].exp > p2.terms[j].exp)
        {
            sum.terms[k++] = terms[i++];
        }
        else if(terms[i].exp < p2.terms[j].exp)
        {
            sum.terms[k++] = p2.terms[j++];
        }
        else
        {
            sum.terms[k] = terms[i];
            sum.terms[k++].coef = terms[i++].coef + p2.terms[j++].coef;
        }
    }
    for(;i<n;i++)
    {
        sum.terms[k++] = terms[i];
    }
    for(;j<p2.n;j++)
    {
        sum.terms[k++] = p2.terms[j];
    }
    sum.n = k;
    return sum;
}
int main()
{
    Polynomial p1(3);
    cin>>p1;
    cout<<p1<<endl;
    Polynomial p2(3);
    cin>>p2;
    cout<<p2<<endl;
    Polynomial sum = p1+p2;
    cout<<sum;
    return 0;
}