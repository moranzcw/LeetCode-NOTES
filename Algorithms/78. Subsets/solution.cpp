class Solution 
{
public:
    vector<vector<int> > result;
    vector<int> Str;
    vector<bool> flag;

    void solve(vector<int> temp, int f, int k)
    {
        if(k == 0)
        {
            result.push_back(temp);
        }
        else
        {
            for(int i=f;i<flag.size();i++)
            {
                if(flag[i] == false)
                {
                    flag[i] = true;
                    temp.push_back(Str[i]);
                    solve(temp,i,k-1);
                    temp.erase(temp.end()-1);
                    flag[i] = false;
                }
            }
        }
    }

    vector<vector<int> > subsets(vector<int> &S) 
    {
        flag.resize(S.size());
        sort(S.begin(),S.end());
        Str = S;
        for(int i=0;i<S.size()+1;i++)
            solve(vector<int>(),0,i);
        return result;
    }
};