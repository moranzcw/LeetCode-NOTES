#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > result;
    vector<bool> flag;

    void solve(vector<int> temp, int k)
    {
        if(k == 0)
        {
            result.push_back(temp);
        }
        else
        {
            for(int i=temp.empty()?1:temp.back()+1;i<flag.size();i++)
            {
                if(flag[i] == false)
                {
                    flag[i] = true;
                    temp.push_back(i);
                    solve(temp,k-1);
                    temp.erase(temp.end()-1);
                    flag[i] = false;
                }
            }
        }
    }

    vector<vector<int> > combine(int n, int k) 
    {
        flag.resize(n+1,false);
        solve(vector<int>(),k);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
     vector<vector<int> > result = sol.combine(4,4);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";    
        cout<<endl;
    }

    return 0;
}