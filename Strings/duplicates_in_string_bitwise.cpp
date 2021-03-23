#include <iostream>
#include <string>

using namespace std;

void duplicates_using_bitwise(string input)
{
    int H=0, X=0, result=0;
    for(int i=0; input[i] != '\0'; i++)
    {
        X = 1;
        X = X << input[i] -97;
        result = X & H;
        if (result > 0)
            cout << input[i] << " is duplicate in the given string" << endl;
        else
            H = X | H;    
    }
}

int main()
{
    string input_string;
    cout << "Please input your string which you wish to check for duplicates in lowercase" << endl;
    getline(cin, input_string);
    duplicates_using_bitwise(input_string);
    return 0;
}