#include <iostream>
using namespace std;

string replaceSpace(string s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            s.push_back(' ');
            s.push_back(' ');
        }
    }

    int j = size - 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[j] != ' ')
            s[i] = s[j];
        else
        {
            s[i--] = '0';
            s[i--] = '2';
            s[i] = '%';
        }
        j--;
    }
    return s;
}

int main()
{
    string s = "We are happy.";
    cout << replaceSpace(s) << endl;
}