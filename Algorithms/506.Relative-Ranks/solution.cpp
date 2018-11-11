bool cmp(pair<int,int> i, pair<int,int> j){
    return j.first < i.first;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int> > mapp;
        for(int i=0;i<nums.size();i++){
            mapp.push_back(pair<int,int>(nums[i],i));
        }
        sort(mapp.begin(), mapp.end(), cmp);
        
        vector<string> str(nums.size());
        for(int i=0;i<mapp.size();i++){
            str[mapp[i].second] = to_string(i + 1);
        }
        if(mapp.size() > 0)
            str[mapp[0].second] = "Gold Medal";
        if(mapp.size() > 1)
            str[mapp[1].second] = "Silver Medal";
        if(mapp.size() > 2)
            str[mapp[2].second] = "Bronze Medal";
        return str;
    }
};
