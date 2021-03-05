#include <iostream>
#include <string>

using namespace std;

void reverse(string input)
{
    int i = 0;
    char temp;

    for ( i=0; input[i] != '\0'; i++)
    {
    }
    i = i-1;
    for (int j=0; j <i; j++, i--)
    {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
    }
    cout << " reverse of your input string is : " << input << endl;
}
int main()
{
    string s;
    cout << "Please input your string" << endl;
    getline(cin, s);
    reverse(s);
    
    return 0;
}