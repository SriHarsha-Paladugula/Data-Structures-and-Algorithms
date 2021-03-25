#include <iostream>
#include <string>

using namespace std;

void perm(string input, int l, int h)
{
    if (l == h)
        cout << input << endl;
    else
        for(int i=l; i<=h; i++)
        {
            swap(input[l], input[i]);
            perm(input, l+1, h);
            swap(input[l], input[i]);
        }
}

int main()
{
    string input;
    cout <<"please give the input string to print out the permutations" << endl;
    getline(cin, input);
    perm(input, 0, input.size()-1);
    return 0;
}