#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

class Ques1
{
    vector<int> dailyRequirements;
    vector<int> orders;
    int g, p, s, totalDays;
    int minimumOptimalCost;
    int getCostFromQuantity(int x, int y)
    {
        int sum = 0;
        for (int i = x; i <= y; i++)
        {
            sum += s * dailyRequirements[i] * (i - x);
        }
        return sum;
    }

public:
    Ques1()
    {
        cout << "Enter max capacity of cask: ";
        cin >> g;
        cout << "Enter the cost to store a liter of nitrogen for every extra day: ";
        cin >> p;
        cout << "Enter delivery charges: ";
        cin >> s;
        cout << "Enter number of days after which plant is closed: ";
        cin >> totalDays;
        cout << "Enter daily requirement of nitrogen gas in litres\n";
        for (int i = 0; i < totalDays; i++)
        {
            int temp;
            cout << "requirement for day " << i + 1 << ": ";
            cin >> temp;
            dailyRequirements.push_back(temp);
            if (dailyRequirements[i] > g)
            {
                cout << "\nDaily order cannot be greater than max capacity. Exitting program\n";
                system("pause");
                exit(1);
            }
        }
    }

    void algo()
    {
        minimumOptimalCost = 0;
        vector<int> tempArray(totalDays, 0);
        for (int i = 0; i < totalDays; i++)
        {
            orders.push_back(-1);
            // tempArray
        }

        for (int i = totalDays - 1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                
                if (accumulate(dailyRequirements.begin() + j, dailyRequirements.begin() + i + 1, 0) && j <= i && i <= totalDays)
                {
                    if (orders[j] == -1 || getCostFromQuantity(j, i) < tempArray[j])
                    {
                        orders[j] = i;
                        tempArray.push_back(getCostFromQuantity(j, i));
                    }
                }

                minimumOptimalCost = p + tempArray[j];
            }
        }
    }

    void output()
    {
        cout << "\nMinimum optimal cost = " << minimumOptimalCost;
        cout << "\nDays on which to place order, and order value";
        cout << "\nDay\tOrder";
        cout << "\nDay 1\t" << dailyRequirements[0] << " lit";
        for (int i = 1; i < totalDays; i++)
        {
            // cout << endl << orders[i - 1] << "  " << orders[i];
            
            if (orders[i - 1] == orders[i])
            {
                // cout << endl << orders[i] << endl;
                cout << "\nDay " << i + 1 << '\t' << accumulate(dailyRequirements.begin() + i, dailyRequirements.begin() + orders[i], 0) << " lit";
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Ques1 q;
    q.algo();
    q.output();
    cout << endl;
    system("pause");
    return 0;
}
