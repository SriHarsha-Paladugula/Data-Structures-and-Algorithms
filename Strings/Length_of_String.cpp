#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    cout << "Please input your string" << endl;
    getline(cin, s);
    int length;
    for (length=0; s[length] != '\0'; length++)
    {

    }
    cout << "Length of the string is : " << length << endl;
    cout << "The string is : "<< s << endl;
    return 0;
}