#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

class Graph
{
    int **matrix;
    int vertices;
    vector<int> parent;
    vector<int> children;
    vector<int> weights;

public:
    Graph(int v)
    {
        vertices = v;
        matrix = new int *[v];
        // parent = new int[v];
        // child = new int[v];
        for (int i = 0; i < vertices; i++)
        {
            matrix[i] = new int[v];
            for (int j = 0; j < vertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void printGraph()
    {
        system("\n\n");
        cout << setw(8);
        cout << " ";
        for (int i = 0; i < vertices; i++)
        {
            cout << setw(5) << char(i + 65);
        }
        cout << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << setw(8) << char(i + 65);
            for (int j = 0; j < vertices; j++)
            {
                cout << setw(5) << matrix[i][j];
            }
            cout << endl;
        }
    }

    void addEdge(int weight, int v1, int v2)
    {

        matrix[v1][v2] = matrix[v2][v1] = weight;
    }

    int getWeight(int v1, int v2){
        return matrix[v1][v2];
    }

    //to take mst T input from user
    void addMst()
    {
        cout << "\nAdd each edge in mst:\n";
        for (int i = 1; i < vertices; i++)
        {
            int temp;
            cout << "First vertex of edge " << i << ": ";
            cin >> temp;
            parent.push_back(temp);
            cout << "Second vertex of edge " << i << ": ";
            cin >> temp;
            children.push_back(temp);
        }
        cout << "\nGiven MST is:\n";
        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; i++){
            weights.push_back(matrix[i][parent[i - 1]]);
            cout << parent[i - 1] << " - " << children[i - 1] << " \t" << weights[i-1] << " \n";
        }
    }

    void algo()
    {
        int oldWeight;
        int newWeight;
        cout << "\nEdge e";
        cout << "\nEnter weight of edge e: ";
        cin >> oldWeight;
        int v1 = 0, v2 = 0;
        bool flag = false;
        for (v1 = 0; v1 < vertices; v1++){
            for (v2 = 0; v2 < vertices; v2++){
                if (matrix[v1][v2] == oldWeight){
                    cout << "\nEnter new weight: ";
                    cin >> newWeight;
                    matrix[v1][v2] = matrix[v2][v1] = newWeight;
                    flag = true;
                    break;
                }
            }
            if (flag){
                break;
            }
            
        }
        int x = find(parent.begin(), parent.end(), v1) - parent.begin();
        // check if edge exists already in mst
        if (find(parent.begin(), parent.end(), v1) != parent.end() && parent[x] == v1 && children[x] == v2){
            // mst is same
            cout << "Edge \tWeight\n";
            for (int i = 1; i < vertices; i++)
            {
                cout << parent[i - 1] << " - " << children[i - 1] << " \t" << weights[i-1] << " \n";
            }
        }
        else{
            // Add edge e to given MST T
            parent.push_back(v1);
            children.push_back(v2);
            weights.push_back(matrix[v1][v2]);
            
            // find the largest weight in the mst
            int maxIndex = distance(weights.begin(), max_element(weights.begin(), weights.end()));
            parent.erase(parent.begin() + maxIndex - 1);
            children.erase(children.begin() + maxIndex - 1);
            weights.erase(weights.begin() + maxIndex - 1);

            // Print the new mst T'
            cout << "\nNew MST is:\n";
            cout << "Edge \tWeight\n";
            for (int i = 1; i < vertices; i++)
            {
                cout << parent[i - 1] << " - " << children[i - 1] << " \t" << weights[i-1] << " \n";
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int v;
    cout << "Enter total vertex of graph G: ";
    cin >> v;
    Graph graph(v);
    int choice;
    do
    {
        graph.printGraph();
        cout << "\nChoose:"
            << "\n1. Add vertex"
            << "\n2. Add MST"
            << "\n3. Change weight of edge e and get new MST"
            << "\n4. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int v1, v2, weight;
            cout << "\nAdd first vertex: ";
            cin >> v1;
            cout << "\nAdd second vertex: ";
            cin >> v2;
            cout << "\nAdd weight of edge: ";
            cin >> weight;
            graph.addEdge(weight, v1, v2);
            break;
        case 2:
            graph.addMst();
            break;
        case 3:
            graph.algo();
            break;
        default:
            cout << "\nWrong choice\n";
        }
    } while (choice != 4);
    return 0;
}
