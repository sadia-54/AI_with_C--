#include<bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>> &graph, int start)
{
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < nodes; i++)
        {
            if (graph[node][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes, vector<int>(nodes, 0));

    cout << "Enter each edge (node1 node2):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // for undirected graph
    }

    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;
    cout << "BFS starting from node " << start << ": ";
    bfs(graph, start);

    return 0;
}
