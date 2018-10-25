#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int V;             // 顶点个数
    vector<list<int> > adj;    // 邻接表
    queue<int> q;      // 维护一个入度为0的顶点的集合
    vector<int> indegree;     // 记录每个顶点的入度
public:
    Graph(int V);                   // 构造函数
    ~Graph();                       // 析构函数
    void addEdge(int v, int w);     // 添加边
    vector<int> topological_sort();        // 拓扑排序
};

/************************类定义************************/
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);

    indegree.resize(V,0);  // 入度全部初始化为0
    // for(int i=0; i<V; ++i)
    //     indegree[i] = 0;
}

Graph::~Graph()
{
    // delete [] adj;
    // delete [] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    ++indegree[w];
}

vector<int> Graph::topological_sort()
{
    for(int i=0; i<V; ++i)
        if(indegree[i] == 0)
            q.push(i);         // 将所有入度为0的顶点入队

    vector<int> order;             // 计数，记录当前已经输出的顶点数 
    while(!q.empty())
    {
        int v = q.front();      // 从队列中取出一个顶点
        q.pop();

        order.push_back(v);
        // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
        list<int>::iterator beg = adj[v].begin();
        for( ; beg!=adj[v].end(); ++beg)
            if(!(--indegree[*beg]))
                q.push(*beg);   // 若入度为0，则入栈
    }

    if(order.size() < V)
        order.resize(0);       // 没有输出全部顶点，有向图中有回路

    return order;
}


class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) 
    {
        Graph g(numCourses);
        for(int i=0; i<prerequisites.size(); ++i)
            g.addEdge(prerequisites[i].second, prerequisites[i].first);

        return g.topological_sort();
    }
};