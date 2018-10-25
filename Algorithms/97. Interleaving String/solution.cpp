class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.size() + s2.size() != s3.size()) 
        {
            return false;
        }
            
        bool a[1000][1000];
        a[0][0] = true;
        for (int i = 1; i <= s1.size(); ++i) 
        {
            a[i][0] = a[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for (int i = 1; i <= s2.size(); ++i) 
        {
            a[0][i] = a[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        for (int i = 1; i <= s1.size(); ++i) 
        {
            for (int j = 1; j <= s2.size(); ++j) 
            {
                a[i][j] = (a[i-1][j] && s1[i-1] == s3[i+j-1]) || (a[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return a[s1.size()][s2.size()];
    }
};