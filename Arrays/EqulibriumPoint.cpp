/*

Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).

*/

#include<iostream>
using namespace std;

/*
int left_sum(int arr[], int index, int len_array)
{
    int left_summation = 0;
    
    for(int i=index-1; i >=0 ; i--)
        left_summation += arr[i];
    
    return left_summation;
}

int right_sum(int arr[], int index, int len_array)
{
    int right_summation = 0;
    
    for(int j=index+1; j<len_array; j++)
        right_summation += arr[j];
    
    return right_summation;
}
*/

int equiibrium_point(int arr[], int len_array)
{
    if(len_array == 1)
        return 1;
    else
    {
        int total_sum=0;
        int left_sum=0;
        int right_sum=0;
        bool equiibrium_exists = false;
        
        /*
        for(int index=0; index<len_array; index++)
        {
            int left_summation =  left_sum(arr, index, len_array);
            int right_summation =  right_sum(arr, index, len_array);
            if(left_summation ==  right_summation)
                return index+1;
        }
        */
        
        for(int index=0; index<len_array; index++)
            total_sum += arr[index];
        
        //cout << "total_sum is :" << total_sum;    
        
        for(int index=1; index<len_array; index++)
        {
            left_sum = left_sum + arr[index-1];
            right_sum = total_sum -left_sum - arr[index];
            //cout<< "for index: "<<index<<" left sum is: " <<left_sum <<" right sum is: "<<right_sum<<endl; 
            if(left_sum == right_sum)
            {
                //cout<< "index is :"<<index<<endl;
                equiibrium_exists == true;
                return index+1;
                
            }
        }    
        
        if (!equiibrium_exists)    
            return -1;
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
        int res = equiibrium_point(arr,  n); //calling the function
        cout << res << endl;
    }
    return 0;
}

