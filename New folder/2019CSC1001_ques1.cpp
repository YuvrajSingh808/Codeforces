#include <iostream>
using namespace std;

class Laysfactory
{
	int G, S, n, p, *l, *legal, *min, *c;

public:
	void input()
	{
		cout << "\n Enter the maximum capacity of cask(in litres),delivery price,number of days remaining,storage cost (for each extra day) : ";
		cin >> G >> S >> n >> p;

		l = new int[n];		//daily wala array
		c = new int[n + 1]; //cost wala array
		legal = new int[n];
		min = new int[n];

		for (int i = 0; i < n; i++)
		{
			c[i] = 0;
			legal[i] = -1;
			min[i] = 0;
		}

		cout << "\n Enter gas requirements per day for " << n << " days : \n";
		for (int i = 0; i < n; i++)
		{
			cout << "\n Day " << i + 1 << " : ";
			cin >> l[i];
		}

		compute();
		display();
	}

	void compute()
	{
		c[n] = 0;

		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = j; i >= 0; i--)
			{
				if (i <= j && j <= n && ssum(i, j) <= G)
				{
					if (legal[i] == -1)
					{
						min[i] = costcalc(i, j);
						legal[i] = j;
					}
					else
					{
						int newmin = costcalc(i, j);
						if (newmin < min[i])
						{
							min[i] = newmin;
							legal[i] = j;
						}
					}
				}
				c[i] = p + min[i];
			}
		}
	}

	//series sum in an array
	//can be replaced by sum
	int ssum(int a, int b)
	{
		int sum = 0;
		for (int i = a; i <= b; i++) // included last index
			sum = sum + l[i];
		return sum;
	}

	//calculates the cost of gas in a particular series
	int costcalc(int i, int j)
	{
		int sum = 0;
		for (int k = i; k <= j; k++)
			sum += (k - i) * S * l[k];
		return sum;
	}

	void display()
	{
		

		cout << "\n Minimum Optimal cost : " << c[0];
		cout << "\n\n Days and quantity of gas required \n";
		cout << "\n Day 1 : " << l[0] << "L";
		for (int i = 1; i < n; i++)
		{
			if (legal[i - 1] != legal[i])
			{
				cout << "\n Day " << i + 1 << " : " << ssum(i, legal[i]) << "L";
			}
		}
	}
};

int main()
{
	Laysfactory obj;
	obj.input();
	system("pause");
	return 0;
}
