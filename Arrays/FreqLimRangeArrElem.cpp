/*
Given an array A[] of N positive integers which can contain integers from 1 to N where elements can be repeated or can be absent from the array. Your task is to count frequency of all elements from 1 to N.

Note: Expected time complexity is O(n) with O(1) extra space.

Input Format:
First line of input contains an integer T denoting the number of test cases. For each test case, first line contains an integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output Format:
For each test case, output N space-separated integers denoting the frequency of each element from 1 to N.

Your Task:
You need to complete the function printfrequency and print frequency of each element. The newline is automatically added by the driver code.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 <= A[i] <= 106

Example:
Input:
2
5
2 3 2 3 5
4
3 3 3 3

Output:
0 2 2 0 1
0 0 4 0

Explanation:
Testcase 1: Counting frequencies of each array elements, we have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.
*/

#include <iostream>

using namespace std;

void printfrequency(int arr[], int n)
{ 
	// Your code herre
	for(int i=0; i < n; i++)
	{
	   arr[i] -= 1; //Shift all elements by 1 so that {1,n} become {0,n-1}
	   arr[arr[i]%n] += n; //For all elements arr[i]%n gives the value at which index is added with n for every occurrence of the value.
	}
	for(int i=0; i < n; i++)
	{
	   cout << i+1 << " is occuring " << arr[i]/n <<" times."<<endl;//Print out the freq. as it is clearly the number of times n was added.
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

        cout<<"The result is :"<<endl;
        printfrequency(arr,  n); //calling the function
        cout <<endl;
         
    }
    return 0;
}