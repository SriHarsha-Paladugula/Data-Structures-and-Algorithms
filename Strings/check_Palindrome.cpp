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

string reverse(string input1)
{
    int length;
    for(length=0; input1[length] != '\0'; length++){}

    string reverse_string = input1;

    for(int i=length-1, j=0; i > 0, j < length; i--, j++)
    {
        reverse_string[j] =input1[i];
    }
    reverse_string[length] = '\0';
    cout << "reverse of your string is :" << reverse_string << endl;
    return reverse_string;
}

bool check_palindrome(string input1)
{
    string reverse_string = reverse(input1);
    return compare(input1, reverse_string);
}

int main()
{
    string input1;
    cout << "Please input your first string to compare" << endl;
    cin >> input1;
    if (check_palindrome(input1))
        cout << "Your input is a palindrome" << endl;
    else
        cout << "Your input is not a palindrome" << endl;   
    return 0;
}