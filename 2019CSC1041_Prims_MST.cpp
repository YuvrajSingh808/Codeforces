#include <bits/stdc++.h>
using namespace std;
#define max 500
class prims
{
public:
	int graph[max][max]; //for storing weight
	string vertex[max];	 //for storting names
	int size;			 //for storing size

	prims()
	{
		size = 0; //setting default value
	}

	void add_ver(string name)
	{
		if (finder(name) != -1) //check if already exist
		{
			cout << "\nVertex already entered!\n";
			return;
		}
		vertex[size] = name; //entering data
		size++;
		cout << "\nVertex added!\n";
	}

	void del_ver(string name)
	{
		if (finder(name) == -1) //check if doesn't exist
		{
			cout << "\nVertex doesnt exist!\n";
			return;
		}
		int temp = finder(name); //updating the name array after deletion
		for (int i = temp; i < size - 1; i++)
		{
			swap(vertex[i], vertex[i + 1]);
		}
		vertex[size - 1] = "";
		size--;
		for (int i = 0; i < size; i++) //updating the path array after deletion
		{
			for (int j = temp; j < size; j++)
			{
				int t = graph[i][j];
				graph[i][j] = graph[i][j + 1];
				graph[i][j + 1] = t;
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = temp; j < size; j++)
			{
				int t = graph[j][i];
				graph[j][i] = graph[j + 1][i];
				graph[j + 1][i] = t;
			}
		}
	}

	void connect_ver(string name, string name2, int val)
	{
		int i = finder(name);
		int j = finder(name2);
		if (i == -1 | j == -1)
		{
			cout << "\nEither or both of the vertex doesn't exist\n";
			return;
		}
		graph[i][j] = graph[j][i] = val; //connecting vertex
	}

	void disconnect_ver(string name, string name2)
	{
		int i = finder(name);
		int j = finder(name2);
		if (i == -1 | j == -1)
		{
			cout << "\nEither or both of the vertex doesn't exist\n";
			return;
		}
		graph[i][j] = graph[j][i] = 0; //disconnecting vertex
	}

	void algo()
	{
		int mst[size];
		int key[size];
		bool visited[size];
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			key[i] = INT_MAX;
			visited[i] = false;
		}

		key[0] = 0;
		mst[0] = -1;

		for (int count = 0; count < size - 1; count++)
		{
			int min = INT_MAX, index;
			for (int i = 0; i < size; i++)
			{
				if (visited[i] == false && key[i] < min)
					min = key[i], index = i;
			}
			visited[index] = true;
			for (int i = 0; i < size; i++)
			{
				if (graph[index][i] && visited[i] == false && graph[index][i] < key[i])
					mst[i] = index, key[i] = graph[index][i];
			}
		}

		for (int i = 1; i < size; i++)
		{
			cout << vertex[mst[i]] << vertex[i] << " - " << graph[i][mst[i]] << " \n";
			sum += graph[i][mst[i]];
		}
		cout << "\nTotal Cost = " << sum << endl;
	}

	int finder(string name) //funtion to find a vertex in the array
	{
		for (int i = 0; i < size; i++)
		{
			if (name == vertex[i])
				return i;
		}
		return -1;
	}

	void print() //to print the whole graph
	{
		cout << "* ";
		for (int i = 0; i < size; i++)
		{
			cout << vertex[i] << " ";
		}
		cout << endl;
		for (int a = 0; a < size; a++)
		{
			cout << vertex[a] << " ";
			for (int b = 0; b < size; b++)
			{
				cout << graph[a][b] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	int run = 1, choice = 0, val = 0;
	string data, data2;
	prims object;
	cout << endl
		 << "-----------------------Prims MST-----------------------" << endl;
	while (run != 0)
	{
		cout << "\n1.Enter Node\n2.Delete Node\n3.Connect Nodes \n4.Disconect Nodes \n5.Find MST\n6.Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter node : ";
			cin >> data;
			object.add_ver(data);
			object.print();
			break;
		case 2:
			cout << "Enter node : ";
			cin >> data;
			object.del_ver(data);
			object.print();
			break;
		case 3:
			cout << "Enter first node : ";
			cin >> data;
			cout << "\nEnter second node : ";
			cin >> data2;
			cout << "\nEnter distance : ";
			cin >> val;
			object.connect_ver(data, data2, val);
			object.print();
			break;
		case 4:
			cout << "Enter first node : ";
			cin >> data;
			cout << "\nEnter second node : ";
			cin >> data2;
			object.disconnect_ver(data, data2);
			object.print();
			break;
		case 5:
			object.algo();
			break;
		case 6:
			run = 0;
			break;
		default:
			cout << "\nEnter Valid Choice\n";
		}
	}
	return 0;
}
