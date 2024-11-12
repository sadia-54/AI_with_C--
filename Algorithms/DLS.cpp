#include <bits/stdc++.h>
using namespace std;

bool DLS(vector<vector<int>> &adj, int current, int target, vector<bool> &visited, int depthLimit)
{
    if (current == target)
    {
        cout << "Target " << target << " found!" << endl;
        return true;
    }
    if (depthLimit <= 0)
    {
        return false;
    }

    visited[current] = true;
    cout << current << " "; // Print the current node

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            if (DLS(adj, neighbor, target, visited, depthLimit - 1))
            {
                return true;
            }
        }
    }

    visited[current] = false; // Unmark the node (backtracking)
    return false;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V); // Adjacency list representation

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex1 vertex2):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge u -> v
        adj[v].push_back(u); // Since it's undirected, add edge v -> u
    }

    int start, target, depthLimit;
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "Enter the target vertex: ";
    cin >> target;
    cout << "Enter the depth limit: ";
    cin >> depthLimit;

    vector<bool> visited(V, false); // Track visited nodes

    cout << "DLS traversal starting from vertex " << start << " with depth limit " << depthLimit << ": ";
    if (!DLS(adj, start, target, visited, depthLimit))
    {
        cout << "\nTarget " << target << " not found within depth limit " << depthLimit << endl;
    }

    return 0;
}
