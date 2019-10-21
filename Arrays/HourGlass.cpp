#include <iostream>
#include <vector>

using namespace std;
/*
Given a  2D Array, :

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
We define an hourglass in  to be a subset of values with indices falling in this pattern in 's graphical representation:

a b c
  d
e f g
There are  hourglasses in , and an hourglass sum is the sum of an hourglass' values. Calculate the hourglass sum for every hourglass in , then print the maximum hourglass sum.

For example, given the 2D array:

-9 -9 -9  1 1 1 
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0
We calculate the following  hourglass values:

-63, -34, -9, 12, 
-10, 0, 28, 23, 
-27, -11, -2, 10, 
9, 17, 25, 18
Our highest hourglass value is  from the hourglass:

0 4 3
  1
8 6 6
Note: If you have already solved the Java domain's Java 2D Array challenge, you may wish to skip this challenge.

Function Description

Complete the function hourglassSum in the editor below. It should return an integer, the maximum hourglass sum in the array.

hourglassSum has the following parameter(s):

arr: an array of integers
Input Format

Each of the  lines of inputs  contains  space-separated integers .

Constraints

-9<=a[i][j]<=9
0<=i,j<=5

Output Format

Print the largest (maximum) hourglass sum found in array.
*/

int hourglassSum(vector<vector<int>> input)
{
    int max = -100;
    for(int i=1; i<6; i+3)
    {
        int hourglass_up,hourglass_middle,hourglass_bottom,hourglass=0;
        for(int j=1; j<6; j+3)
        {
            hourglass_up = input[i-1][j-1]+ input[i-1][j]+ input[i-1][j+1];
            hourglass_middle = input[i][j];
            hourglass_bottom = input[i+1][j-1]+ input[i+1][j]+ input[i+1][j+1];
            hourglass = hourglass_up + hourglass_middle + hourglass_bottom;
            if(hourglass > max)
                max = hourglass;
        }
    }
    return max;
}

int main()
{

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
