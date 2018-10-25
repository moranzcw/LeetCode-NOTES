class Solution 
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> res(n+1);
        for(int i = 0 ; i< n + 1 ; ++i)
        {
            res[i] = i - 1;
        }
        vector<vector<bool> > p(n, vector<bool>(n, false));
        for(int i = 0; i< n; ++i)
        {
            for(int j = 0; j <= i ; ++j)
            {
                if(s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1]))
                {
                    p[j][i] = true;
                    res[i + 1] = min(res[i + 1], res[j] + 1);
                }
            }
        }
        return res[n];
    }
};