#include <iostream>
#include <string>

using namespace std;

void count_vowels_consonents_in_string (string input)
{
    int vowels=0, consonents=0, words = 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
            vowels ++;
        else if ( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            consonents++;
        else if (isspace(input[i])) 
            words++;         
    }

    cout << "vowels in input string is : " << vowels << endl;
    cout << "consonents in input string is : " << consonents << endl;
    cout << "No. of words in input string is : " << words << endl;
}
int main()
{
    string input_string;
    cout << "Please input your string"<< endl;
    getline(cin, input_string);
    count_vowels_consonents_in_string(input_string);

    return 0;
}