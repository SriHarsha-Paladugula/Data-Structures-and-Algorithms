/*
Given an array arr[] of size N of positive integers which may have duplicates. The task is to find maximum and second maximum from the array, which must be distinct. If no second max exists, then second max will be -1.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N, next line contains array elements.

Output Format:
For each testcase, print the maximum and second maximum from the array. IF no second max exists, print "-1" for second max.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

User Task:
The task is to complete the function largestAndSecondLargest(), which should print maximum and second maximum element from the array.

Example:
Input:
2
5
1 2 3 4 5
3
2 1 2

Output:
5 4
2 1

Explanation:
Testcase 1: From the given array elements, 5 is the largest and 4 is the second largest.
Testcase 2: From the given array elements, 2 is the largest and 1 is the second largest.
*/

#include <iostream>
using namespace std;

void largestAndSecondLargest(int sizeOfArray, int arr[])
{
    int max = -1, max2= -1;
    for(int index=0; index<sizeOfArray; index++)
    {

        if (arr[index]<max && arr[index]>max2)
        {
            max2=arr[index];
        }
        else if (arr[index]>max)
        {
            max2=max;
            max=arr[index];
        }
    }
     
     cout << "First Maximum is : " << max << " Second Maximum is: " << max2 << endl;
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

        largestAndSecondLargest(n, arr); //calling the function   
    }
    return 0;
}