bool cmp(pair<int ,int> p1 , pair<int, int> p2)
{
    return p1.first > p2.first;
}
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> count;
        for(auto i:nums)
            count[i]++;
            
        vector<pair<int, int> > table;
        for(auto i:count)
            table.push_back(pair<int, int>(i.second, i.first));
        sort(table.begin(), table.end(), cmp);
        
        vector<int> result;
        for(int i=0;i<k;i++)
            result.push_back(table[i].second);
        return result;
    }
};