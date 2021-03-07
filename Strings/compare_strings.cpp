#include <iostream>
#include <string>

using namespace std;

bool compare (string input1, string input2)
{
    int i,j = 0;
    for(i=0,j=0; input1[i] != '\0' || input2[j] != '\0'; i++,j++ )
    {
        if(input1[i] != input2[j])
        {
            if (input1[i] < input2[j])
                cout << input1 << " string is smaller" << endl;
            else 
                cout << input2 << " string is smaller" << endl;
            return false;
        }
    }
    if (input1[i] == input2[j])
        cout << "Two strings are equal" << endl;
    return true;
}
int main()
{
    string input1, input2;
    cout << "Please input your first string to compare" << endl;
    cin >> input1;
    cout << "Please input your second string to compare" << endl;
    cin >> input2;
    compare(input1, input2);
    return 0;
}