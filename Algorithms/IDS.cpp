#include <bits/stdc++.h>
using namespace std;

// Depth-Limited Search (DLS) for IDS
bool DLS(vector<vector<int>> &adj, int current, int target, vector<bool> &visited, int depthLimit, vector<int> &path)
{
    visited[current] = true;
    path.push_back(current);

    if (current == target)
    {
        return true; // Target found
    }

    if (depthLimit <= 0)
    {
        path.pop_back();
        visited[current] = false;
        return false;
    }

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            if (DLS(adj, neighbor, target, visited, depthLimit - 1, path))
            {
                return true;
            }
        }
    }

    path.pop_back();
    visited[current] = false;
    return false;
}

// Iterative Deepening Search (IDS) function
bool IDS(vector<vector<int>> &adj, int start, int target, int maxDepth)
{
    for (int depth = 0; depth <= maxDepth; depth++)
    {
        vector<bool> visited(adj.size(), false);
        vector<int> path;

        cout << "Trying depth limit " << depth << ":\n";

        if (DLS(adj, start, target, visited, depth, path))
        {
            cout << "Target " << target << " found!\n";
            cout << "Path: ";
            for (int node : path)
            {
                cout << node << " ";
            }
            cout << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V); // Adjacency list

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

    int start, target, maxDepth;
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "Enter the target vertex: ";
    cin >> target;
    cout << "Enter the maximum depth limit: ";
    cin >> maxDepth;

    if (!IDS(adj, start, target, maxDepth))
    {
        cout << "Target " << target << " not found within depth limit " << maxDepth << endl;
    }

    return 0;
}
