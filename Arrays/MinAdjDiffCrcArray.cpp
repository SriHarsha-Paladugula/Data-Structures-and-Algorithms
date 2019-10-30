/*
Given an array Arr of N integers arranged in a circular fashion. Your task is to find the minimum absolute difference between adjacent elements.

Input:
The input line contains T, denoting the number of testcases. Each testcase contains two lines. The first line contains N(size of array). The second line contains N elements of array separated by space.

Output:
For each testcase in new line print the minimum absloute difference.

User Task:
The task is to complete the function minAdjDiff() which returns the minimum difference between adjacent elements in circular array.

Constraint:
1 <= T <= 100
2 <= N <= 106
-106 <= Arr[i] <= 106

Example:
Input:
3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1

Output:
4
1
0

Explanation:
Testcase 1: The absolute difference between adjacent elements in the given array are as such: 16 17 18  19 21 23 4. Among the calculated absolute difference the minimum is 4.
 */
#include <iostream>
#include<math.h>

using namespace std;

int minAdjDiff(int arr[], int n)
{    
    // Your code here
    int min_abs_diff = abs(arr[0]-arr[1]),k;
    if(arr[0] == arr[n-1])
        return 0;
    for(int i=1; i<n; i++)
    {
        k = i+1;
        if( k >= n)
            k=0;
        if(min_abs_diff > abs(arr[i]-arr[k]))
                min_abs_diff = abs(arr[i]-arr[k]);
    }
    return min_abs_diff;
}

int main()
{
    int t,count=0; //testcases
    cout<<"please input number of test cases you want to execute"<<endl;
    cin>>t; //input the test cases
    while (t--)
    {
        count++;
        cout<<"\nplease  input the size of the array for your "<< count << " tets case"<< endl;
        int n; //size of array
        cin>>n; //input array size
        int arr[n]; //Declaring array of size n
        cout<<"please input your array elements followed by space as mentioned in array size "<<endl;
        for(int i=0; i<n; i++) //input into array of n elements
            cin>>arr[i];

        cout<<"The result is :";
        cout<<minAdjDiff(arr,  n)<<endl; //calling the function 
         
    }
    return 0;
}