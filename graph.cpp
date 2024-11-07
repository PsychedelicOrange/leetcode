#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    public :
    int numV; 
    vector<bool> visdfs;
    vector<list<int>> graph;
    Graph(int numV)
    {
        this->numV = numV;
        graph.resize(numV);
        visdfs.resize(numV);
    }
    void addEdge(int i , int j)
    {
        graph[i].push_back(j);
    }
    void BFS(int start)
    {
        queue<int> q; 
        vector<bool> visited(numV);
        visited[start] = 1;
        q.push(start);
        while(!q.empty())
        {
            int temp = q.front();q.pop();
            cout << temp << " ";
            for(int node : graph[temp] )
            {
                if(!visited [node])
                {
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }
    }
    void dfs(int start)
    {
        visdfs[start] = true;
        cout << start << " ";
        for(int i : graph[start])
        {
            if(!visdfs[i])
                dfs(i);
        }
    }
};
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
        cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.dfs(2);
 
    return 0;
}