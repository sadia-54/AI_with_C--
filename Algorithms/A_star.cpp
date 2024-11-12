#include <bits/stdc++.h>
using namespace std;

// Function for A* search
void AStar(int start, int goal, vector<vector<pair<int, int>>> &adj, vector<int> &heuristic)
{
    int V = adj.size();              // Number of nodes
    vector<int> minCost(V, INT_MAX); // Minimum cost to reach each node
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;

    minCost[start] = 0;
    pq.push({0 + heuristic[start], {start}}); // f(n) = g(n) + h(n)

    while (!pq.empty())
    {
        auto current = pq.top();
        int fCost = current.first;
        vector<int> path = current.second;
        pq.pop();

        int node = path.back();
        int gCost = fCost - heuristic[node]; // Real cost to reach this node (f - h)

        if (node == goal)
        { // If reached the goal, print path and cost
            cout << "Path found with cost " << gCost << ": ";
            for (int n : path)
                cout << n << " ";
            cout << endl;
            return;
        }

        // Explore neighbors
        for (size_t j = 0; j < adj[node].size(); ++j)
        {
            int neighbor = adj[node][j].first;
            int weight = adj[node][j].second;
            int newGCost = gCost + weight;                 // Updated cost to reach neighbor
            int newFCost = newGCost + heuristic[neighbor]; // f(n) for the neighbor

            if (newGCost < minCost[neighbor])
            { // Only proceed if we found a cheaper path
                minCost[neighbor] = newGCost;
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                pq.push({newFCost, newPath});
            }
        }
    }
    cout << "Goal node " << goal << " is not reachable from start node " << start << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<pair<int, int>>> adj(V); // Graph adjacency list
    vector<int> heuristic(V);              // Heuristic values for each node

    cout << "Enter the heuristic for each node:\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Heuristic for node " << i << ": ";
        cin >> heuristic[i];
    }

    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter each edge (from to cost):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost}); // If the graph is undirected
    }

    int start, goal;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    AStar(start, goal, adj, heuristic);

    return 0;
}
