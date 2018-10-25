class Solution 
{
public:
   bool wordBreak(string s, unordered_set<string> &dict) 
   {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) 
        {
            if (dp[i]) 
            {
                for (int len = 1; i + len - 1 < n; len++) 
                {
                    if (dict.count(s.substr(i, len)) > 0)
                        dp[i + len] = true;
                }
            }
        }
        return dp[n];
    }
};