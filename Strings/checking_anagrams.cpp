#include <iostream>
#include <string>

using namespace std;

bool check_anagram(string input1, string input2)
{
    int H[26] = {0};
    if (input1.length() != input2.length())
        return false;
    else    
        for (int i=0; i<input1.length(); i++)   
            H[input1[i] -97] ++;
        for (int i=0; i<input2.length(); i++)
        {   
            H[input1[i] -97] --;
            if (H[input1[i] -97] == -1)
                return false; 
        }
        return true;    
}

int main()
{
    string input1, input2;
    cout << "Please input your First string in lower case" << endl;
    getline(cin, input1);
    cout << "Please input your Second string in lower case" << endl;
    getline(cin, input2);
    if (check_anagram(input1, input2))
        cout << "The two given strings are anagrams" << endl;
    else    
        cout << "The two given strings are not anagrams" << endl;
    return 0;
}