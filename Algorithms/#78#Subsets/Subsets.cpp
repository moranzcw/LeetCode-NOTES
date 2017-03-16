#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

int main(int argc, char const *argv[])
{
    vector<int> S;
    S.push_back(1);
    S.push_back(5);
    S.push_back(3);
    Solution sol;
     vector<vector<int> > result = sol.subsets(S);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";    
        cout<<endl;
    }

    return 0;
}