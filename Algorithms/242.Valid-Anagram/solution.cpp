class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(256,0);
        for(int i=0;i<s.size();i++)
            count[s[i]] += 1;
        for(int i=0;i<t.size();i++)
            count[t[i]] -= 1;
        for(int i=0;i<count.size();i++)
            if(count[i] != 0) 
                return false;
        return true;
    }
};