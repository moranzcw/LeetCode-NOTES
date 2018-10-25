bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second<p2.second)
        return true;
    if(p1.second>p2.second)
        return false;
    return p1.first<p2.first;
}

class Solution 
{
public:
    int findMinArrowShots(vector<pair<int, int>>& points) 
    {
        if(points.size()==0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int shots=1;
        int x = points[0].second;
        for(auto i:points)
        {
            if(x<i.first)
            {
                x = i.second;
                shots++;
            }
        }
        return shots;
    }
};