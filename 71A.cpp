#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    string inputs[t], outputs[t];
    for (int i = 0; i < t; i++)
    {
        cin >> inputs[i];
    }
    for (int i = 0; i < t; i++)
    {   
        if(inputs[i].length() > 10){
            outputs[i] = "";
            outputs[i] += inputs[i][0];
            int len = inputs[i].length();
            outputs[i] += to_string(len-2);
            outputs[i] += inputs[i][len-1];
            cout << outputs[i] << endl;
        }
        else{
            cout << inputs[i] << endl;
        }
    }
    return 0;
}
