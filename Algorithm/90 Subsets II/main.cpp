#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

int main(int argc, char const *argv[])
{
    vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(2);
    Solution sol;
     vector<vector<int> > result = sol.subsetsWithDup(S);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";    
        cout<<endl;
    }
    return 0;
}