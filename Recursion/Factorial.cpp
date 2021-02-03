#include<iostream>
#include<chrono>

using namespace std;

auto fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);    
}

auto Ifact(int n)
{
    int f=1;
    for (int i=1; i<=n; i++)
    {
        f = f*i;
    }
    return f;
}
int main()
{
    int n=10;

    auto start = chrono::high_resolution_clock::now();
    auto res = fact(n);
    auto stop = chrono::high_resolution_clock::now();

    auto time_taken = chrono::duration_cast<chrono::microseconds>(stop-start).count();

    cout<<"Factorial of "<< n << " is " <<res <<endl;
    cout<<"Time taken to execute the function is " << time_taken <<endl;

    return 0;
}