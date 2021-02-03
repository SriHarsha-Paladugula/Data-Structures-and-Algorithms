#include<iostream>
#include<chrono>

using namespace std;

const int n=11;
int F[n+1];

int fibnocci(int n)
{
    if (n<=1)
    {
        F[n] =n;
        return n;
    }
    else
    {
        if(F[n-2] == -1)
            F[n-2] = fibnocci(n-2);
        if(F[n-1] == -1)
            F[n-1] = fibnocci(n-1);
        F[n] =  F[n-2]+F[n-1];  
        return F[n-2]+F[n-1];        
    }
}

int main()
{
    for(int i=0; i<n; i++)
        F[i] = -1;
    
    auto start = chrono::high_resolution_clock::now();
    int res =  fibnocci(n);   
    auto stop = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::microseconds>(stop-start).count();

    cout <<"The fibnocci series with " << n << "th term is " << res <<endl;
    cout <<"Time taken for execution of this function is "<< time_taken <<endl;
    return 0;
}