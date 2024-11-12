#include <bits/stdc++.h>
using namespace std;

// Function for Uniform Cost Search (UCS)
void UCS(int start, int target, vector<vector<pair<int, int>>> &adj)
{
    int V = adj.size(); // Number of vertices

    // Priority queue to select the path with minimum cost
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;

    // Initial path starts with the start node and cost 0
    pq.push({0, {start}});
    vector<int> minCost(V, INT_MAX);
    minCost[start] = 0;

    while (!pq.empty())
    {
        pair<int, vector<int>> top = pq.top();
        int cost = top.first;
        vector<int> path = top.second;
        pq.pop();

        int node = path.back();

        // If we reached the target node, print the path and cost
        if (node == target)
        {
            cout << "Path found with cost " << cost << ": ";
            for (int n : path)
            {
                cout << n << " ";
            }
            cout << endl;
            return;
        }

        // Explore neighbors
        for (size_t j = 0; j < adj[node].size(); ++j)
        {
            int neighbor = adj[node][j].first;
            int weight = adj[node][j].second;
            int newCost = cost + weight;

            // If we find a cheaper path to neighbor, update and push to queue
            if (newCost < minCost[neighbor])
            {
                minCost[neighbor] = newCost;
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                pq.push({newCost, newPath});
            }
        }
    }
    cout << "Target " << target << " is not reachable from " << start << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Graph as adjacency list of pairs (neighbor, edge cost)
    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter each edge (from to cost):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost}); // For undirected graph
    }

    int start, target;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the target node: ";
    cin >> target;

    UCS(start, target, adj);

    return 0;
}
