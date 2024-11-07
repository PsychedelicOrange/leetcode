#include<iostream>
#include<list>
#include<vector>
using namespace std;
enum Subject
{
    EOM,
    DBS,
    ES,
    SE,
    CYS,
};
class Graph
{
    public :
    int numV; 
    vector<list<pair<Subject,int>>> graph;
    Graph(int numV = 5)
    {
        this->numV = numV;
        graph.resize(numV);
    }
    void addEdge(Subject i , Subject j, int weight = 1)
    {
        graph[i].push_back(make_pair(j,weight));
    }
};
int main()
{
    Graph* IT = new Graph();
    IT->addEdge(EOM,ES); // EOM Then ES
}