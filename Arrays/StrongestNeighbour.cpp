/*
Given an array arr[] of N positive integers. The task is to find the maximum for every adjacent pairs in the array.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N, and next line contains N space separated integers denoting the array elements.

Output Format:
For each testcase, print the maximum for every adjacent pairs in the array.

Constraints:
1 <= T <= 100
2 <= N <= 106
1 <= arr[i] <= 106

User Task:
The task is to complete the function maximumAdjacent(), which takes sizeOfArray and array as parameters and prints the maximum of all adjacent pairs. The drivercode automatically adds a new line.

Example:
Input:
2
6
1 2 2 3 4 5
2
5 5

Output:
2 2 3 4 5
5

Explanation:
Testcase 1: Maximum of arr[0] and arr[1] is 2, that of arr[1] and arr[2] is 2, ... and so on. For last two elements, maximum is 5.
*/

#include <iostream>
using namespace std;


void maximumAdjacent(int sizeOfArray, int arr[])
{
    
    for(int index=0; index < sizeOfArray-1; index++)
    {
        if(arr[index] > arr[index+1])
        {
            cout<<arr[index]<<" ";
        }
        else
        {
            cout<<arr[index+1]<<" ";
        }
    }
     
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
        maximumAdjacent(n, arr); //calling the function 
         
    }
    return 0;
}