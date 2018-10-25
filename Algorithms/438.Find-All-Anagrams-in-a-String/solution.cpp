class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> hash1(256), hash2(256);
        for(auto ch: p) 
            hash1[ch]++;
        int lenp = p.size(), lens = s.size();
        vector<int> ans;
        for(int i = 0; i < lens; i++)
        {
            hash2[s[i]]++;
            if(i >= lenp) 
                hash2[s[i-lenp]]--;
            if(hash1 == hash2) 
                ans.push_back(i-lenp+1);
        }
        return ans;
    }
};