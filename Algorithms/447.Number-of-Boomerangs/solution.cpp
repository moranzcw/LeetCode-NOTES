class Solution 
{
public:
    int combination(int n)
    {
        return n*(n-1);
    }
    
    int distance(pair<int,int> &point1, pair<int,int> &point2)
    {
        int a = abs(point1.first - point2.first);
        int b = abs(point1.second - point2.second); 
        return a*a + b*b;
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) 
    {
        int result = 0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<int,int> table;
            unordered_map<int,int>::iterator ite;
            for(int j=0;j<points.size();j++)
            {
                int d = distance(points[i],points[j]);
                // cout<<"a:"<<points[i].first<<","<<points[i].second<<" b:"<<points[j].first<<","<<points[j].second<<" d:"<<d<<endl;
                // ite = table.find(d); 
                // if(ite == table.end())
                //     table.insert(pair<int,int>(d,1));
                // else
                //     ite->second += 1;
                table[d]++;
            }
            for(ite=table.begin();ite!=table.end();ite++)
            {
                // cout<<"d:"<<ite->first<<" n:"<<ite->second<<endl;
                result += combination(ite->second);
                // cout<<"result = "<<result<<endl;
            }
                // cout<<endl;
        }
        return result;
    }
};