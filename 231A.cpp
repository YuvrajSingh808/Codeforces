#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    int ques = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int arr[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j];
        }
        if(count(arr, arr + 3, 1) > 1){
            ques++;
        }
    }
    cout << ques;
    return 0;
}