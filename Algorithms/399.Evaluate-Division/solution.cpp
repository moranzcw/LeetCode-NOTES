class Solution 
{
public:
    double DFS(unordered_map<string, unordered_map<string, double> > &graph, unordered_map<string, bool> &visited, double res, string dividend, string &divisor)
    {
        if(dividend == divisor)
        {
            return res;
        }
        visited[dividend] = true;
        for(unordered_map<string,double>::iterator ite = graph[dividend].begin();ite!=graph[dividend].end();ite++)
        {
            if(!visited[ite->first])
            {
                double t = DFS(graph,visited,res * ite->second,ite->first,divisor);
                if(t!=-1)
                    return t;
            }
        }
        return -1;
    }
    
    double calc(unordered_map<string, unordered_map<string,double> > &graph, unordered_map<string, bool> visited, pair<string,string> &querie)
    {
        if(graph.find(querie.first) == graph.end() 
        || graph.find(querie.second) == graph.end())
            return -1.0;
        if(querie.first == querie.second)
            return 1.0;
        return DFS(graph,visited,1,querie.first,querie.second);
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        unordered_map<string, unordered_map<string,double> > graph;
        unordered_map<string, bool> visited;
        for(int i=0;i<equations.size();i++)
        {
            graph[equations[i].first][equations[i].second] = values[i];
            graph[equations[i].second][equations[i].first] = 1.0 / values[i];
            visited[equations[i].first] = false;
            visited[equations[i].second] = false;
        }
        vector<double> result;
        for(int i=0;i<queries.size();i++)
        {
            result.push_back(calc(graph,visited,queries[i]));
        }
        return result;
    }
};