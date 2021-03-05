#include <iostream>
#include <string>

using namespace std;

bool validate_alphanumeric(string input)
{
    for(int i=0; input[i] != '\0'; i++)
    {
        if (!( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') ) )
            return false;
    }
    return true;
}

int main()
{
    string input;
    cout << "Please input your string for validation" << endl;
    getline(cin ,input);
    bool result = validate_alphanumeric(input);
    if (result)
        cout << "Your input is valid";
    else
        cout << "your input is invalid";
    return 0;
}