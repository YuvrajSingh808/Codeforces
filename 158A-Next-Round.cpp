#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int *notQual = find(arr, arr + n, k);
    if(notQual == arr+n){
        cout << 0;
    }
    else
        cout << notQual[0] + 1;
    return 0;
}
