/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution 
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if( node == NULL ) 
            return NULL;
        unordered_map<UndirectedGraphNode * , UndirectedGraphNode *> otn;
        otn[node] = new UndirectedGraphNode(node -> label);
        queue<UndirectedGraphNode *> que;
        que.push(node);
        
        while(!que.empty())
        {
            UndirectedGraphNode* node = que.front() ; que.pop();
            int size = node -> neighbors.size();
            
            for(int i = 0 ; i < size ; i ++)
            {
                if(otn.find(node -> neighbors[i]) == otn.end())
                {
                    UndirectedGraphNode * tmp = new UndirectedGraphNode(node -> neighbors[i] -> label);
                    otn[node] -> neighbors.push_back(tmp);
                    otn[node -> neighbors[i]] = tmp;
                    que.push(node -> neighbors[i]);
                }
                else
                {
                    otn[node] -> neighbors.push_back(otn[node -> neighbors[i]]);
                }
            }
        }
        return otn[node];
    }
};