class Solution 
{
public:
    int numDistinct(string S, string T)
    {
        vector<vector<int> > cnt(T.length()+1,vector<int>(S.length()+1));
        for(int j=0; j<S.length(); j++) 
        {
            cnt[0][j] = 1;
        }
        for(int i=1; i<T.length(); i++) 
        {
            cnt[i][0] = 0;
        }
        
        for(int i=1; i<=T.length(); i++) 
        {
            for(int j=1; j<=S.length(); j++) 
            {
                if(T[i-1] != S[j-1]) 
                {
                    cnt[i][j] = cnt[i][j-1];    // The old way to match
                } 
                else 
                {    // Match, it allows us to have a new way to match
                    cnt[i][j] = cnt[i][j-1] + cnt[i-1][j-1];    // old way + new way
                }
            }
        }
        
        return cnt[T.length()][S.length()];
    }
};