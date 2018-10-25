class Solution 
{
public:
    vector<vector<int> > v;
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(),S.end());
        generate(vector<int>(), S, 0);
        return v;
    }

    void generate(vector<int> res, vector<int> &S, int i)
    {
        if(i == S.size())
        {
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i] == res)
                {
                    return;
                }
            }
            v.push_back(res);
            return;
        }
        else
        {
            generate(res, S, i+1);
            res.push_back(S[i]);
            generate(res, S, i+1);
        }
    }
};