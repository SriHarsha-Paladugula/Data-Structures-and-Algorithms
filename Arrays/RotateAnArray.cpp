/*

Given an unsorted array arr[] of size N, rotate it by D elements (counter-clockwise). 

Input: 
The first line of the input contains T denoting the number of testcases. First line of eacg test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

User Task:
The task is to complete the function rotate() which rotates the array by given D elements. The newline is automatically added by the driver code.

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105

Example:
Input:
2
5 2
1 2 3 4 5 
10 3
2 4 6 8 10 12 14 16 18 20

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6

Explanation :
Testcase 1: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
*/

#include <iostream>
using namespace std;

void rotateArr(int arr[], int d, int n)
{
   // Your code here
   int temp_arr[d] = {};
   for(int index=0; index<d; index++)
   {    
       temp_arr[index]=arr[index];
   }
   for(int index=0; index<n; index++)
   {    
       if(index < n-d)
            arr[index] = arr[index+d];
       else
            arr[index] = temp_arr[index-n+d];
   }
   for(int i=0; i<n; i++) 
            cout<<arr[i]<<" ";
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
        int n,d; //size of array
        cin>>n; //input array size
        cout<<"\nPlease input the size of rotation for this array "<<endl;
        cin>>d;
        int arr[n]; //Declaring array of size n
        cout<<"please input your array elements followed by space as mentioned in array size "<<endl;
        for(int i=0; i<n; i++) //input into array of n elements
            cin>>arr[i];

        cout<<"The result is :";
        rotateArr(arr, d, n); //calling the function 
         
    }
    return 0;
}