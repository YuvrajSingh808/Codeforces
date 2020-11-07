//
//  Order.cpp
//  Ques1
//
//  Created by Akshit Sharma on 03/05/21.
//

#include "Order.hpp"
using namespace std;

Order::Order(std::string fileName)
{

    cout << "Enter max capacity of cask: ";
    cin >> G;
    cout << "Enter the cost to store a liter of nitrogen for every extra day: ";
    cin >> p;
    cout << "Enter delivery charges: ";
    cin >> S;
    cout << "Enter number of days after which plant is closed: ";
    cin >> numDays;
    daily = new int[numDays];
    cout << "Enter daily requirement of nitrogen gas in litres\n";
    for (int i = 0; i < numDays; i++)
    {
        cout << "requirement for day " << i + 1 << ": ";
        cin >> daily[i];
        if (daily[i] > G)
        {
            cout << "\nDaily order cannot be greater than max capacity. Exitting program";
            exit(1);
        }
    }
}

/*
 
    process() :- processing the orders in accordance with the maximum cost
 
 
 
 */

void Order::process()
{

    // memoization
    observed = new int[numDays];
    for (int i = 0; i < numDays; i++)
    {
        observed[i] = -1;
    }

    observed[0] = 0;

    int total_cost = p * (daily[0]) + S;
    int pre_consecutive_day = 0;
    int pre_capacity = daily[0];

    // checking order of further days
    for (int i = 1; i < numDays; i++)
    {

        if (observed[i - 1] == i - 1)
        { // checking for new consecutive list

            if (daily[i - 1] + daily[i] > G)
            { // verfying if the capacity of current day is valid or not
                observed[i] = i;
                pre_consecutive_day = i;
                pre_capacity = daily[i];
                total_cost += p * (daily[i]) + S;
                continue;
            }

            int costorder = p * (daily[i - 1] + daily[i]) + 2 * S;            // cost of separate ordering
            int costpreorder = p * (daily[i - 1]) + (2) * p * (daily[i]) + S; // cost of ordering with previous day order

            if (costpreorder <= costorder)
            { // if current day gas can be pre-ordered or not
                observed[i] = i - 1;
                pre_consecutive_day = i - 1;
                pre_capacity += daily[i];
                total_cost += (2) * p * (daily[i]);
            }
            else
            {
                observed[i] = i;
                pre_consecutive_day = i;
                pre_capacity = daily[i];
                total_cost += p * (daily[i]) + S;
            }
        }
        else
        {

            if (pre_capacity + daily[i] > G)
            { // verfying if the capacity of current day is valid or not
                observed[i] = i;
                pre_capacity = daily[i];
                total_cost += p * (daily[i]) + S;
                continue;
            }

            int costorder = total_cost + p * (daily[i]) + S;                                // cost of separate ordering
            int costpreorder = total_cost + (i - pre_consecutive_day + 1) * p * (daily[i]); // cost of ordering with previous day order

            if (costpreorder <= costorder)
            { // if current day gas can be pre-ordered or not
                observed[i] = i - 1;
                pre_capacity += daily[i];
                total_cost += (i - pre_consecutive_day + 1) * p * (daily[i]);
            }
            else
            {
                observed[i] = i;
                pre_consecutive_day = i;
                pre_capacity = daily[i];
                total_cost += p * (daily[i]) + S;
            }
        }
    }
}

/*
 
 present() :- displays the liist of orders to be executed in order to get the minimum cost
 
 */

void Order::present()
{

    int iterator = 1;

    std::cout << "Order " << iterator << ": \n";
    std::cout << "Day 1\n";
    for (int i = 1; i < numDays; i++)
    {

        if (observed[i] == observed[i - 1])
        {
            std::cout << "Day " << i + 1 << "\n";
        }
        else
        {
            iterator++;
            std::cout << "Order " << iterator << ": \n";
            std::cout << "Day " << i + 1 << "\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    Order test("C:\\Users\\hp\\Desktop\\Programming\\C++\\Codeforces\\New folderorder.txt");
    test.process();
    test.present();

    std::cout << std::endl;
    system("pause");
    return 0;
}
