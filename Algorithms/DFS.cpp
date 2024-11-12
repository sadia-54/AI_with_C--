#include<bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &graph, int start, vector<bool>&visited)
{
    cout<< start << " ";
    int len = graph.size();
    visited[start] = true;

    for(int i=0; i<len; i++)
    {
        if(graph[start][i]!=0 && !visited[i])
        {
            dfs(graph, i, visited);
        }
    }
}

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<int>>graph(nodes, vector<int>(nodes, 0));
    vector<bool> visited(nodes, false);

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cin>>start;

    dfs(graph, start, visited);
    cout<< endl;

    return 0;
}