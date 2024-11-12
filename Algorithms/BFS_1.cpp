#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&graph, int start)
{
    int len = graph.size();
    vector<bool>visited(len, false);
    queue<int>q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        cout<< node << " ";
        q.pop();

        for(int i=0; i<len; i++)
        {
            if(graph[node][i]!=0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }

    }

    cout<< endl;
}

int main()
{

    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<int>>graph(nodes, vector<int>(nodes, 0));

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cin>>start;
    bfs(graph, start);

}