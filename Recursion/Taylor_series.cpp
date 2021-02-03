#include<iostream>
#include<chrono>

using namespace std;

double e (int x, int n)
{
     static double s=0;

     if (n==0)
        return s;

     s = 1+x*s/n;

     return e(x, n-1);   
}
int main()
{
    int x=1, n=20;

    auto start = chrono::high_resolution_clock::now();
    double res = e(x, n);
    auto stop = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::microseconds>(stop -start).count();

    cout<<"Reult of e raise to the power of "<< x << " is : "<< res <<endl;
    cout<<"Time taken for function is : "<< time_taken << endl;

    return 0;
}