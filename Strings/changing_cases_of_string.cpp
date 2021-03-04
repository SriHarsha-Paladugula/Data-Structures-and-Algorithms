#include <iostream>
#include <string>

using namespace std;

string upper_to_lower(string input)
{
    for (int i=0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] += 32;
    }

    return input;
}

string lower_to_upper(string input)
{
    for (int i=0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
    }

    return input;
}

string toggle_cases(string input)
{
    for (int i=0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
        else if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] += 32;   
    }
    return input;
}

int main()
{
    string input_string;
    cout << "Please input your string" << endl;
    getline(cin, input_string);

    string lowercase = upper_to_lower(input_string);
    cout << "string in lowercase is : " << lowercase << endl;

    string uppercase = lower_to_upper(input_string);
    cout << "string in uppercase is : " << uppercase << endl;

    string togglecase = toggle_cases(input_string);
    cout << "string in togglecase is : " << togglecase << endl;

    return 0;
}