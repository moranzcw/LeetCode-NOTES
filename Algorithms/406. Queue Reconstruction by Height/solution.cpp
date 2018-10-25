bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first > p2.first)
        return true;
    if(p1.first == p2.first && p1.second < p2.second)
        return true;
    return false;
}
    
class Solution 
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
    {
        sort(people.begin(),people.end(),cmp);
        vector<pair<int, int>> result;
        for(int i=0;i<people.size();i++)
        {
            if(people[i].second >= result.size())
                result.push_back(people[i]);
            else
                result.insert(result.begin()+people[i].second, people[i]);
        }
        return result;
    }
};