/*
Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
Structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.



Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks.

User Task:
The task is to complete the function trappingWater() which returns the total amount of water that can be trapped.

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.*/

#include<iostream>
using namespace std;

int trappingWater(int arr[], int n)
{
    // Your code here
    int water = 0;
    int left[n] ;
    int right[n] ;
    //filling the left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1],arr[i]);
    }
    //filling the right array
    right[n-1] = arr[n-1];
    for (int i = n-2; i >=0; i--)
    {
        right[i] = max(right[i+1], arr[i]);
    }
    //Calculating the accumulated water
    for (int i = 0; i < n; i++)
    {
        water += min(left[i],right[i]) - arr[i];
    }
    return water;
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
        int res = trappingWater(arr,  n); //calling the function
        cout << res << endl;
    }
    return 0;
}