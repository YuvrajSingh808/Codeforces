#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 6


int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V]){
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[V][V]){
	
	int parent[V];
	
	int key[V];
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph);
}

// Driver code
int main(){
	int graph[V][V] = { { 0, 7, 8, 0, 0, 0 },
						{ 7, 0, 3, 6, 0, 0 },
						{ 8, 3, 0, 4, 3, 0 },
						{ 0, 6, 4, 0, 2, 5 },
						{ 0, 0, 3, 2, 0, 2 },
						{ 0, 0, 0, 5, 2, 0 }, };

	// Print the solution
	primMST(graph);
	system("pause");
	return 0;
}

