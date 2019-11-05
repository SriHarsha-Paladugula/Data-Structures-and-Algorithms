/*Given an array of positive integers. Your task is to find the leaders in the array.

Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

User Task:
The task is to complete the function leader() which returns an array of leaders in same order as they appear in the array. The printing is automatically done by driver code.

Constraints:
1 <= T <= 100
1 <= N <= 107
0 <= Ai <= 107

Example:
Input:
4
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
3
4 1 4

Output:
17 5 2
4 0
7 7 3
4 4

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7. Also, all the elements of right side of 7 (at index 3) are smaller than 7. 
And, the last element 3 is itself a leader since no elements are on its right.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> leaders(int arr[], int n)
{

     vector<int> res = {};
     //Not efficient sol as complexity is O(N**2)
     /*
     for(int i=0; i<n; i++)
     {  
        bool flag = false; 
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] < arr[j])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
            res.push_back(arr[i]);
     }
     return res;*/

     int max = arr[n-1];
     res.push_back(max); // last element is always a leader since there is no value to its right
     for (int i=n-2; i >=0; i--)
     {
         if (arr[i] >= max)
         {
            res.insert(res.begin(), arr[i]); //inserting the max value at the start of the vector
            max = arr[i];
         }
     }
     return res;
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
        vector<int> res = leaders(arr,  n); //calling the function
        for(int i=0; i<res.size(); i++)
        {
            cout <<res[i]<<" ";
        } 
         
    }
    return 0;
}