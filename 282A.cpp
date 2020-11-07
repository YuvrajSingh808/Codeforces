#include <bits/stdc++.h>
using namespace std;

bool isSubstring(string mainString, string subString)
{
    bool flag = false;
    for (int i = 0; i < mainString.length(); i++)
    {
        if (subString[0] == mainString[i])
        {
            for (int j = 1; j < subString.length(); j++)
            {
                if (subString[j] == mainString[i + j])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (isSubstring(str, "++"))
        {
            val++;
        }
        else
        {
            val--;
        }
    }
    cout << val;
    return 0;
}