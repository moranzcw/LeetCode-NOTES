class Graph
{
    int V;
    list<int> *adj;
    queue<int> q;
    int* indegree;
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool topological_sort();
};

/************************类定义************************/
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    indegree = new int[V];
    for(int i=0; i<V; ++i)
        indegree[i] = 0;
}

Graph::~Graph()
{
    delete [] adj;
    delete [] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    ++indegree[w];
}

bool Graph::topological_sort()
{
    for(int i=0; i<V; ++i)
        if(indegree[i] == 0)
            q.push(i);
            
    int count = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        ++count;
        list<int>::iterator beg = adj[v].begin();
        for( ; beg!=adj[v].end(); ++beg)
            if(!(--indegree[*beg]))
                q.push(*beg);
    }

    if(count < V)
        return false;
    else
        return true;
}


class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
    {
        Graph g(numCourses);
        for(int i=0; i<prerequisites.size(); ++i)
            g.addEdge(prerequisites[i][1], prerequisites[i][0]);

        return g.topological_sort();
    }
};
