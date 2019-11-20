/*

Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...

Note: O(1) extra space is allowed. Also, try to modify the input array as required.

Input:
First line of input conatins number of test cases T. First line of test case contain an integer denoting the array size N and second line of test case contain N space separated integers denoting the array elements.

Output:
Output the modified array with alternated elements.

Constraints:
1 <=T<= 100
1 <=N<= 107
1 <=arr[i]<= 107

Example:
Input:
2
6
1 2 3 4 5 6
11 
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60

Explanation:
Testcase 1: Max element = 6, min = 1, second max = 5, second min = 2, and so on... Modified array is : 6 1 5 2 4 3.

*/

#include<iostream>
#include <vector>
using namespace std;

long int* rearrange(long int arr[], long int n) 
{ 
    // initialize index of first minimum and first 
    // maximum element 
    long int max_idx = n - 1, min_idx = 0; 
  
    // store maximum element of array 
    long int max_elem = arr[n - 1] + 1; 
  
    // traverse array elements 
    for (long int i = 0; i < n; i++) { 
        // at even index : we have to put maximum element 
        if (i % 2 == 0) { 
            arr[i] += (arr[max_idx] % max_elem) * max_elem; 
            max_idx--; 
        } 
  
        // at odd index : we have to put minimum element 
        else { 
            arr[i] += (arr[min_idx] % max_elem) * max_elem; 
            min_idx++; 
        } 
    } 
  
    // array elements back to it's original form 
    for (long int i = 0; i < n; i++) 
        arr[i] = arr[i] / max_elem; 
        
    return arr;    
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
        long int n; //size of array
        cin>>n; //input array size
        long int arr[n]; //Declaring array of size n
        cout<<"please input your array elements followed by space as mentioned in array size "<<endl;
        for(long int i=0; i<n; i++) //input into array of n elements
            cin>>arr[i];

        cout<<"The result is :";
        long int* res = rearrange(arr,  n); //calling the function
        for(long int i=0; i<n; i++)
        {
            cout <<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}