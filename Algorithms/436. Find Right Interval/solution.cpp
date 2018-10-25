/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(pair<Interval,int> a,pair<Interval,int> b)
{
    return a.first.start <= b.first.start || (a.first.start==b.first.start&&a.first.end<=b.first.end);
}

class Solution 
{
public:
    vector<int> findRightInterval(vector<Interval>& intervals) 
    {
        int n=intervals.size();
        vector<int> ans(n,-1);
        vector<pair<Interval,int>> h;
        for(int i=0;i<n;i++)
            h.push_back(pair<Interval,int>(intervals[i],i));
        sort(h.begin(),h.end(),cmp);
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(h[j].first.start>=h[i].first.end)
                {
                    ans[h[i].second]=h[j].second;
                    break;
                }
            }
        }
        return ans;
    }
};