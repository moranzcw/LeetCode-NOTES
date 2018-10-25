class Solution 
{
public:
    string s;
    vector<vector<bool> > DP;
    vector<vector<string> > result;

    void solve(int index, vector<string> tempResult)
    {
        if(index == s.size())
            result.push_back(tempResult);
        else
        {
            for(int i = index;i<DP[index].size();i++)
            {
                if(DP[index][i])
                {
                    tempResult.push_back(s.substr(index,i-index+1));
                    solve(i+1,tempResult);
                    tempResult.pop_back();
                }
            }
        }
    }

    vector<vector<string> > partition(string s) 
    {
        DP.resize(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<DP.size();i++)
        {
            DP[i][i]=true;
            if( i<DP.size()-1 && s.at(i) == s.at(i+1) )
                DP[i][i+1] = true;
        }
        for(int len=3;len<=s.size();len++)
        {
            for(int i=0;i+len<=s.size();i++)
            {
                int j=i+len-1;
                if( DP[i+1][j-1] && s[i] == s[j] )
                {
                    DP[i][j]=true;
                }
            }
        }

        this->s = s;
        solve(0,vector<string>());

        return result;
    }
};