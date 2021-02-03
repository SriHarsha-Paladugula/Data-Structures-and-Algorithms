#include<iostream>
#include<chrono>

using namespace std;

auto power(int m, int n)
{
    if ( n==0)
        return 1;
    else
        if (n%2 == 0)
            return  power(m*m, n/2);  
        else
            return m * power(m*m, (n-1)/2);
}
int main()
{
    int m=5, n=5;

    auto start = chrono::high_resolution_clock::now();
    auto res = power(m, n);
    auto stop = chrono::high_resolution_clock::now();

    auto time_taken = chrono::duration_cast<chrono::microseconds>(stop-start).count();

    cout<<"power of " << m << " raised to "<<n <<" is : "<< res <<endl;
    cout<<"Time taken to execute the function is " << time_taken <<endl;
    return 0;
}