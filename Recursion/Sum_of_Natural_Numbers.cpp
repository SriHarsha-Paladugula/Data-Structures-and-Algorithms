#include<iostream>
#include<chrono>

using namespace std;

long long Sum_Of_NaturalNumbers(long long n)
{
    if(n==0)
        return 0;
    else
        return Sum_Of_NaturalNumbers(n-1)+n;
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    long long  n = 20000;
    long long sum = 0;
    sum = Sum_Of_NaturalNumbers(n);

    auto stop = std::chrono::high_resolution_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count(); 
  
    cout <<" sum of first "<< n << " Natural numbers is : " << sum <<endl;

    // To get the value of duration use the count() member function on the duration object 
    cout << "Time taken by function: " << duration<< " microseconds" << endl;
    
    return 0;
}